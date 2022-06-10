/*
 * INSTRUCTION:
 *     This is a C++ staring code for hw4_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw4_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw4_1.cpp
 * Abstract: This program will convert directed graph data from a user into adjacency list format.
 * ID: 0730
 * Name: Gabrielle Lake
 * Date: 02/21/2022
 */

#include <iostream>
using namespace std;

int main()
{
    int vertices, edges;
		int adjacencyList[50][50];

		cin >> vertices >> edges;

		for(int i = 0; i < edges; i++){
			int start, end;
			cin >> start >> end;

			adjacencyList[start][end] = 1;
			adjacencyList[start][end] = 1;
			
		}

		for(int i = 0; i < vertices; i++){
			cout << i;
			for(int k = 0; k < vertices; k++){
				if(adjacencyList[i][k] == 1){
					cout << "->" << k;
				}
			}
			cout << endl;
		}

    return 0;
}

