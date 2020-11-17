/*
5 6
101010
111111
000001
111111
111111
*/

#include <iostream>
#include <string>
#include <queue>

using namespace std;

string str;
int Ans;
int N, M;
int Map[201][201];
int Time[201][201];
bool Visited[201][201];

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void Solve(int r, int c) {
	queue<pair<int, int>> q;
	q.push({ r, c });
	Visited[r][c] = true;
	Time[r][c] = 1;

	while (!q.empty()) {
		int rr = q.front().first;
		int cc = q.front().second;
		int time = Time[rr][cc];
		q.pop();

		if (rr == N - 1 && cc == M - 1) {
			Ans = time;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nr = rr + dr[i];
			int nc = cc + dc[i];

			if (nr >= 0 && nc >= 0 && nr < N && nc < M) {
				if (Map[nr][nc] == 1 && Visited[nr][nc] == false) {
					if (time + 1 < Time[nr][nc]) {
						q.push({ nr, nc });
						Visited[nr][nc] = true;
						Time[nr][nc] = time + 1;
					}
				}
			}
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			Map[i][j] = str[j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			Time[i][j] = 987654321;
		}
	}

	Solve(0, 0);

	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << Time[i][j] << " ";
		}
		cout << endl;
	}
	*/

	cout << Ans << endl;

	return 0;
}
