#include <iostream>
#include <deque>

using namespace std;

int N, K;
int L;
int Map[101][101];
int Time[101];
char Dir[101];

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, -1, 0, 1 };

void Play() {
	deque<pair<int, int>> de;
	int time = 0;
	int idx = 0;
	int r = 1, c = 1;
	int d = 3;

	de.push_back({ r, c });
	Map[r][c] = 2;

	while (true) {
		time += 1;

		int nr = r + dr[d];
		int nc = c + dc[d];

		if ((nr < 1 || nc < 1 || nr > N || nc > N) || Map[nr][nc] == 2) break;
		else if (Map[nr][nc] == 0) {
			Map[nr][nc] = 2;
			Map[de.back().first][de.back().second] = 0;
			de.pop_back();
			de.push_front({ nr, nc });
		}
		else if (Map[nr][nc] == 1) {
			Map[nr][nc] = 2;
			de.push_front({ nr, nc });
		}

		if (idx < L) {
			if (time == Time[idx]) {
				if (Dir[idx] == 'L') {
					d += 1;
					if (d == 4) d = 0;
				}
				else if (Dir[idx] == 'D') {
					d -= 1;
					if (d == -1) d = 3;
				}
				idx += 1;
			}
		}
		r = nr, c = nc;
	}

	cout << time << endl;
}

int main() {
	cin >> N >> K;

	int r = 0, c = 0;
	for (int i = 0; i < K; i++) {
		cin >> r >> c;

		Map[r][c] = 1;
	}

	cin >> L;

	int x = 0;
	char ch = ' ';
	for (int i = 0; i < L; i++) {
		cin >> x >> ch;

		Time[i] = x, Dir[i] = ch;
	}

	Play();

	return 0;
}
