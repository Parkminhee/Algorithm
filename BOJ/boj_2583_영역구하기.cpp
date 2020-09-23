#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int M, N, K;
int Cnt;
int Map[101][101];
bool Visited[101][101];
vector<int> V;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void Make(int a, int b, int c, int d) {
	int sr = b;
	int sc = a;

	int er = d - 1;
	int ec = c - 1;

	for (int i = sr; i <= er; i++) {
		for (int j = sc; j <= ec; j++) {
			Map[i][j] = 1;
		}
	}
}

void BFS(int x, int y) {
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push({ x, y });
	Visited[x][y] = true;

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		cnt += 1;

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr >= 0 && nc >= 0 && nr < M && nc < N) {
				if (Map[nr][nc] == 0 && Visited[nr][nc] == false) {
					q.push({ nr ,nc });
					Visited[nr][nc] = true;
				}
			}
		}
	}

	V.push_back(cnt);
}

void Solve() {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (Map[i][j] == 0 && Visited[i][j] == false) {
				BFS(i, j); 
				Cnt += 1;
			}
		}
	}
}

int main() {
	cin >> M >> N >> K;

	int a = 0, b = 0, c = 0, d = 0;
	for (int i = 0; i < K; i++) {
		cin >> a >> b >> c >> d;

		Make(a, b, c, d);
	}

	Solve();
	sort(V.begin(), V.end());

	cout << Cnt << endl;
	for (int i = 0; i < V.size(); i++) cout << V[i] << " ";
	cout << endl;
	
	return 0;
}
