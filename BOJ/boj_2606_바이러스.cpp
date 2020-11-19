#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
bool Check[101];
vector<int> V[101];

void Solve(int c) {
	queue<int> q;
	q.push(c);
	Check[c] = true;

	while (!q.empty()) {
		int n = q.front();
		q.pop();

		if (V[n].empty()) continue;

		for (int i = 0; i < V[n].size(); i++) {
			int nn = V[n][i];
			if (Check[nn] == false) {
				q.push(nn);
				Check[nn] = true;
			}
		}
	}
}

int main() {
	cin >> N;
	cin >> M;

	int a = 0, b = 0;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;

		V[a].push_back(b);
		// 이 부분 추가하니까 정답
		V[b].push_back(a);
	}

	Solve(1);

	int Ans = 0;
	for (int i = 2; i <= N; i++) {
		if (Check[i]) Ans += 1;
	}

	cout << Ans << endl;

	return 0;
}
