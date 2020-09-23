#include<iostream>
#include<vector>

using namespace std;

struct MAL {
	int r, c, d;
};

int Turn;
int N, K;
int ColorMap[13][13];
MAL Mal[11];
vector<int> MalMap[13][13];

int dr[] = { 0, 0, 0, -1, 1 };
int dc[] = { 0, 1, -1, 0, 0 };

bool Check() {
	for (int i = 1; i <= K; i++) {
		int r = Mal[i].r, c = Mal[i].c;
		if (MalMap[r][c].size() >= 4) return true;
	}
	return false;
}

int ChangeDir(int n) {
	int d = Mal[n].d;
	if (d == 1) return 2;
	else if (d == 2) return 1;
	else if (d == 3) return 4;
	else if (d == 4) return 3;
}

int FindIdx(int r, int c, int n) {
	for (int i = 0; i < MalMap[r][c].size(); i++) {
		if (MalMap[r][c][i] == n) return i;
	}
}

int FindRemove(int r, int c, int n) {
	int cnt = 0;
	for (int i = MalMap[r][c].size() - 1; i >= 0; i--) {
		if (MalMap[r][c][i] == n) break;
		cnt++;
	}
	return cnt + 1;
}

void Move(int r, int c, int nr, int nc, int idx, int n, int color) {
	if (color == 0) {
		for (int i = idx; i < MalMap[r][c].size(); i++) {
			MalMap[nr][nc].push_back(MalMap[r][c][i]);
			Mal[MalMap[r][c][i]].r = nr, Mal[MalMap[r][c][i]].c = nc;
		}
		int remove = FindRemove(r, c, n);
		for (int i = 0; i < remove; i++) {
			MalMap[r][c].pop_back();
		}
	}
	else if (color == 1) {
		for (int i = MalMap[r][c].size() - 1; i >= idx; i--) {
			MalMap[nr][nc].push_back(MalMap[r][c][i]);
			Mal[MalMap[r][c][i]].r = nr, Mal[MalMap[r][c][i]].c = nc;
		}
		int remove = FindRemove(r, c, n);
		for (int i = 0; i < remove; i++) {
			MalMap[r][c].pop_back();
		}
	}
	else if (color == 2) {
		int d = ChangeDir(n);
		Mal[n].d = d;

		int nnr = r + dr[d];
		int nnc = c + dc[d];

		if (nnr >= 1 && nnc >= 1 && nnr <= N && nnc <= N) {
			if (ColorMap[nnr][nnc] != 2) {
				Move(r, c, nnr, nnc, idx, n, ColorMap[nnr][nnc]);
			}
		}
	}
}

void Solve() {
	bool flag = false;

	while (true) {
		if (Turn > 1000) break;

		for (int i = 1; i <= K; i++) {
			int r = Mal[i].r, c = Mal[i].c, d = Mal[i].d;
			int nr = r + dr[d], nc = c + dc[d];

			int idx = FindIdx(r, c, i);

			if (nr >= 1 && nc >= 1 && nr <= N && nc <= N) Move(r, c, nr, nc, idx, i, ColorMap[nr][nc]);
			else Move(r, c, nr, nc, idx, i, 2);

			if (Check()) {
				flag = true;
				break;
			}
		}
		if (flag) break;
		Turn++;
	}

	if (flag) cout << Turn + 1 << endl;
	else cout << -1 << endl;
}

int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> ColorMap[i][j];
		}
	}

	int r = 0, c = 0, d = 0;
	for (int i = 1; i <= K; i++) {
		cin >> r >> c >> d;

		Mal[i] = { r, c, d };
		MalMap[r][c].push_back(i);
	}

	Solve();

	return 0;
}