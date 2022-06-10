/*
 * Title: main_hw5_1.cpp
 * Abstract: This program will read a positive integer number from a user and display the reverse of the number using recursion.
 * ID: 0730
 * Name: Gabrielle Lake
 * Date: 02/27/2022
 */

#include <iostream>
using namespace std;

int reverseDigits(int num);

int main() {
    int userNumber = 0;
    cin >> userNumber;
    cout << reverseDigits(userNumber) << endl;
    return 0;
}

int reverseDigits(int num) {
    static int reversedNum = 0;
    static int position = 1;
    if(num > 0){
        reverseDigits(num / 10);
        reversedNum += (num % 10) * position;
        position *= 10;
    }
    return reversedNum;
}

