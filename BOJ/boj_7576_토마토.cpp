#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int Ans;
int M, N;
int Box[1001][1001];
int Time[1001][1001];
bool Visited[1001][1001];
queue<pair<int, int>> Q;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void Solve() {
	while (!Q.empty()) {
		int rr = Q.front().first;
		int cc = Q.front().second;
		int time = Time[rr][cc];
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = rr + dr[i];
			int nc = cc + dc[i];

			if (nr >= 0 && nc >= 0 && nr < N && nc < M) {
				if (Box[nr][nc] == 0 && Visited[nr][nc] == false) {
					if (time + 1 < Time[nr][nc]) {
						Q.push({ nr, nc });
						Visited[nr][nc] = true;
						Time[nr][nc] = time + 1;
					}
				}
			}
		}
	}
}

int main() {
	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			Time[i][j] = 987654321;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Box[i][j];

			if (Box[i][j] == 1) {
				Visited[i][j] = true;
				Time[i][j] = 0;
				Q.push({ i, j });
			}
		}
	}

	Solve();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Box[i][j] != -1 && Time[i][j] == 987654321) {
				cout << -1 << endl;
				return 0;
			}
			else if (Box[i][j] == 0) {
				Ans = max(Ans, Time[i][j]);
			}
		}
	}

	cout << Ans << endl;

	return 0;
}
