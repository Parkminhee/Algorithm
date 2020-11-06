// O(N)
/*
#include <iostream>
#include <string>

using namespace std;

int N;
int R = 1, C = 1;
string dir;

char d[] = { 'U','D','L','R' };
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int main() {
	cin >> N;
	cin.ignore();		// 버퍼 비우기
	getline(cin, dir);	// 한 줄 전체 입력받기

	for (int i = 0; i < dir.length(); i++) {
		char c = dir[i];

		int nr = 0, nc = 0;
		for (int j = 0; j < 4; j++) {
			if (c == d[j]) {
				nr = R + dr[j];
				nc = C + dc[j];
				break;
			}
		}
		if (nr < 1 || nc < 1 || nr > N || nc > N) continue;
		R = nr;
		C = nc;
	}

	cout << R << " " << C << endl;

	return 0;
}
*/

#include <iostream>
#include <string>

using namespace std;

int R = 1, C = 1;
int N;
string S;

char D[] = { 'U', 'D', 'L', 'R' };
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int main() {
	cin >> N;

	cin.ignore();
	getline(cin, S);

	for (int i = 0; i < S.length(); i++) {
		if (S[i] == ' ') continue;

		int nr = 0, nc = 0;
		char c = S[i];
		for (int j = 0; j < 4; j++) {
			if (D[j] == c) {
				nr = R + dr[j];
				nc = C + dc[j];
				break;
			}
		}

		if (nr >= 1 && nc >= 1 && nr <= N && nc <= N) {
			R = nr, C = nc;
			//cout << R << ", " << C << endl;
		}
	}

	cout << R << ", " << C << endl;

	return 0;
}
