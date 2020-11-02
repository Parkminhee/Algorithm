/*
#include <iostream>
#include <string>

using namespace std;

int N;
int Ans;

int main() {
	cin >> N;

	for (int i = 0; i <= N; i++) {
		string h = to_string(i);
		for (int j = 0; j < 60; j++) {
			string m = to_string(j);
			for (int k = 0; k < 60; k++) {
				string s = to_string(k);

				string time = h + m + s;
				for (int l = 0; l < time.length(); l++) {
					if (time[l] == '3') {
						Ans += 1;
						break;
					}
				}
			}
		}
	}

	cout << Ans << endl;

	return 0;
}
*/

#include <iostream>

using namespace std;

int N;
int Ans;

// 시, 분, 초 안에 '3'이 포함되어 있는지의 여부
bool Check(int h, int m, int s) {
	if (h % 10 == 3 || m / 10 == 3 || m % 10 == 3 || s / 10 == 3 || s % 10 == 3) return true;
	return false;
}

int main() {
	cin >> N;

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < 60; j++) {
			for (int k = 0; k < 60; k++) {
				if (Check(i, j, k)) Ans += 1;
			}
		}
	}

	cout << Ans << endl;

	return 0;
}
