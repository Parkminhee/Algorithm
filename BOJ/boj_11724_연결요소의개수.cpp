#include<iostream>

using namespace std;

int Ans;
int N, M;
int Map[1001][1001];
bool Visited[1001];

void DFS(int n) {
	if (Visited[n]) return;

	Visited[n] = true;

	for (int i = 1; i <= N; i++) {
		if (Map[n][i] == 1) {
			DFS(i);
		}
	}
}

int main() {
	cin >> N >> M;

	int a = 0, b = 0;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;

		Map[a][b] = 1;
		Map[b][a] = 1;
	}

	for (int i = 1; i <= N; i++) {
		if (Visited[i] == false) {
			DFS(i);
			Ans += 1;
		}
	}

	cout << Ans << endl;

	return 0;
}
