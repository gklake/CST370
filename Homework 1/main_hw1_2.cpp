/*
 * INSTRUCTION:
 *     This is a C++ staring code for hw1_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw1_2.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw1_2.cpp
 * Abstract: This program will read in two groups of numbers(each group having unique numbers) and print out the non-common numbers in both groups in descending order.
 * ID: 0730
 * Name: Gabrielle Lake
 * Date: 1/31/2022
 */

#include <iostream>
#include <vector>
using namespace std;

void insertionSort(int * values, int size){
	for(int i = 1; i < size; i++){
      for(int k = i; k > 0; k--){
          if(values[k] < values[k-1]){
            int temp = values[k];
            values[k] = values[k - 1];
            values[k - 1] = temp;
          } else {
            break;
          }
      }
    }
}

int main(){
	int numOfNums1;
	cin >> numOfNums1;

	int firstNums[numOfNums1];
	for(int i = 0; i < numOfNums1; i++){
		cin >> firstNums[i];
	}

	int numOfNums2;
	cin >> numOfNums2;
	int secondNums[numOfNums2];
	for(int i = 0; i < numOfNums2; i++){
		cin >> secondNums[i];
	}

	int allNums[numOfNums1 + numOfNums2];
	for(int i = 0; i < numOfNums1; i++){
		allNums[i] = firstNums[i];
	}
	
	for(int i = 0; i < numOfNums2; i++){
		allNums[i + (numOfNums1)] = secondNums[i];
	}

	insertionSort(allNums, numOfNums1 + numOfNums2);

	vector<int> uniqueNums;

	cout << "Answer:";
	for(int i = numOfNums1 + numOfNums2 - 1; i >= 0; i--){
		if(i >= 0){
			if(allNums[i] != allNums[i - 1]){
				uniqueNums.push_back(allNums[i]);
			} else {
				i--;
			}
		}
	}

	if(uniqueNums.size() == 0){
		cout << "NONE" << endl;
	} else {
		for(int i = 0; i < uniqueNums.size(); i++){
			if(i < uniqueNums.size() - 1){
				cout << uniqueNums[i] << " ";
			} else {
				cout << uniqueNums[i] << endl;
			}
		}
	}

}

