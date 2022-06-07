/*
 * Title: main_hw10_2.cpp
 * Abstract: This program will display the alphabetical order of characters for an alien language.
 * ID: 0730
 * Name: Gabrielle Lake
 * Date: 04/19/2022
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isInAlienAlphabet(char letter);

void displayAlienAlphabetOrder();

void generateAlienAlphabet();

vector<string> alienAlphabetInput;
vector<char> alienAlphabetOrder;
int longestString = 0;

int main()
{
    int sizeOfAlienAlphabet;
    cin >> sizeOfAlienAlphabet;

    for(int i = 0; i < sizeOfAlienAlphabet; i++){
        string currentLine;
        cin >> currentLine;
        if(currentLine.length() > longestString){
            longestString = currentLine.length();
        }
        alienAlphabetInput.push_back(currentLine);
    }

    generateAlienAlphabet();

    displayAlienAlphabetOrder();

    return 0;
}

void generateAlienAlphabet() {
    for(int i = 0; i < longestString; i++){
        for(auto & k : alienAlphabetInput){
            if(i < k.length()){
                char currentLetter = k.at(i);

                if(!(isInAlienAlphabet(currentLetter))){
                    alienAlphabetOrder.push_back(currentLetter);
                }
            }
        }
    }
}

void displayAlienAlphabetOrder() {
    for(int i = 0; i < alienAlphabetOrder.size(); i++){
        if(i == alienAlphabetOrder.size() - 1) {
            cout << alienAlphabetOrder[i] << endl;
        } else {
            cout << alienAlphabetOrder[i] << "->";
        }
    }
}

bool isInAlienAlphabet(char letter){
    for(char i : alienAlphabetOrder){
        if(letter == i){
            return true;
        }
    }
    return false;
}
