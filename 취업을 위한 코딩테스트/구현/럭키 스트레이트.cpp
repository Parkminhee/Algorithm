#include <iostream>
#include <string>

using namespace std;

int N;

int main() {
	cin >> N;

	string str = to_string(N);
	int mid = str.length() / 2;

	int front = 0, back = 0;
	for (int i = 0; i < str.length(); i++) {
		if (i < mid) front += str[i] - '0';
		else back += str[i] - '0';
	}

	if (front == back) cout << "LUCKY" << endl;
	else cout << "READY" << endl;


	return 0;
}
