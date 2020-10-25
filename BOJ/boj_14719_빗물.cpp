#include <iostream>
#include <algorithm>

using namespace std;

int Result;
int H, W;
int Arr[501];

int main() {
	cin >> H >> W;

	for (int i = 0; i < W; i++) cin >> Arr[i];

	for (int i = 1; i < W; i++) {
		int m1 = 0, m2 = 0;
		for (int j = i + 1; j < W; j++) {
			m1 = max(m1, Arr[j]);
		}
		for (int j = i - 1; j >= 0; j--) {
			m2 = max(m2, Arr[j]);
		}

		int m = min(m1, m2);

		if (Arr[i] >= m) continue;
		Result += m - Arr[i];
	}

	cout << Result << endl;

	return 0;
}
