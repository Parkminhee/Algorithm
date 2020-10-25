#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
vector<int> V;

int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		V.push_back(n);
	}

	sort(V.begin(), V.end());

	int first = V[N - 1];
	int second = V[N - 2];

	int count = int(M / (K + 1)) * K;
	count += M % (K + 1);

	int result = 0;
	result += count * first;
	result += (M - count) * second;

	cout << result << endl;

	return 0;
}
