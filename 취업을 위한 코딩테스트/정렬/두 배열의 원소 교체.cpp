#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
vector<int> A;
vector<int> B;

bool MyCmp(int a, int b) {
	if (a > b) return true;
	return false;
}

int main() {
	cin >> N >> K;

	int n = 0;
	for (int i = 0; i < N; i++) {
		cin >> n;
		A.push_back(n);
	}

	for (int i = 0; i < N; i++) {
		cin >> n;
		B.push_back(n);
	}

	// A 배열 : 오름차순 정렬
	sort(A.begin(), A.end());

	// B 배열 : 내림차순 정렬
	sort(B.begin(), B.end(), MyCmp);

	for (int i = 0; i < K; i++) {
		A[i] = B[i];
	}

	int sum = 0;
	for (int i = 0; i < A.size(); i++) sum += A[i];
	
	cout << sum << endl;

	return 0;
}
