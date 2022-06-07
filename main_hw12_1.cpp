/*
 * Title: main_hw12_1.cpp
 * Abstract: This program will collect the maximum number of coins on an n x m board and provide the path to get the coins.
 * ID: 0730
 * Name: Gabrielle Lake
 * Date: 05/10/2022
 */

#include <iostream>
#include <vector>

void findOptimalPath(int n, int m, std::vector<std::vector<int>> &matrix, int pathCoins, std::vector<std::pair<int, int>>path, std::vector<std::pair<int, int>>& optimalPath, int &maxCoins);

void displayOutput(int n, int m, std::vector<std::pair<int, int>> &optimalPath, int maxCoins);

using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> matrix(n, vector<int>(m));
	vector<pair<int, int>> path;
	vector<pair<int, int>> optimalPath;
	int pathCoins = 0;
	int maxCoins = -1;

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			int tempValue;
			cin >> tempValue;
			matrix[i][j] = tempValue;
		}
	}

	findOptimalPath(0, 0, matrix, pathCoins, path, optimalPath, maxCoins);

	displayOutput(n, m, optimalPath, maxCoins);
	
	return 0;
}

void displayOutput(int n, int m, vector<pair<int, int>> &optimalPath, int maxCoins) {
	cout << "Max coins:" << maxCoins << endl;
	cout << "Path:";
	for (pair<int, int> p : optimalPath){
		cout << "(" << p.first << "," << p.second << ")";
		if (p.first == n && p.second == m){
			cout << endl;
		}
		else{
			cout << "->";
		}
	}
}


void findOptimalPath(int n, int m, vector<vector<int>>& matrix, int pathCoins, vector<pair<int, int>> path, vector<pair<int, int>> &optimalPath, int &maxCoins)
{
	if (n >= matrix.size() || m >= matrix[0].size()){
		return;
	}

	path.emplace_back(n + 1, m + 1 );

	if ((n == matrix.size() - 1) && (m == matrix[0].size() - 1)){
		if (pathCoins + matrix[n][m] > maxCoins){
			maxCoins = pathCoins + matrix[n][m];
			optimalPath = path;
		}
		return;
	}

	int currentCoins = pathCoins + matrix[n][m];
	findOptimalPath(n + 1, m, matrix, currentCoins, path, optimalPath, maxCoins);
	findOptimalPath(n, m + 1, matrix, currentCoins, path, optimalPath, maxCoins);
}
