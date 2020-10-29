/*
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int Ans;
string S;

int main() {
	cin >> S;

	int zeroCnt = 0;
	int oneCnt = 0;

	// 모두 1로 만드는 경우
	if (S[0] == '0') oneCnt += 1;
	for (int i = 1; i < S.length(); i++) {
		if (S[i] != S[i - 1]) {
			if (S[i] == '0') oneCnt += 1;
		}
	}

	// 모두 0으로 만드는 경우
	if (S[0] == '1') zeroCnt += 1;
	for (int i = 1; i < S.length(); i++) {
		if (S[i] != S[i - 1]) {
			if (S[i] == '1') zeroCnt += 1;
		}
	}

	//cout << zeroCnt << ", " << oneCnt << endl;

	cout << min(zeroCnt, oneCnt) << endl;

	return 0;
}
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int Ans;
string S;

int main() {
	cin >> S;

	int zeroCnt = 0;
	int oneCnt = 0;

	if (S[0] == '0') oneCnt += 1;
	else if (S[0] == '1') zeroCnt += 1;

	for (int i = 1; i < S.length(); i++) {
		if (S[i] != S[i - 1]) {
			if (S[i] == '0') oneCnt += 1;
			else if (S[i] == '1') zeroCnt += 1;
		}
	}

	//cout << zeroCnt << ", " << oneCnt << endl;

	cout << min(zeroCnt, oneCnt) << endl;

	return 0;
}
