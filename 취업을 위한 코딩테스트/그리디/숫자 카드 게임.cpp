#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int Arr[101][101];
vector<int> V;

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		int minNum = 987654321;
		for (int j = 0; j < M; j++) {
			minNum = min(minNum, Arr[i][j]);
		}
		V.push_back(minNum);
	}

	sort(V.begin(), V.end());

	cout << V[V.size() - 1] << endl;

	return 0;
}
