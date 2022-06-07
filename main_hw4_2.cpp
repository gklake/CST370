/*
 * Title: main_hw4_2.cpp
 * Abstract: This program will partition n positive integers into two disjoint sets with the same sum.
 * ID: 0730
 * Name: Gabrielle Lake
 * Date: 02/21/2022
 */

#include <iostream>
#include <string>
#include <climits>
#include <vector>
#include <cmath>

void checkAns(bool ans, std::vector<int> &allNums, std::string &binDig);

void findingSums(int n, const std::vector<int> &allNums, int firstSum, int secondSum, bool &ans, std::string &binDig);

using namespace std;

int main()
{
    int n, num;
    bool ans = false;
    vector<int> allNums;

    cin >> n;

    int temp = n;
    int digits = 1;
    string binDig = "0";
    while(temp > 1){
        digits++;
        temp /= 2;
    }

    for(int i = n; i > 1; i--){
        binDig += '0';
    }

    for(int i = 0; i < n; i++){
        cin >> num;
        allNums.push_back(num);
    }

    int firstSum = 0, secondSum = 0;

    findingSums(n, allNums, firstSum, secondSum, ans, binDig);

    checkAns(ans, allNums, binDig);

    return 0;
}

void findingSums(int n, const vector<int> &allNums, int firstSum, int secondSum, bool &ans, string &binDig) {
    for(int i = 0; i < pow(n, 2); i++){
        for(int k = 0; k < binDig.size(); k++){
            if(binDig[k] == '0'){
                firstSum += allNums[k];
            } else {
                secondSum += allNums[k];
            }
        }
        if(firstSum == secondSum){
            ans = true;
            break;
        }

        firstSum = 0;
        secondSum = 0;

        int numDig = 0, temp2 = n - 1;

        for(char k : binDig){
            numDig += (int(k) - 48) * (pow(2, temp2));
            temp2--;
        }
        numDig++;

        vector<int> conversion;
        while(numDig > 0){
            conversion.push_back(numDig % 2);
            numDig /= 2;
        }

        binDig = "";
        for(int k = conversion.size() - 1; k >= 0; k--){
            binDig += to_string(conversion[k]);
        }
        conversion.clear();

        while(binDig.size() < n){
            binDig.insert(0,"0");
        }
    }
}

void checkAns(bool ans, vector<int> &allNums, string &binDig) {
    if(!ans){
        cout << "Equal Set: 0" << endl;
    } else {
        char character = 'z';
        int min = INT_MAX, index;
        string result = "Equal Set: ";
        for (int i = 0; i < binDig.size(); i++) {
            if (allNums[i] < min) {
                min = allNums[i];
                character = binDig[i];
            }
        }
        int totalIterations = 0;
        for (char i: binDig) {
            if (i == character) {
                totalIterations++;
            }
        }
        for (int i = 0; i < totalIterations; i++) {
            min = INT_MAX;
            for (int k = 0; k < allNums.size(); k++) {
                if (binDig[k] == character) {
                    if (allNums[k] < min) {
                        min = allNums[k];
                        index = k;
                    }
                }
            }
            allNums[index] = INT_MAX;
            if (i < totalIterations - 1) {
                result += to_string(min) + " ";
            } else {
                result += to_string(min);
            }
        }
        cout << result << endl;
    }
}