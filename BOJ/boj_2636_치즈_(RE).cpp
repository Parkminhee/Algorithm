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

int CountCheese() {
	int count = 0;

	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < M - 1; j++) {
			if (Board[i][j] == 1) count += 1;
		}
	}

	return count;
}

void Solve() {
	// 치즈의 테두리 체크
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

			for (int k = 0; k < 4; k++) {
				int nr = i + dr[k];
				int nc = j + dc[k];

				if (Visited[nr][nc]) {
					Board[i][j] = 0;
					break;
				}
			}
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Board[i][j];
		}
	}

	int preCnt = 0;
	while (true) {
		int cnt = CountCheese();

		if (cnt == 0) break;
		else preCnt = cnt;

		Solve();

		memset(Visited, false, sizeof(Visited));
		Time += 1;
	}

	cout << Time << endl;
	cout << preCnt << endl;

	return 0;
}
