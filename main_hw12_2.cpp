/*
 * Title: main_hw12_2.cpp
 * Abstract: This program will implement the Floyd algorithm to display all-pairs shortest paths.
 * ID: 0730
 * Name: Gabrielle Lake
 * Date: 05/10/2022
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	
	int numV;
	cin >> numV;

	int matrix[numV][numV];
	
	for(int i = 0; i < numV; i++){
		for(int k = 0; k < numV; k++){
			int tempDistance;
			cin >> tempDistance;
			if(tempDistance == -1){
				tempDistance = 100000;
			}
			matrix[i][k] = tempDistance;
		}
	}

	//Floyd's Algorithm
	for(int k = 0; k < numV; k++){
		for(int i = 0; i < numV; i++){
			if(i == k){
				continue;
			}
			for(int j = 0; j < numV; j++){
				if(j == k){
					continue;
				}
				matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
			}
		}
	}

	//Placing the -1's back in the matrix
	for(int i = 0; i < numV; i++) {
		for(int j = 0; j < numV; j++) {
			if(matrix[i][j] == 100000) {
				matrix[i][j] = -1;
			} 
		}
	}

	for(int i = 0; i < numV; i++) {
		for(int j = 0; j < numV; j++) {
			if(j == numV - 1){
				cout << matrix[i][j];
			} else {
				cout << matrix[i][j] << " ";
			}
		}
		cout << endl;
	}
	
	return 0;
}
