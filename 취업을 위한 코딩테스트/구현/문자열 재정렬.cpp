#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string S;
string Ans;

int main() {
	cin >> S;

	vector<int> n;
	vector<char> c;
	for (int i = 0; i < S.length(); i++) {
		if (isdigit(S[i])) n.push_back(S[i] - '0');
		else c.push_back(S[i]);
	}

	sort(n.begin(), n.end());
	sort(c.begin(), c.end());

	int sum = 0;
	for (int i = 0; i < c.size(); i++) Ans += c[i];
	for (int i = 0; i < n.size(); i++) sum += n[i];

	cout << Ans + to_string(sum) << endl;

	return 0;
}
