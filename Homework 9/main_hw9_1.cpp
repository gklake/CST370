/*
 * Title: main_hw9_1.cpp
 * Abstract: This program will display the performance of three different sorting algorithms (= insertion sort, merge-sort, and quick sort) on the screen.
 * ID: 0730
 * Name: Gabrielle Lake
 * Date: 04/13/2022
 */

#include <iostream>
#include <vector>
#include <ctime>
#include <climits>
#include <chrono>
#include <algorithm>
using namespace std;

void choice1();
void choice2();
void choice3();

void insertion();
void insertionSort(int arr[], int size);

void merge();
void mergeSort(int arr[], int l, int r);

void quick();
void quickSort(int arr[], int low, int high);

int userSampleSize;
vector<int> values;

double insertionSortTotalElapsedTime;
double mergeSortTotalElapsedTime;
double quickSortTotalElapsedTime;

int main() {
    cout << "Enter input size: ";
    cin >> userSampleSize;

    insertionSortTotalElapsedTime = 0.0;
    mergeSortTotalElapsedTime = 0.0;
    quickSortTotalElapsedTime = 0.0;

    cout << "========== Select Option for Input Numbers ==========" << endl;
    cout << "\t1. Ascending Order" << endl;
    cout << "\t2. Descending Order" << endl;
    cout << "\t3. Random Order" << endl;
    cout << "Choose option: ";

    int userOption;
    cin >> userOption;

    switch(userOption) {
        case 1:
            choice1();
            break;
        case 2:
            choice2();
            break;
        case 3:
            choice3();
            break;
    }

    for(int i = 1; i <= 3; i++) {
        cout << endl << "========================== ";
        if(i == 1) {
            cout << "1st";
        } else if(i == 2) {
            cout << "2nd";
        } else {
            cout << "3rd";
        }
        cout << " Run =========================" << endl;


        cout << "Insertion Sort: ";
        insertion();
        cout << "Merge Sort: ";
        merge();
        cout << "Quick Sort: ";
        quick();

        cout << "============================================================" << endl;
    }

    cout << endl<< "========================== Ranking =========================" << endl;
    double insertionSortAverage = insertionSortTotalElapsedTime / 3;
    double mergeSortAverage = mergeSortTotalElapsedTime / 3;
    double quickSortAverage = quickSortTotalElapsedTime / 3;

    if(quickSortAverage < mergeSortAverage && quickSortAverage < insertionSortAverage){
        cout << "(1) Quick sort" << endl;
        if(mergeSortAverage < insertionSortAverage){
            cout << "(2) Merge sort" << endl;
            cout << "(3) Insertion sort" << endl;
        } else {
            cout << "(2) Insertion sort" << endl;
            cout << "(3) Merge sort" << endl;
        }
    } else if (mergeSortAverage < quickSortAverage && mergeSortAverage < insertionSortAverage){
        cout << "(1) Merge sort" << endl;
        if(quickSortAverage < insertionSortAverage){
            cout << "(2) Quick sort" << endl;
            cout << "(3) Insertion sort" << endl;
        } else {
            cout << "(2) Insertion sort" << endl;
            cout << "(3) Quick sort" << endl;
        }
    } else {
        cout << "(1) Insertion sort" << endl;
        if(mergeSortAverage < quickSortAverage){
            cout << "(2) Merge sort" << endl;
            cout << "(3) Quick sort" << endl;
        } else {
            cout << "(2) Quick sort" << endl;
            cout << "(3) Merge sort" << endl;
        }
    }
    cout << "============================================================" << endl;

    return 0;
}

void choice1() {
    vector<int> temp;
    for(int i = 0; i < userSampleSize; i++) {
        temp.push_back(i);
    }
    values = temp;
}

void choice2() {
    vector<int> temp;
    for(int i = userSampleSize - 1; i >= 0; i--) {
        temp.push_back(i);
    }
    values = temp;
}

void choice3(){
    vector<int> temp;
    srand(time(nullptr));
    for(int i = 0; i < userSampleSize; i++){
			int randNum1 = rand() % INT_MAX;
			int randNum2 = rand() % INT_MAX;
			int randomNumber = randNum1 - randNum2;
			temp.push_back(randomNumber);
    }
    values = temp;
}

