/*
 * Title: main_hw7_1.cpp
 * Abstract: This program will display the biggest number in an array with n integer numbers using a divide-and-conquer technique.
 * ID: 0730
 * Name: Gabrielle Lake
 * Date: 03/21/2022
 */

#include <iostream>
#include <vector>
using namespace std;

int largestNumber(vector <int> nums, int start, int end);

int main(){

	int n;
	cin >> n;
	vector<int> nums;

	for(int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}

	int largestNum = largestNumber(nums, 0, nums.size() - 1);

	cout << largestNum << endl;

	return 0;
}


int largestNumber(vector <int> nums, int start, int end){
	if(start == end){
		return nums[start];
	} else {
		int firstNum = largestNumber(nums, start, (start + end)/2);
		int secondNum = largestNumber(nums, (start + end)/2 + 1, end);
		if(firstNum > secondNum){
			return firstNum;
		} else {
			return secondNum;
		}
	}
}
