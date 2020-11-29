#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int Time;
int N, M;
int Board[101][101];
bool Visited[101][101];

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int Count() {
	int cnt = 0;

	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < M - 1; j++) {
			if (Board[i][j] == 1) cnt += 1;
		}
	}

	return cnt;
}

void Solve() {
	queue<pair<int, int>> q;

	q.push({ 0, 0 });
	Visited[0][0] = true;

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr >= 0 && nc >= 0 && nr < N && nc < M) {
				if (!Visited[nr][nc]) {
					if (Board[nr][nc] != 1) {
						q.push({ nr, nc });
						Visited[nr][nc] = true;
					}
				}
			}
		}
	}

	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < M - 1; j++) {
			if (Board[i][j] == 0) continue;

			int count = 0;
			for (int k = 0; k < 4; k++) {
				int ni = i + dr[k];
				int nj = j + dc[k];

				if (Visited[ni][nj]) count += 1;
			}

			if (count >= 2) Board[i][j] = 0;
		}
	}

	/*
	cout << endl;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << Board[i][j] << " ";
		}
		cout << endl;
	}
	*/
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Board[i][j];
		}
	}

	while (true) {
		int cnt = Count();

		if (cnt == 0) break;

		Solve();

		memset(Visited, false, sizeof(Visited));
		Time += 1;
	}

	cout << Time << endl;

	return 0;
}
