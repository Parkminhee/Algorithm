#include<iostream>
#include<string>
#include<queue>

using namespace std;

int N, M;
int Map[100][100];
int Time[100][100];
bool Visited[100][100];

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void BFS() {
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	Visited[0][0] = true;
	Time[0][0] = 1;

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		if (r == N - 1 && c == M - 1) {
			cout << Time[r][c] << endl;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr >= 0 && nc >= 0 && nr < N && nc < M) {
				if (Visited[nr][nc] == false && Map[nr][nc] == 1) {
					q.push({ nr, nc });
					Visited[nr][nc] = true;
					Time[nr][nc] = Time[r][c] + 1;
				}
			}
		}
	}
}

int main() {
	cin >> N >> M;

	string str = "";
	for (int i = 0; i < N; i++) {
		cin >> str;
		
		for (int j = 0; j < M; j++) {
			char c = str[j];
			Map[i][j] = c - '0';
		}
	}

	BFS();

	return 0;
}