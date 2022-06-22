/*
 * Title: main_hw10_1.cpp
 * Abstract: This program will conduct the topological sorting using the Kahn algorithm covered in the class.
 * ID: 0730
 * Name: Gabrielle Lake
 * Date: 04/19/2022
 */

#include <iostream>
#include <vector>
#include <queue>

void printTopologicalSortOrder(const std::vector<int> &topologicalOrder);
std::vector<int> topologicalSort(int numV, const std::vector<int> *adjacencyList, std::vector<int> &inDegree, int visitedCount);

using namespace std;

int main(){

	vector<vector<int>> graph;
	int numV;
	cin >> numV;
	int numE;
	cin >> numE;

	vector<int> adjacencyList[numV];
    
	graph.resize(numV);

	int source;
	int destination;

	for(int i = 0; i < numE; i++){
		cin >> source >> destination;
		graph[source].push_back(destination);
		adjacencyList[source].push_back(destination);
	}


	vector<int> inDegree(graph.size(), 0);
	for(auto & i : graph){
		for(int k : i){
			inDegree[k]++;
		}
	}

	int visitedCount = 0;

	for(int i = 0; i < inDegree.size(); i++){
		cout << "In-degree[" << i << "]:" << inDegree[i] << endl;
	}

    vector<int> topologicalOrder = topologicalSort(numV, adjacencyList, inDegree, visitedCount);

    printTopologicalSortOrder(topologicalOrder);

    return 0;
}

vector<int> topologicalSort(int numV, const vector<int> *adjacencyList, vector<int> &inDegree, int visitedCount) {
    queue<int> queue;
    vector<int> topologicalOrder;
    for(int i = 0; i < numV; i++){
        if(inDegree[i] == 0){
            queue.push(i);
        }
    }

    while(!queue.empty()){
        visitedCount++;
        for(auto x: adjacencyList[queue.front()]){
            inDegree[x]--;
            if(inDegree[x] == 0){
                queue.push(x);
            }
        }
        topologicalOrder.push_back(queue.front());
        queue.pop();
    }
    return topologicalOrder;
}

void printTopologicalSortOrder(const vector<int> &topologicalOrder) {
    cout << "Order:";
    for(int i = 0; i < topologicalOrder.size(); i++){
        if(i == topologicalOrder.size() - 1){
            cout << topologicalOrder[i] << endl;
        } else {
            cout << topologicalOrder[i] << "->";
        }
    }
}
