#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

string str;
int N;
int Map[26][26];
bool Visited[26][26];
vector<int> V;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int Solve(int r, int c) {
	int count = 0;
	queue<pair<int, int>> q;

	q.push({ r, c });
	Visited[r][c] = true;

	while (!q.empty()) {
		int rr = q.front().first;
		int cc = q.front().second;
		q.pop();
		count += 1;

		for (int i = 0; i < 4; i++) {
			int nr = rr + dr[i];
			int nc = cc + dc[i];

			if (nr >= 0 && nc >= 0 && nr < N && nc < N) {
				if (Map[nr][nc] == 1 && Visited[nr][nc] == false) {
					q.push({ nr, nc });
					Visited[nr][nc] = true;
				}
			}
		}
	}

	return count;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < N; j++) {
			Map[i][j] = str[j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (Map[i][j] == 1 && Visited[i][j] == false) {
				int ret = Solve(i, j);
				V.push_back(ret);
			}
		}
	}

	sort(V.begin(), V.end());

	cout << V.size() << endl;

	for (int i = 0; i < V.size(); i++) {
		cout << V[i] << endl;
	}

	return 0;
}
