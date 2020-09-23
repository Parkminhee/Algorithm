#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int Ans;
int T;
int M, N, K;
int Map[50][50];
bool Visited[50][50];

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void BFS(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	Visited[x][y] = true;

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr >= 0 && nc >= 0 && nr < N && nc < M) {
				if (Visited[nr][nc] == false && Map[nr][nc] == 1) {
					q.push({ nr, nc });
					Visited[nr][nc] = true;
				}
			}
		}
	}
}

void Solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Map[i][j] == 1 && Visited[i][j] == false) {
				BFS(i, j);
				Ans += 1;
			}
		}
	}
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> M >> N >> K;

		int a = 0, b = 0;
		for (int j = 0; j < K; j++) {
			cin >> a >> b;

			Map[b][a] = 1;
		}

		Solve();

		cout << Ans << endl;

		memset(Map, 0, sizeof(Map));
		memset(Visited, 0, sizeof(Visited));
		Ans = 0;
	}

	return 0;
}