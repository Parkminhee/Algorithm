#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int Ans = -987654321;
int N, M, D;
int Position[16];
int CopyMap[16][16];
int Map[16][16];
vector<pair<int, int>> V;

void FindEnemy(int c) {
	vector<pair<int, pair<int, int>>> v;
	int ar = N + 1;
	int ac = c;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (Map[i][j] == 1) {
				int dis = abs(ar - i) + abs(ac - j);

				if (dis <= D) {
					v.push_back({ dis, {j, i} });
				}
			}
		}
	}

	if (!v.empty()) {
		sort(v.begin(), v.end());
		V.push_back({ v[0].second.second, v[0].second.first });
	}
}

int Attack() {
	for (int i = 1; i <= M; i++) {
		if (Position[i] == 1) {
			FindEnemy(i);
		}
	}

	int kill = 0;
	if (!V.empty()) {
		sort(V.begin(), V.end());
		V.erase(unique(V.begin(), V.end()), V.end());

		for (int i = 0; i < V.size(); i++) {
			int r = V[i].first;
			int c = V[i].second;

			Map[r][c] = 0;
			kill += 1;
		}

		V.clear();
	}

	return kill;
}

void Move() {
	for (int i = N; i >= 1; i--) {
		for (int j = 1; j <= M; j++) {
			if (Map[i][j] == 1) {
				int nr = i + 1;
				int nc = j;

				if (nr <= N) Map[nr][nc] = 1;
				Map[i][j] = 0;
			}
		}
	}
}

bool Check() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (Map[i][j] == 1) return false;
		}
	}
	return true;
}

void Select(int idx, int cnt) {
	if (cnt == 3) {
		int ret = 0;

		while (true) {
			if (Check()) break;
			ret += Attack();
			Move();
		}
		Ans = max(Ans, ret);

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				Map[i][j] = CopyMap[i][j];
			}
		}
	}
	else {
		for (int i = idx; i <= M; i++) {
			if (Position[i] == 0) {
				Position[i] = 1;
				Select(i, cnt + 1);
				Position[i] = 0;
			}
		}
	}
}

int main() {
	cin >> N >> M >> D;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> Map[i][j];
			CopyMap[i][j] = Map[i][j];
		}
	}

	Select(1, 0);

	cout << Ans << endl;

	return 0;
}
