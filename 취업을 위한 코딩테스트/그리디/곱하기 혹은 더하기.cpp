/* 내 코드
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int Answer = 1;
string S;
vector<int> V;

int main() {
	cin >> S;

	for (int i = 0; i < S.length(); i++) {
		int n = S[i] - '0';
		V.push_back(n);
	}

	for (int i = 0; i < V.size(); i++) {
		if (V[i] == 0) continue;
		Answer *= V[i];
	}

	cout << Answer << endl;

	return 0;
}
*/

#include <iostream>
#include <string>

using namespace std;

string S;

int main() {
	cin >> S;

	int Answer = S[0] - '0';

	for (int i = 1; i < S.length(); i++) {
		int n = S[i] - '0';

		if (n <= 1 || Answer <= 1) Answer += n;
		else Answer *= n;
	}

	cout << Answer << endl;

	return 0;
}
