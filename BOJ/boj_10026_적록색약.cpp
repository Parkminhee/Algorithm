#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

int N;
char Map[101][101];
bool Visited[101][101];

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void Solve(int r, int c, char color, int type) {
	queue<pair<int, int>> q;
	Visited[r][c] = true;
	q.push({ r, c });

	while (!q.empty()) {
		int rr = q.front().first;
		int cc = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = rr + dr[i];
			int nc = cc + dc[i];

			if (nr >= 0 && nc >= 0 && nr < N && nc < N) {
				if (!Visited[nr][nc]) {
					if (type == 1) {
						if (Map[nr][nc] == color) {
							Visited[nr][nc] = true;
							q.push({ nr, nc });
						}
					}
					else if (type == 2) {
						if (color == 'R') {
							if (Map[nr][nc] == color || Map[nr][nc] == 'G') {
								Visited[nr][nc] = true;
								q.push({ nr, nc });
							}
						}
						else if (color == 'G') {
							if (Map[nr][nc] == color || Map[nr][nc] == 'R') {
								Visited[nr][nc] = true;
								q.push({ nr, nc });
							}
						}
						else {
							if (Map[nr][nc] == color) {
								Visited[nr][nc] = true;
								q.push({ nr, nc });
							}
						}
					}
				}
			}
		}
	}
}

int main() {
	cin >> N;

	string str = "";
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			Map[i][j] = str[j];
		}
	}

	int case1 = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!Visited[i][j]) {
				Solve(i, j, Map[i][j], 1);
				case1 += 1;
			}
		}
	}

	memset(Visited, false, sizeof(Visited));

	int case2 = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!Visited[i][j]) {
				Solve(i, j, Map[i][j], 2);
				case2 += 1;
			}
		}
	}

	cout << case1 << " " << case2 << endl;

	return 0;
}
