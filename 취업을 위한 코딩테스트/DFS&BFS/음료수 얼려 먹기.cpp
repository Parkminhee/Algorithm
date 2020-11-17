/*
15 14
00000111100000
11111101111110
11011101101110
11011101100000
11011111111111
11011111111100
11000000011111
01111111111111
00000000011111
01111111111000
00011111111000
00000001111000
11111111110011
11100011111111
11100011111111
*/

/*
4 5
00110
00011
11111
00000
*/

#include <iostream>
#include <string>
#include <queue>

using namespace std;

string str;
int Ans;
int N, M;
int Map[1001][1001];
bool Visited[1001][1001];

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void Solve(int r, int c) {
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
				if (Map[nr][nc] == 0 && Visited[nr][nc] == false) {
					q.push({ nr, nc });
					Visited[nr][nc] = true;
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
			if (Map[i][j] == 0 && Visited[i][j] == false) {
				Solve(i, j);
				Ans += 1;
			}
		}
	}

	cout << Ans << endl;

	return 0;
}
