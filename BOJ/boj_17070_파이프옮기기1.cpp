#include<iostream>

using namespace std;

int Ans;
int N;
int Map[17][17];

void Solve(int r, int c, int d) {
	if (r == N && c == N) {
		Ans += 1;
		return;
	}

	if (d == 0) {
		int nr = r;
		int nc = c + 1;

		if (nr >= 1 && nc >= 1 && nr <= N && nc <= N) {
			if (Map[nr][nc] == 0) Solve(nr, nc, 0);
		}

		nr = r + 1;
		nc = c + 1;

		if (nr >= 1 && nc >= 1 && nr <= N && nc <= N) {
			if (Map[nr][nc] == 0 && Map[r][c + 1] == 0 && Map[r + 1][c] == 0) Solve(nr, nc, 2);
		}
	}
	else if (d == 1) {
		int nr = r + 1;
		int nc = c;

		if (nr >= 1 && nc >= 1 && nr <= N && nc <= N) {
			if (Map[nr][nc] == 0) Solve(nr, nc, 1);
		}

		nr = r + 1;
		nc = c + 1;

		if (nr >= 1 && nc >= 1 && nr <= N && nc <= N) {
			if (Map[nr][nc] == 0 && Map[r][c + 1] == 0 && Map[r + 1][c] == 0) Solve(nr, nc, 2);
		}
	}
	else if (d == 2) {
		int nr = r;
		int nc = c + 1;

		if (nr >= 1 && nc >= 1 && nr <= N && nc <= N) {
			if (Map[nr][nc] == 0) Solve(nr, nc, 0);
		}

		nr = r + 1;
		nc = c;

		if (nr >= 1 && nc >= 1 && nr <= N && nc <= N) {
			if (Map[nr][nc] == 0) Solve(nr, nc, 1);
		}

		nr = r + 1;
		nc = c + 1;

		if (nr >= 1 && nc >= 1 && nr <= N && nc <= N) {
			if (Map[nr][nc] == 0 && Map[r][c + 1] == 0 && Map[r + 1][c] == 0) Solve(nr, nc, 2);
		}
	}
}

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> Map[i][j];
		}
	}

	Solve(1, 2, 0);

	cout << Ans << endl;

	return 0;
}
