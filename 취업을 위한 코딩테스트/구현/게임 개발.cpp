#include <iostream>

using namespace std;

int Ans = 1;
int N, M;
int R, C, D;
int Map[51][51];
bool Visited[51][51];

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

int main() {
	cin >> N >> M;
	cin >> R >> C >> D;
	Visited[R][C] = true;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
		}
	}

	int nr = 0, nc = 0;
	int dirCnt = 0;

	while (true) {
		D -= 1;
		if (D == -1) D = 3;

		nr = R + dr[D];
		nc = C + dc[D];

		if (Map[nr][nc] == 0 && Visited[nr][nc] == false) {
			//cout << nr << ", " << nc << endl;
			Visited[nr][nc] = true;
			R = nr;
			C = nc;
			Ans += 1;
			dirCnt = 0;
			// continue; (꼭 해야하나..?)
		}
		else {
			dirCnt += 1;
		}

		if (dirCnt == 4) {
			nr = R - dr[D];
			nc = C - dc[D];

			if (Map[nr][nc] == 1) break;
			else {
				R = nr;
				C = nc;
			}

			dirCnt = 0;
		}
	}

	cout << Ans << endl;

	return 0;
}
