#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> V;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int d;
		cin >> d;

		V.push_back(d);
	}

	sort(V.begin(), V.end());

	cout << V[(N - 1) / 2] << endl;

	return 0;
}
