/*
 * Title: main_hw11_2.cpp
 * Abstract: This program will simulate the operations of linear probing.
 * ID: 0730
 * Name: Gabrielle Lake
 * Date: 04/30/2022
 */

#include <iostream>
#include <vector>
using namespace std;

void insert(vector<int> currHashValues, vector<string> currHashIndexState, int key);
void displayStatus(int index);
void search(int key);
void deleteValue(int key);
float getLoadFactor();
void rehash();
int updateHashTableSize(int previousSize);
bool isPrime(int num);

vector<int> hashValues;
vector<string> hashIndexState;
int hashValuesSize;
float totalNumsInHash = 0;

int main() {
    cin >> hashValuesSize;

    hashValues.resize(hashValuesSize, -1);
    hashIndexState.resize(hashValuesSize, "Empty");

    int numOfCommands;
    cin >> numOfCommands;

    string usersCommand;
    for(int i = 0; i < numOfCommands; i++) {
        cin >> usersCommand;
        int tempValue;
        
        if(usersCommand == "insert") {
            cin >> tempValue;
            insert(hashValues, hashIndexState, tempValue);
            totalNumsInHash++;
            if(getLoadFactor() > 0.5) {
                rehash();
            }
        } else if(usersCommand == "displayStatus") {
            cin >> tempValue;
            displayStatus(tempValue);
        } else if(usersCommand == "tableSize") {
            cout << hashValues.size() << endl;
        } else if(usersCommand == "search") {
            cin >> tempValue;
            search(tempValue);
        } else if(usersCommand == "delete") {
            cin >> tempValue;
            deleteValue(tempValue);
            totalNumsInHash--;
        } else if(usersCommand == "printTables") {
            cout << endl << "-----" << endl;
            for(int k = 0; k < hashValues.size(); k++) {
                cout << "Index " << k << " ";
                cout << hashValues[k] << " ";
                cout << hashIndexState[k] << endl;
            }
            cout << "-----" << endl;
        }
    }
    return 0;
}

void insert(vector<int> currHashValues, vector<string> currHashIndexState, int key) {
    int i = key % currHashValues.size();
    while(currHashIndexState[i] == "Active") {
        if(i == currHashValues.size()) {
            i = 0;
        } else {
            i++;
        }
    }
    currHashValues[i] = key;
    currHashIndexState[i] = "Active";
    hashValues = currHashValues;
    hashIndexState = currHashIndexState;
}

void displayStatus(int index) {
    string currStatus = hashIndexState[index];
    if(currStatus == "Empty") {
        if(hashValues[index] != -1) {
            cout << hashValues[index] << " Deleted" << endl;
        } else {
            cout << "Empty" << endl;
        }
    } else {
        cout << hashValues[index] << " Active" << endl;
    }
}


void search(int key) {
    for(int i = 0; i < hashValues.size(); i++) {
        if(hashValues[i] == key) {
            cout << key;
            if(hashIndexState[i] == "Empty") {
                cout << " Not found" << endl;
                return;
            } else if (hashIndexState[i] == "Active"){
                cout << " Found" << endl;
                return;
            }
        }
    }
    cout << key << " Not found" << endl;
}

void deleteValue(int key) {
    for(int i = 0; i < hashValuesSize; i++) {
        if(hashValues[i] == key) {
            hashIndexState[i] = "Empty";
        }
    }
}

float getLoadFactor() {
    return totalNumsInHash / hashValuesSize;
}

void rehash() {
    vector<int> oldHashTable = hashValues;
    hashValues.clear();
    hashIndexState.clear();
    hashValuesSize = updateHashTableSize(hashValuesSize);
    hashValues.resize(hashValuesSize, -1);
    hashIndexState.resize(hashValuesSize, "Empty");

    for(int key : oldHashTable) {
        if(key != - 1) {
            insert(hashValues, hashIndexState, key);
        }
    }
}

int updateHashTableSize(int previousSize) {
    int tempNewSize = previousSize * 2;
    while(!isPrime(tempNewSize)) {
        tempNewSize++;
    }
    int newSize = tempNewSize;

    return newSize;
}

bool isPrime(int num) {
    for(int i = 2; i < num; i++) {
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}
