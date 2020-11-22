#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int Ans;
int N, M;
int Lab[9][9];
int CopyLab[9][9];
int MakeWall[81];
bool Visited[9][9];
vector<pair<int, int>> Empty;
vector<pair<int, int>> Virus;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int Spread() {
	memset(Visited, false, sizeof(Visited));

	int count = 0;
	queue<pair<int, int>> q;
	
	for (int i = 0; i < Virus.size(); i++) {
		q.push({ Virus[i].first, Virus[i].second });
		Visited[Virus[i].first][Virus[i].second] = true;
	}

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr >= 0 && nc >= 0 && nr < N && nc < M) {
				if (Visited[nr][nc] == false && Lab[nr][nc] == 0) {
					q.push({ nr, nc });
					Visited[nr][nc] = true;
					Lab[nr][nc] = 2;
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Lab[i][j] == 0) count += 1;
		}
	}

	return count;
}

void Solve(int idx, int cnt) {
	if (cnt == 3) {
		for (int i = 0; i < Empty.size(); i++) {
			if (MakeWall[i] == 1) {
				Lab[Empty[i].first][Empty[i].second] = 1;
			}
		}

		int ret = Spread();
		Ans = max(Ans, ret);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				Lab[i][j] = CopyLab[i][j];
			}
		}
	}
	else {
		for (int i = idx; i < Empty.size(); i++) {
			if (MakeWall[i] == 0) {
				MakeWall[i] = 1;
				Solve(i, cnt + 1);
				MakeWall[i] = 0;
			}
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Lab[i][j];

			CopyLab[i][j] = Lab[i][j];

			if (Lab[i][j] == 0) Empty.push_back({ i, j });
			else if (Lab[i][j] == 2) Virus.push_back({ i, j });
		}
	}

	Solve(0, 0);

	cout << Ans << endl;

	return 0;
}
