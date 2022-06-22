/*
 * Title: main_hw8_1.cpp
 * Abstract: This program will read a number of input values and the values 
themselves and then, put all negative numbers in front of all positive numbers using 2 different methods.
 * ID: 0730
 * Name: Gabrielle Lake
 * Date: 04/11/2022
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> methodOne(vector<int> userValues, int numValues);
vector<int> methodTwo(vector<int> userValues, int numValues);

int main(){
	int numValues;
	cin >> numValues;

	vector<int> userValues;
	for(int i = 0; i < numValues; i++){
		int tempValue;
		cin >> tempValue;
		userValues.push_back(tempValue);
	}

	vector<int> methodOneResult = methodOne(userValues, numValues);
	vector<int> methodTwoResult = methodTwo(userValues, numValues);

	for(int i = 0; i < numValues; i++){
		if(i == numValues - 1){
			cout << methodOneResult[i] << endl;
		} else {
			cout << methodOneResult[i] << " ";
		}
	}
	for(int i = 0; i < numValues; i++){
		if(i == numValues - 1){
			cout << methodTwoResult[i] << endl;
		} else {
			cout << methodTwoResult[i] << " ";
		}
	}
	return 0;
}

vector<int> methodOne(vector<int> userValues, int numValues){
	int start = 0, end = numValues - 1;
	while(start < end){
		if(userValues[start] > 0 && userValues[end] < 0){
			int tempValue = userValues[start];
			userValues[start] = userValues[end];
			userValues[end] = tempValue;
			start++;
			end--;
		}
		if(userValues[start] < 0){
			start++;
		}
		if(userValues[end] > 0){
			end--;
		}
	}
	return userValues;
}
vector<int> methodTwo(vector<int> userValues, int numValues){
	for(int positivePos = 0; positivePos < numValues; positivePos++){
		if(userValues[positivePos] > 0){
			int negativePos = positivePos + 1;
			while(negativePos < numValues){
				if(userValues[negativePos] < 0){
					break;
				} else {
					negativePos++;
				}
			}

			if(userValues[positivePos] > 0 && userValues[negativePos] < 0){
				int tempValue = userValues[positivePos];
			userValues[positivePos] = userValues[negativePos];
			userValues[negativePos] = tempValue;
			}
		}
	}
	return userValues;
}
