#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

int N;
int Cnt;
int Map[101][101];
int NewMap[101][101];
bool Visited[101][101];

int Ans = -987654321;
int Max = -987654321;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void FindDownUp(int h) {
	//cout << "높이 : " << h << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (Map[i][j] > h) {
				NewMap[i][j] = 1;		// 0인 경우 물에 잠김
			}
		}
	}
	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << NewMap[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	*/
}

void BFS(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	Visited[x][y] = true;

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr >= 0 && nc >= 0 && nr < N && nc < N) {
				if (NewMap[nr][nc] == 1 && Visited[nr][nc] == false) {
					q.push({ nr, nc });
					Visited[nr][nc] = true;
				}
			}
		}
	}
}

void DFS() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (NewMap[i][j] == 1 && Visited[i][j] == false) {
				BFS(i, j);
				Cnt += 1;
			}
		}
	}
}

void Solve(int h) {
	FindDownUp(h);
	DFS();
	//cout << Cnt << endl;
	Ans = max(Ans, Cnt);

	memset(NewMap, 0, sizeof(NewMap));
	memset(Visited, false, sizeof(Visited));
	Cnt = 0;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Map[i][j];

			Max = max(Map[i][j], Max);
		}
	}

	for (int i = 0; i <= Max; i++) {
		Solve(i);
	}

	cout << Ans << endl;

	return 0;
}