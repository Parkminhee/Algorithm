#include<iostream>
#include<cstring>

using namespace std;

bool Flag;
int Ans;
int Board[100][100];

void Solve() {
	for (int i = 0; i < 100; i++) {
		if (Board[0][i] == 1) {
			int r = 0, c = i, d = 1;

			while (true) {
				//cout << r << ", " << c << endl;

				if (r == 99) {
					break;
				}

				if (d == 1) {
					while (true) {
						r += 1;

						if (r == 99) break;

						if (c + 1 < 100) {
							if (Board[r][c + 1] == 1) {
								d = 3;
								break;
							}
						}
						if (c - 1 >= 0) {
							if (Board[r][c - 1] == 1) {
								d = 2;
								break;
							}
						}
					}
				}
				else if (d == 2) {
					while (true) {
						c -= 1;

						if (r == 99) break;

						if (r + 1 < 100) {
							if (Board[r + 1][c] == 1) {
								d = 1;
								break;
							}
						}
					}
				}
				else if (d == 3) {
					while (true) {
						c += 1;

						if (r == 99) break;

						if (r + 1 < 100) {
							if (Board[r + 1][c] == 1) {
								d = 1;
								break;
							}
						}
					}
				}
			}

			if (Board[r][c] == 2) {
				Ans = i;
			}
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int n;
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		cin >> n;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> Board[i][j];
			}
		}

		Solve();

		cout << "#" << test_case << " " << Ans << endl;

		memset(Board, 0, sizeof(Board));
	}
	return 0;
}
