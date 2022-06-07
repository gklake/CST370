/*
 * Title: main_hw8_2.cpp
 * Abstract: This program will collect the maximum number of apples in boxes, and will determine the maximum number of apples you can collect from the boxes.
 * ID: 0730
 * Name: Gabrielle Lake
 * Date: 04/11/2022
 */

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

vector<int> binaryConversion(int decimalNum, int numOfBits);
bool validPerm(int vectorSize);
int appleTotal(int vectorSize);

vector<int> numOfApples;
vector<int> currentPerm;
vector<int> highestPerm;
int numOfBasketsInHighestPerm = 0;
int highestTotalApples = 0;

int main(){
  
	int numBaskets;
	cin >> numBaskets;

	for(int i = 0; i < numBaskets; i++){
		int temp;
		cin >> temp;
		numOfApples.push_back(temp);
	}

	for(int i = 0; i < pow(2, numBaskets); i++){
		currentPerm = binaryConversion(i, numBaskets);
		if(validPerm(numBaskets)){
			int currentTotalApplies = appleTotal(numBaskets);
			if(currentTotalApplies > highestTotalApples){
				highestTotalApples = currentTotalApplies;
				highestPerm = currentPerm;
				int tempNumOfBaskets = 0;
				for(int k = 0; k < numBaskets; k++){
					if(highestPerm[k] == 1){
						tempNumOfBaskets++;
					}
					numOfBasketsInHighestPerm = tempNumOfBaskets;
				}
			}
		}
	}

	cout << "Boxes:";
	for(int i = 0; i < numBaskets; i++){
		if(highestPerm[i] == 1){
			if(numOfBasketsInHighestPerm != 1){
				cout << i << " ";
				numOfBasketsInHighestPerm--;
			} else {
				cout << i;
			}
		}
	}
	cout << endl << "Max Apples:" << highestTotalApples << endl;
	return 0;
}


vector<int> binaryConversion(int decimalNum, int numOfBits){
	vector<int> binaryVector;
	while(decimalNum > 0){
		binaryVector.push_back(decimalNum % 2);
		decimalNum /= 2;
	}
	while(binaryVector.size() != numOfBits){
		binaryVector.push_back(0);
	}
	reverse(binaryVector.begin(), binaryVector.end());
	return binaryVector;
}

bool validPerm(int vectorSize){
	for(int i = 0; i < vectorSize - 1; i++){
		if(currentPerm[i] == 1 && currentPerm[i + 1] == 1){
			return false;
		}
	}
	return true;
}

int appleTotal(int vectorSize){
	int total = 0;
	for(int i = 0; i < vectorSize; i++){
		if(currentPerm[i] == 1){
			total += numOfApples[i];
		}
	}
	return total;
}
