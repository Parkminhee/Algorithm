#include<iostream>
#include<queue>

using namespace std;

int N, M, V;
int Map[1000][1000];
int Visited[1000];

void DFS(int v) {
	cout << v + 1 << " ";

	Visited[v] = 1;

	for (int i = 0; i < N; i++) {
		if (Visited[i] == 1 || Map[v][i] == 0) continue;
		DFS(i);
	}
}

void BFS(int v) {
	cout << endl;

	queue<int> q;
	q.push(v);
	Visited[v] = 1;

	while (!q.empty()) {
		v = q.front();
		q.pop();
		cout << v + 1 << " ";

		for (int i = 0; i < N; i++) {
			if (Visited[i] == 1 || Map[v][i] == 0) continue;
			q.push(i);
			Visited[i] = 1;
		}
	}
}

int main() {
	cin >> N >> M >> V;

	int a = 0, b = 0;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		a -= 1, b -= 1;

		Map[a][b] = 1;
		Map[b][a] = 1;
	}

	DFS(V - 1);
	memset(Visited, 0, sizeof(Visited));
	BFS(V - 1);

	return 0;
}
