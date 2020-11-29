#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int Time;
int N, M;
int Map[301][301];
int TmpMap[301][301];
bool Visited[301][301];

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

bool Check() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Map[i][j] != 0) return false;
		}
	}

	return true;
}

void CountIce(int r, int c) {
	queue<pair<int, int>> q;
	q.push({ r, c });
	Visited[r][c] = true;

	while (!q.empty()) {
		int rr = q.front().first;
		int cc = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = rr + dr[i];
			int nc = cc + dc[i];

			if (nr >= 0 && nc >= 0 && nr < N && nc < M) {
				if (!Visited[nr][nc]) {
					if (Map[nr][nc] != 0) {
						q.push({ nr, nc });
						Visited[nr][nc] = true;
					}
				}
			}
		}
	}
}

void Solve(int r, int c) {
	int count = 0;

	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr >= 0 && nc >= 0 && nr < N && nc < M) {
			if (Map[nr][nc] == 0) {
				count += 1;
			}
		}
	}

	int ice = Map[r][c] - count;

	if (ice <= 0) TmpMap[r][c] = 0;
	else TmpMap[r][c] = ice;
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
		}
	}

	while (true) {
		int cntIce = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!Visited[i][j] && Map[i][j] != 0) {
					CountIce(i, j);
					cntIce += 1;
				}
			}
		}

		if (Check()) {
			Time = 0;
			break;
		}
		if (cntIce >= 2) break;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (Map[i][j] != 0) {
					Solve(i, j);
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				Map[i][j] = TmpMap[i][j];
			}
		}

		memset(TmpMap, 0, sizeof(TmpMap));
		memset(Visited, false, sizeof(Visited));
		Time += 1;
	}

	cout << Time << endl;

	return 0;
}
