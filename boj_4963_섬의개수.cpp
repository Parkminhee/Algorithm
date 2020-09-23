#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int Ans;
int Map[51][51];
bool Visited[51][51];

int dr[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void BFS(int x, int y, int h, int w) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	Visited[x][y] = true;

	while(!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr >= 0 && nc >= 0 && nr < h && nc < w) {
				if (Map[nr][nc] == 1 && Visited[nr][nc] == false) {
					q.push({ nr, nc });
					Visited[nr][nc] = true;
				}
			}
		}
	}
}

void Solve(int h, int w) {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (Map[i][j] == 1 && Visited[i][j] == false) {
				BFS(i, j, h, w);
				Ans += 1;
			}
		}
	}
}

int main() {
	while (true) {
		int w = 0, h = 0;
		cin >> w >> h;

		if (w == 0 && h == 0) break;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> Map[i][j];
			}
		}

		Solve(h, w);
		cout << Ans << endl;

		memset(Map, 0, sizeof(Map));
		memset(Visited, false, sizeof(Visited));
		Ans = 0;
	}
	return 0;
}