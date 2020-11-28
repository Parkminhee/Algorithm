#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

int Time;
int N, L, R;
int Land[51][51];
bool Visited[51][51];
vector<pair<int, int>> V;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void Find(int r, int c) {
	queue<pair<int, int>> q;
	q.push({ r, c });
	Visited[r][c] = true;
	V.push_back({ r, c });

	while (!q.empty()) {
		int rr = q.front().first;
		int cc = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = rr + dr[i];
			int nc = cc + dc[i];

			if (nr >= 0 && nc >= 0 && nr < N && nc < N) {
				if (!Visited[nr][nc]) {
					int diff = abs(Land[rr][cc] - Land[nr][nc]);

					if (diff >= L && diff <= R) {
						q.push({ nr, nc });
						Visited[nr][nc] = true;
						V.push_back({ nr, nc });
					}
				}
			}
		}
	}
}

void Solve() {
	while (true) {
		bool flag = false;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!Visited[i][j]) {
					V.clear();

					Find(i, j);

					if (V.size() == 1) continue;

					int sum = 0;
					for (int k = 0; k < V.size(); k++) {
						sum += Land[V[k].first][V[k].second];
					}

					int people = sum / V.size();
					for (int k = 0; k < V.size(); k++) {
						Land[V[k].first][V[k].second] = people;
					}

					flag = true;
				}
			}
		}

		if (!flag) break;

		memset(Visited, false, sizeof(Visited));
		Time += 1;
	}
}

int main() {
	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Land[i][j];
		}
	}

	Solve();

	cout << Time << endl;

	return 0;
}
