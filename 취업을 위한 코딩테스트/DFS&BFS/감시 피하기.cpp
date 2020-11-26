#include <iostream>
#include <vector>

using namespace std;

bool Ans;
int Cnt;
int N;
char Map[7][7];
char CopyMap[7][7];
bool Wall[50];
vector<pair<int, int>> T;
vector<pair<int, int>> E;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

bool Find(int r, int c) {
	int dir[4] = { 0 };

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			if (dir[j] == 1) continue;

			int nr = r + (i * dr[j]);
			int nc = c + (i * dc[j]);

			if (nr >= 0 && nc >= 0 && nr < N && nc < N) {
				if (Map[nr][nc] == 'S') return false;
				else if (Map[nr][nc] == 'O') {
					dir[j] = 1;
				}
			}
		}
	}

	return true;
}

void Select(int idx, int cnt) {
	if (cnt == 3) {
		if (Ans) return;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				Map[i][j] = CopyMap[i][j];
			}
		}

		for (int i = 0; i < E.size(); i++) {
			if (Wall[i]) {
				int r = E[i].first;
				int c = E[i].second;

				Map[r][c] = 'O';
			}
		}
		/*
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << Map[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		*/

		for (int i = 0; i < T.size(); i++) {
			if (Find(T[i].first, T[i].second)) Cnt += 1;
		}

		if (Cnt == T.size()) {
			Ans = true;
			return;
		}
		else Cnt = 0;
	}
	else {
		for (int i = idx; i < E.size(); i++) {
			if (Wall[i] == false) {
				Wall[i] = true;
				Select(i, cnt + 1);
				Wall[i] = false;
			}
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Map[i][j];

			CopyMap[i][j] = Map[i][j];

			if (Map[i][j] == 'T') T.push_back({ i, j });
			else if (Map[i][j] == 'X') E.push_back({ i, j });
		}
	}

	Select(0, 0);

	if (Ans) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}
