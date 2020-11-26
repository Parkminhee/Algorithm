#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, K, X;
vector<int> V[300001];
vector<int> Dis(300001, -1);

void Solve(int x) {
	queue<int> q;
	q.push(x);

	while (!q.empty()) {
		int y = q.front();
		q.pop();

		for (int i = 0; i < V[y].size(); i++) {
			int z = V[y][i];

			if (Dis[z] == -1) {
				Dis[z] = Dis[y] + 1;
				q.push(z);
			}
		}
	}
}

int main() {
	cin >> N >> M >> K >> X;

	int a = 0, b = 0;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;

		V[a].push_back(b);
	}

	Dis[X] = 0;
	Solve(X);

	bool flag = false;
	for (int i = 1; i <= N; i++) {
		if (Dis[i] == K) {
			cout << i << endl;
			flag = true;
		}
	}

	if (!flag) cout << -1 << endl;

	return 0;
}
