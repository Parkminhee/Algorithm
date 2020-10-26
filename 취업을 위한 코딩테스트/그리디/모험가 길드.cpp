#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int GroupCnt;
int N;
vector<int> V;

int main() {
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;

		V.push_back(x);
	}

	sort(V.begin(), V.end());

	int peopleCnt = 0;
	for (int i = 0; i < V.size(); i++) {
		peopleCnt += 1;

		if (V[i] <= peopleCnt) {
			GroupCnt += 1;
			peopleCnt = 0;
		}
	}

	cout << GroupCnt << endl;

	return 0;
}
