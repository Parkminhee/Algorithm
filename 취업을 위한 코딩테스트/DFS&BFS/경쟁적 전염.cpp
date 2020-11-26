#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, K;
int S, X, Y;
int Lab[201][201];
bool Visited[201][201];
vector<pair<int, pair<int, int>>> Virus;
queue<pair<int, pair<int, int>>> Q;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void BFS(int v, int r, int c) {
	Visited[r][c] = true;

	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr >= 1 && nc >= 1 && nr <= N && nc <= N) {
			if (Visited[nr][nc] == false) {
				if (Lab[nr][nc] == 0) {
					Lab[nr][nc] = v;
					Q.push({ Lab[nr][nc], {nr, nc} });
					Visited[nr][nc] = true;
				}
			}
		}
	}
}

int main() {
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> Lab[i][j];

			if (Lab[i][j] != 0) {
				Virus.push_back({ Lab[i][j], { i, j } });
			}
		}
	}

	cin >> S >> X >> Y;

	for (int i = 1; i <= S; i++) {
		sort(Virus.begin(), Virus.end());

		for (int j = 0; j < Virus.size(); j++) {
			BFS(Virus[j].first, Virus[j].second.first, Virus[j].second.second);
		}

		Virus.clear();

		while (!Q.empty()) {
			int vn = Q.front().first;
			int r = Q.front().second.first;
			int c = Q.front().second.second;
			Q.pop();

			Virus.push_back({ vn, { r, c } });
		}
	}

	if (Lab[X][Y] != 0) cout << Lab[X][Y] << endl;
	else cout << 0 << endl;

	return 0;
}