void insertion(){
	int tempArray[userSampleSize];
	copy(values.begin(), values.end(), tempArray);

	auto start = chrono::high_resolution_clock::now();
	insertionSort(tempArray, userSampleSize);
	auto end = chrono::high_resolution_clock::now();

	double insertionElapsed = chrono::duration<double, std::milli>(end - start).count();
	insertionSortTotalElapsedTime += insertionElapsed;
	cout << insertionElapsed << " milliseconds" << endl;
}

void merge(){
	int tempArray[userSampleSize];
	copy(values.begin(), values.end(), tempArray);

	auto start = chrono::high_resolution_clock::now();
	mergeSort(tempArray, 0, userSampleSize - 1);
	auto end = chrono::high_resolution_clock::now();

	double mergeElapsed = chrono::duration<double, std::milli>(end - start).count();
	mergeSortTotalElapsedTime += mergeElapsed;
	cout << mergeElapsed << " milliseconds" << endl;
}

void quick(){
	int tempArray[userSampleSize];
	copy(values.begin(), values.end(), tempArray);

	auto start = chrono::high_resolution_clock::now();
	quickSort(tempArray, 0, userSampleSize - 1);
	auto end = chrono::high_resolution_clock::now();

	double quickElapsed = chrono::duration<double, std::milli>(end - start).count();
	quickSortTotalElapsedTime += quickElapsed;
	cout << quickElapsed << " milliseconds" << endl;
}


/*
	=============================================================================
		NOT MY CODE, ALL SORTING ALGORITHMS ARE FROM PROGRAMIZ
	=============================================================================
*/

// =============== Source: https://www.programiz.com/dsa/insertion-sort ===============
void insertionSort(int array[], int size) {
	for (int step = 1; step < size; step++) {
		int key = array[step];
		int j = step - 1;

		// Compare key with each element on the left of it until an element smaller than
		// it is found.
		// For descending order, change key<array[j] to key>array[j].
		while (key < array[j] && j >= 0) {
			array[j + 1] = array[j];
			--j;
		}
		array[j + 1] = key;
	}
}

// =============== Source: https://www.programiz.com/dsa/merge-sort ===============
// Merge two sub-arrays L and M into arr
void merge(int arr[], int p, int q, int r) {

	// Create L ← A[p..q] and M ← A[q+1..r]
	int n1 = q - p + 1;
	int n2 = r - q;

	int L[n1], M[n2];

	for (int i = 0; i < n1; i++)
		L[i] = arr[p + i];
	for (int j = 0; j < n2; j++)
		M[j] = arr[q + 1 + j];

	// Maintain current index of sub-arrays and main array
	int i, j, k;
	i = 0;
	j = 0;
	k = p;

	// Until we reach either end of either L or M, pick larger among
	// elements L and M and place them in the correct position at A[p..r]
	while (i < n1 && j < n2) {
		if (L[i] <= M[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = M[j];
			j++;
		}
		k++;
	}

	// When we run out of elements in either L or M,
	// pick up the remaining elements and put in A[p..r]
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = M[j];
		j++;
		k++;
	}
}

// Divide the array into two sub-arrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
	if (l < r) {
		// m is the point where the array is divided into two sub-arrays
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		// Merge the sorted sub arrays
		merge(arr, l, m, r);
	}
}

// =============== Source: https://www.programiz.com/dsa/quick-sort ===============
// function to swap elements
void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

// function to print the array
void printArray(int array[], int size) {
	int i;
	for (i = 0; i < size; i++)
			cout << array[i] << " ";
	cout << endl;
}

// function to rearrange array (find the partition point)
int partition(int array[], int low, int high) {

	// select the rightmost element as pivot
	int pivot = array[high];

	// pointer for greater element
	int i = (low - 1);

	// traverse each element of the array
	// compare them with the pivot
	for (int j = low; j < high; j++) {
		if (array[j] <= pivot) {

			// if element smaller than pivot is found
			// swap it with the greater element pointed by i
			i++;

			// swap element at i with element at j
			swap(&array[i], &array[j]);
		}
	}

	// swap pivot with the greater element at i
	swap(&array[i + 1], &array[high]);

	// return the partition point
	return (i + 1);
}

void quickSort(int array[], int low, int high) {
	if (low < high) {

		// find the pivot element such that
		// elements smaller than pivot are on left of pivot
		// elements greater than pivot are on right of pivot
		int pi = partition(array, low, high);

		// recursive call on the left of pivot
		quickSort(array, low, pi - 1);

		// recursive call on the right of pivot
		quickSort(array, pi + 1, high);
	}
}
