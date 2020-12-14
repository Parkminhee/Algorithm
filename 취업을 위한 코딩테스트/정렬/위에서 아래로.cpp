#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> V;

bool MyCmp(int a, int b) {
	if (a > b) return true;
	return false;
}

int main() {
	cin >> N;

	int n = 0;
	for (int i = 0; i < N; i++) {
		cin >> n;
		V.push_back(n);
	}

	sort(V.begin(), V.end(), MyCmp);

	for (int i = 0; i < V.size(); i++) cout << V[i] << " ";

	cout << endl;

	return 0;
}
