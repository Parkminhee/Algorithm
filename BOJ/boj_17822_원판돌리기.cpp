#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

struct ROTATE {
	int x, d, k;
};

int N, M, T;
int Circles[51][51];
ROTATE Rotate[51];

vector<pair<int, int>> V;

void Rotation(int x, int d, int k) {
	int tmp[51] = { 0, };
	int s = k % M;

	if (d == 0) {
		for (int i = 1; i <= M; i++) {
			int idx = i + s;
			if (idx > M) {
				idx -= M;
			}
			tmp[idx] = Circles[x][i];
		}
	}
	else if (d == 1) {
		for (int i = 1; i <= M; i++) {
			int idx = i - s;
			if (idx < 1) {
				idx += M;
			}
			tmp[idx] = Circles[x][i];
		}
	}

	for (int i = 1; i <= M; i++) {
		Circles[x][i] = tmp[i];
	}

	memset(tmp, 0, sizeof(tmp));
}

void Find() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (Circles[i][j] != 0) {
				int idx_1 = i + 1;
				if (idx_1 <= N) {
					if (Circles[i][j] == Circles[i + 1][j]) {
						V.push_back(make_pair(i, j));
						V.push_back(make_pair(i + 1, j));
					}
				}

				int idx_2 = i - 1;
				if (idx_2 != 0) {
					if (Circles[i][j] == Circles[i - 1][j]) {
						V.push_back(make_pair(i, j));
						V.push_back(make_pair(i - 1, j));
					}
				}

				int idx1 = j + 1;
				if (idx1 > M) idx1 = 1;
				int idx2 = j - 1;
				if (idx2 < 1) idx2 = M;

				if (Circles[i][j] == Circles[i][idx1]) {
					V.push_back(make_pair(i, idx1));
					V.push_back(make_pair(i, j));
				}
				if (Circles[i][j] == Circles[i][idx2]) {
					V.push_back(make_pair(i, idx2));
					V.push_back(make_pair(i, j));
				}
			}
		}
	}

	sort(V.begin(), V.end());
	V.erase(unique(V.begin(), V.end()), V.end());
}

void Calc() {
	int cnt = 0;
	int total = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (Circles[i][j] != 0) {
				total += Circles[i][j];
				cnt += 1;
			}
		}
	}

	if (cnt != 0) {
		double avg = (double)total / cnt;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (Circles[i][j] != 0) {
					if (Circles[i][j] < avg) Circles[i][j] += 1;
					else if (Circles[i][j] > avg) Circles[i][j] -= 1;
				}
			}
		}
	}
}

void Erase() {
	for (int i = 0; i < V.size(); i++) {
		int r = V[i].first;
		int c = V[i].second;

		Circles[r][c] = 0;
	}

	V.clear();
}

void Solve() {
	for (int i = 1; i <= T; i++) {
		int x = Rotate[i].x;
		int d = Rotate[i].d;
		int k = Rotate[i].k;
		for (int j = x; j <= N; j += x) {
			Rotation(j, d, k);
		}
		Find();

		if (V.size() != 0) Erase();
		else Calc();
	}
}

int main() {
	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> Circles[i][j];
		}
	}

	int x = 0, d = 0, k = 0;
	for (int i = 1; i <= T; i++) {
		cin >> x >> d >> k;
		Rotate[i] = { x, d, k };
	}

	Solve();

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			ans += Circles[i][j];
		}
	}

	cout << ans << endl;
	
	return 0;
}
