#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int Ans = 987654321;
int Result = -1;
int Map[100][100];

int Go(int n) {
	int r = 0, c = n, d = 1;
	int dis = 0;

	while (true) {
		if (d == 1) {
			dis++;
			r++;

			while (true) {
				if (r == 99) return dis;

				if (c + 1 < 100) {
					if (Map[r][c + 1] == 1) {
						d = 3;
						break;
					}
				}

				if (c - 1 >= 0) {
					if (Map[r][c - 1] == 1) {
						d = 2;
						break;
					}
				}
				r++;
				dis++;
			}
		}
		else if (d == 2) {
			c--;
			dis++;

			while (true) {
				if (r + 1 < 100) {
					if (Map[r + 1][c] == 1) {
						d = 1;
						break;
					}
				}
				c--;
				dis++;
			}
		}
		else if (d == 3) {
			c++;
			dis++;

			while (true) {
				if (r + 1 < 100) {
					if (Map[r + 1][c] == 1) {
						d = 1;
						break;
					}
				}
				c++;
				dis++;
			}
		}
	}
}

void Solve() {
	for (int i = 0; i < 100; i++) {
		if (Map[0][i] == 1) {
			int ret = Go(i);
			if (Ans >= ret) {
				Ans = ret;
				Result = i;
			}
		}
	}
}

int main(int argc, char** argv)
{
	int tc = 0;
	for (int test_case = 1; test_case <= 10; ++test_case)
	{
		cin >> tc;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> Map[i][j];
			}
		}

		Solve();

		cout << "#" << test_case << " " << Result << endl;

		memset(Map, 0, sizeof(Map));
		Ans = 987654321;
		Result = -1;
	}
	return 0;
}
