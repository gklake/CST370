/*
 * Title: main_hw6_1.cpp
 * Abstract: This program will read the number of input values from a user, read the input values from the user, and display the values in ascending order and using short(folded) representation.
 * ID: 0730
 * Name: Gabrielle Lake
 * Date: 03/09/2022
 */

#include <iostream>
#include <vector>
#include <algorithm>

void displayShorthand(const std::vector<int> &allNums, int k, bool &FLAG, int &i);

int displayNormal(const std::vector<int> &allNums, int i);

using namespace std;
int main(){
    vector<int> allNums;
    int numOfNums;
    cin >> numOfNums;

    for(int i = 0; i < numOfNums; i++){
        int temp;
        cin >> temp;
        allNums.push_back(temp);
    }

    sort(allNums.begin(), allNums.end());

    bool FLAG = false;
    for(int i = 0; i < allNums.size();){
        int k = i;
        for(; k < allNums.size() - 1; k++){
            if(allNums[k] == allNums[k + 1] || allNums[k] + 1 == allNums[k + 1]){
                FLAG = true;
            } else {
                break;
            }
        }

        if(FLAG){
            displayShorthand(allNums, k, FLAG, i);

        } else {
            i = displayNormal(allNums, i);
        }
    }
    cout << endl;
}

int displayNormal(const vector<int> &allNums, int i) {
    if(i == allNums.size() - 1){
        cout << allNums[i];
    } else {
        cout << allNums[i] << " ";
    }
    i++;
    return i;
}

void displayShorthand(const vector<int> &allNums, int k, bool &FLAG, int &i) {
    if(k == allNums.size() - 1){
        cout << allNums[i] << "-" << allNums[k];
    } else {
        cout << allNums[i] << "-" << allNums[k] << " ";
    }

    FLAG = false;
    k++;
    i = k;
}
