/*
 * Title: main_hw6_2.cpp
 * Abstract: This program will implement the Depth-First Search(DFS) algorithm.
 * ID: 0730
 * Name: Gabrielle Lake
 * Date: 03/09/2022
 */

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<int> markVector;
int count = 1;

void dfs(int source);

void fillGraphMatrix(int numV, int numE);

void displayDFS();

int main(){

    int numV, numE;
    cin >> numV >> numE;

    vector<int> tempVector;
    tempVector.resize(numV);
    graph.resize(numV, tempVector);

    fillGraphMatrix(numV, numE);

    markVector.resize(numV, 0);
    for(int i = 0; i < numV; i++){
        if(markVector[i] == 0){
            dfs(i);
        }
    }

    displayDFS();

    return 0;
}

void displayDFS() {
    for(int i = 0; i < markVector.size(); i++) {
        cout << "Mark[" << i << "]:" << markVector[i] << endl;
    }
}

void fillGraphMatrix(int numV, int numE) {
    for(int i = 0; i < numV; i++){
        for(int k = 0; k < numV; k++){
            graph[i][k] = 0;
        }
    }

    for(int i = 0; i < numE; i++){
        int source, dest;
        cin >> source >> dest;
        graph[source][dest] = 1;
    }
}

void dfs(int source){
    vector<int> vertex = graph[source];
    markVector[source] = count;
    count++;
    for(int i = 0; i < vertex.size(); i++){
        if(markVector[i] == 0){
            if(vertex[i] == 1){
                dfs(i);
            }
        }
    }
}

