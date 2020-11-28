#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int Ans;
int R, C;
char Map[21][21];
bool Visited[26];
vector<char> V;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void Solve(int r, int c, int cnt) {
	Ans = max(Ans, cnt);

	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr >= 0 && nc >= 0 && nr < R && nc < C) {
			if (Visited[Map[nr][nc] - 'A'] == false) {
				Visited[Map[nr][nc] - 'A'] = true;
				Solve(nr, nc, cnt + 1);
				Visited[Map[nr][nc] - 'A'] = false;
			}
		}
	}
}

int main() {
	cin >> R >> C;

	string str = "";
	for (int i = 0; i < R; i++) {
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			Map[i][j] = str[j];
		}
	}

	Visited[Map[0][0] - 'A'] = true;
	Solve(0, 0, 1);

	cout << Ans << endl;

	return 0;
}
