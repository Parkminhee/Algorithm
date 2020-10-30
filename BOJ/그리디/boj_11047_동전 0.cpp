#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
int Ans;
vector<int> V;

int main() {
	cin >> N >> K;

	int a = 0;
	for (int i = 0; i < N; i++) {
		cin >> a;
		V.push_back(a);
	}

	// 내림차순 정렬
	sort(V.begin(), V.end(), greater<int>());

	for (int i = 0; i < V.size(); i++) {
		if (K / V[i] >= 1) {
			Ans += (K / V[i]);
			K %= V[i];
		}
	}

	cout << Ans << endl;

	return 0;
}
