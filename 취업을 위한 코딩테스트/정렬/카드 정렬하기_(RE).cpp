#include <iostream>
#include <queue>

using namespace std;

int N;
int Arr[100001];

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) cin >> Arr[i];

	priority_queue<int> pq;
	for (int i = 0; i < N; i++) pq.push(-Arr[i]);

	int ans = 0;
	int cnt = 0;

	while (!pq.empty()) {
		if (cnt == N - 1) break;

		int n1 = -pq.top();
		pq.pop();
		int n2 = -pq.top();
		pq.pop();

		ans += (n1 + n2);
		pq.push(-(n1 + n2));
		cnt += 1;
	}

	cout << ans << endl;

	return 0;
}
