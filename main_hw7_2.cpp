/*
 * Title: main_hw7_2.cpp
 * Abstract: This program will conduct the BFS traversal of a graph and display city names in the range of hop(s) from a starting city
 * ID: 0730
 * Name: Gabrielle Lake
 * Date: 03/21/2022
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool compareCities (const string& a, const string& b);

vector<int> bfs(const vector<vector<string>> &graph, int numV, const vector<string> &vertices, const string &source);

void displayHops(const vector<string> &vertices, const string &source, int sourceIndex, vector<int> &hops);

void gatherVertices(vector<vector<string>> &graph, int &numV, vector<string> &vertices);



int main() {

    vector<vector<string>> graph;
    int numV;
    vector<string> vertices;
    gatherVertices(graph, numV, vertices);


    sort(vertices.begin(), vertices.end(), compareCities);
    graph.push_back(vertices);

    int numE;
    cin >> numE;

    string start, dest;

    for(int i = 0; i < numE; i++){
        cin >> start >> dest;
        for(int k = 0; k < numV; k++){
            if(vertices[k] == start){
                graph[k].push_back(dest);
            }
        }
    }

    string source;
    cin >> source;
    int sourceIndex;
    for(int i = 0; i < numV; i++){
        if(vertices[i] == source){
            sourceIndex = i;
        }
    }

    vector<int> hops = bfs(graph, numV, vertices, source);

    displayHops(vertices, source, sourceIndex, hops);

    return 0;
}


void gatherVertices(vector<vector<string>> &graph, int &numV, vector<string> &vertices) {
    cin >> numV;
    graph.resize(numV);
    vertices.resize(numV);

    string tempCity;
    for(auto & vertex : vertices){
        cin >> tempCity;
        vertex = tempCity;
    }
}

void displayHops(const vector<string> &vertices, const string &source, int sourceIndex, vector<int> &hops) {
    int maxHops;
    cin >> maxHops;
    hops[sourceIndex] = 0;
    for(int i = 0; i < hops.size() - 1; i++){
        if(hops[i] != 0 || vertices[i] == source){
            if(hops[i] <= maxHops){
                cout << vertices[i] << ":" << hops[i] << endl;
            }
        }
    }
}

vector<int> bfs(const vector<vector<string>> &graph, int numV, const vector<string> &vertices, const string &source) {
    queue<string> queue;
    vector<int> hops(graph.size(), 0);
    queue.push(source);

    while(!queue.empty()){
        string current = queue.front();
        queue.pop();
        int currentIndex;
        for(int i = 0; i < numV; i++){
            if(vertices[i] == current){
                currentIndex = i;
            }
        }

        for(int i = 0; i < graph[currentIndex].size(); i++){
            string near = graph[currentIndex][i];
            int nearIndex;
            for(int k = 0; k < numV; k++){
                if(vertices[k] == near){
                    nearIndex = k;
                }
            }
            if(hops[nearIndex] == 0){
                hops[nearIndex] = hops[currentIndex] + 1;
                queue.push(near);
            }
        }

    }
    return hops;
}

bool compareCities (const string& a, const string& b) {
    return a<b;
}