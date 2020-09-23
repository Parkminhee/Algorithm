#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int Ans = -987654321;
int Pos[5];
int Mal[11];
int Kan[11];
int Map[33] = {
	0, 2, 4, 6, 8, 10,
	12, 14, 16, 18, 20,
	22, 24, 26, 28, 30,
	32, 34, 36, 38, 40,
	0,
	13, 16, 19, 25, 26, 27, 28,
	22, 24, 30, 35
};

int Rule[14][6] = {
	{5, 22, 23, 24, 25, 31},
	{10, 29, 30, 25, 31, 32},
	{15, 28, 27, 26, 25, 31},
	{22, 23, 24, 25, 31, 32},
	{23, 24, 25, 31, 32, 20},
	{24, 25, 31, 32, 20, 21},
	{25, 31, 32, 20, 21, 21},
	{26, 25, 31, 32, 20, 21},
	{27, 26, 25, 31, 32, 20},
	{28, 27, 26, 25, 31, 32},
	{29, 30, 25, 31, 32, 20},
	{30, 25, 31, 32, 20, 21},
	{31, 32, 20, 21, 21, 21},
	{32, 20, 21, 21, 21, 21}
};

int Play() {
	int score = 0;
	memset(Pos, 0, sizeof(Pos));

	for (int i = 1; i <= 10; i++) {
		int m = Mal[i];
		int k = Kan[i];
		bool flag = false;

		if (Pos[m] == 21) return -1;

		int idx = 0;
		for (int j = 0; j < 14; j++) {
			if (Pos[m] == Rule[j][0]) {
				flag = true;
				idx = j;
				break;
			}
		}

		if (flag) {
			Pos[m] = Rule[idx][k];
		}
		else {
			Pos[m] += k;
			if (Pos[m] >= 21) Pos[m] = 21;
		}

		for (int j = 1; j <= 4; j++) {
			if (m != j && Pos[m] == Pos[j]) {
				if (Pos[m] == 21) continue;
				else return -1;
			}
		}
		score += Map[Pos[m]];
	}

	return score;
}

void Solve(int cnt) {
	if (cnt > 10) {
		int res = Play();
		Ans = max(Ans, res);
	}
	else {
		for (int i = 1; i <= 4; i++) {
			Mal[cnt] = i;
			Solve(cnt + 1);
		}
	}
}

int main() {
	for (int i = 1; i <= 10; i++) cin >> Kan[i];

	Solve(0);

	cout << Ans << endl;

	return 0;
}