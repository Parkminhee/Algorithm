// O(8)

#include <iostream>
#include <string>

using namespace std;

string S;
int Ans;

int dr[] = { -2, -2, 2, 2, -1, 1, -1, 1 };
int dc[] = { 1, -1, 1, -1, 2, 2, -2, -2 };

int main() {
	cin >> S;

	int c = S[0] - '0' - 48;
	int r = S[1] - '0';

	for (int i = 0; i < 8; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr >= 1 && nc >= 1 && nr <= 8 && nc <= 8) Ans += 1;
	}

	cout << Ans << endl;

	return 0;
}
