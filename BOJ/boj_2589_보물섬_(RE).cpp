/* 시간 초과 코드
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int Ans = -987654321;
int N, M;
int Time[51][51];
char Map[51][51];
bool Visited[51][51];
bool SelectLand[2500];
vector<pair<int, int>> Land;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int FindDistance() {
	int start = 0;
	int sr = 0, sc = 0, er = 0, ec = 0;

	for (int i = 0; i < Land.size(); i++) {
		if (SelectLand[i] && start == 0) {
			sr = Land[i].first;
			sc = Land[i].second;
			start += 1;
		}
		else if (SelectLand[i] && start == 1) {
			er = Land[i].first;
			ec = Land[i].second;
		}
	}

	//cout << sr << ", " << sc << endl;
	//cout << er << ", " << ec << endl;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			Time[i][j] = 987654321;
		}
	}

	bool visited[51][51] = { false, };
	queue<pair<int, int>> q;

	q.push({ sr, sc });
	visited[sr][sc] = true;
	Time[sr][sc] = 0;

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		int t = Time[r][c];
		q.pop();

		if (r == er && c == ec) break;

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr >= 0 && nc >= 0 && nr < N && nc < M) {
				if (!visited[nr][nc]) {
					if (Map[nr][nc] == 'L') {
						if (t + 1 < Time[nr][nc]) {
							q.push({ nr, nc });
							visited[nr][nc] = true;
							Time[nr][nc] = t + 1;
						}
					}
				}
			}
		}
	}
	//cout << Time[er][ec] << endl;
	return Time[er][ec];
}

void Solve(int idx, int cnt) {
	if (cnt == 2) {
		int time = FindDistance();

		if (time != 987654321) Ans = max(Ans, time);
	}
	else {
		for (int i = idx; i < Land.size(); i++) {
			if (SelectLand[i] == false) {
				SelectLand[i] = true;
				Solve(i, cnt + 1);
				SelectLand[i] = false;
			}
		}
	}
}

int main() {
	cin >> N >> M;

	string str = "";
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			Map[i][j] = str[j];

			if (Map[i][j] == 'L') Land.push_back({ i, j });
		}
	}

	Solve(0, 0);

	cout << Ans << endl;

	return 0;
}
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int Ans;
int N, M;
int Time[51][51];
char Map[51][51];
bool Visited[51][51];
vector<pair<int, int>> Land;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void BFS(int r, int c) {
	queue<pair<int, int>> q;

	q.push({ r, c });
	Visited[r][c] = true;
	Time[r][c] = 0;

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr >= 0 && nc >= 0 && nr < N && nc < M) {
				if (!Visited[nr][nc]) {
					if (Map[nr][nc] == 'L') {
						q.push({ nr, nc });
						Visited[nr][nc] = true;
						Time[nr][nc] = Time[r][c] + 1;

						Ans = max(Ans, Time[nr][nc]);
					}
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
		for (int j = 0; j < str.length(); j++) {
			Map[i][j] = str[j];

			if (Map[i][j] == 'L') Land.push_back({ i, j });
		}
	}

	for (int i = 0; i < Land.size(); i++) {
		memset(Time, 0, sizeof(Time));
		memset(Visited, false, sizeof(Visited));

		BFS(Land[i].first, Land[i].second);
	}

	cout << Ans << endl;

	return 0;
}
