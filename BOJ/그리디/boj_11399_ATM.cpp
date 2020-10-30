#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int Ans;
int N;
vector<int> V;

int main() {
	cin >> N;

	int p = 0;
	for (int i = 0; i < N; i++) {
		cin >> p;
		V.push_back(p);
	}

	sort(V.begin(), V.end());

	int sum = 0;
	for (int i = 0; i < V.size(); i++) {
		Ans += V[i];
		sum += Ans;
	}

	cout << sum << endl;

	return 0;
}
