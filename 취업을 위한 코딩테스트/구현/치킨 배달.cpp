#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int Ans = 987654321;
int N, M;
int Map[51][51];
bool Check[51 * 51];
vector<pair<int, int>> Home;
vector<pair<int, int>> Store;

int FindDis() {
	int result = 0;
	vector<int> v;

	for (int i = 0; i < Home.size(); i++) {
		int dis = 987654321;
		int diff = 0;
		for (int j = 0; j < Store.size(); j++) {
			if (Check[j] == true) {
				diff = abs(Home[i].first - Store[j].first) + abs(Home[i].second - Store[j].second);
				dis = min(dis, diff);
			}
		}
		v.push_back(dis);
	}

	for (int i = 0; i < v.size(); i++) result += v[i];

	v.clear();

	return result;
}

void Select(int idx, int cnt) {
	if (cnt == M) {
		int ret = FindDis();
		Ans = min(Ans, ret);
	}
	else {
		for (int i = idx; i < Store.size(); i++) {
			if (Check[i] == false) {
				Check[i] = true;
				Select(i, cnt + 1);
				Check[i] = false;
			}
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> Map[i][j];

			if (Map[i][j] == 1) Home.push_back({ i, j });
			else if (Map[i][j] == 2) Store.push_back({ i, j });
		}
	}

	Select(0, 0);

	cout << Ans << endl;

	return 0;
}
