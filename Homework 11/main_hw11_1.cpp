/*
 * Title: main_hw11_1.cpp
 * Abstract: This program will conduct radix sort
 * ID: 0730
 * Name: Gabrielle Lake
 * Date: 04/30/2022
 */

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

vector<int> userNums;
int sortingOccurrence = 0;

void radixSort(int sortingPlace);

int main() {
    int numInputs;
    cin >> numInputs;

    int greatestNum = 0;
    for(int i = 0; i < numInputs; i++) {
        int currNum;
        cin >> currNum;
        userNums.push_back(currNum);

        if(currNum > greatestNum) {
            greatestNum = currNum;
        }
    }

    string largestNum = to_string(greatestNum);
    sortingOccurrence = largestNum.length();

    for(int i = 1; i <= sortingOccurrence; i++) {
        radixSort(pow(10, i));
        for(int k = 0; k < userNums.size(); k++) {
            if(k == userNums.size() - 1) {
                cout << userNums[k] << endl;
            } else {
                cout << userNums[k] << " ";
            }
        }
    }

    return 0;
}

void radixSort(int sortingPlace) {
    vector<vector<int>> sorter(10);
    for(int & num : userNums) {
        int currLSD = (num % sortingPlace) / (sortingPlace / 10);
        sorter[currLSD].push_back(num);
    }

    vector<int> sortedNums;
    for(auto & i : sorter) {
        for(int & k : i) {
            sortedNums.push_back(k);
        }
    }

    userNums = sortedNums;
}
