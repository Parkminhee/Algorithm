#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int MaxNum = -987654321;
int MinNum = 987654321;
int N;
int Op[4];
int OpCnt;
vector<int> Nums;
vector<int> Ops;

int Calc() {
	int idx = 0;
	int ret = Nums[idx];

	for (int i = 0; i < Ops.size(); i++) {
		idx += 1;

		if (Ops[i] == 0) {
			ret += Nums[idx];
		}
		else if (Ops[i] == 1) {
			ret -= Nums[idx];
		}
		else if (Ops[i] == 2) {
			ret *= Nums[idx];
		}
		else if (Ops[i] == 3) {
			bool flag = false;
			if (ret < 0) flag = true;

			ret = abs(ret);
			ret /= Nums[idx];

			if (flag) ret *= -1;
		}
	}

	return ret;
}

void Solve(int cnt) {
	if (cnt == OpCnt) {
		/*
		for (int i = 0; i < OpCnt; i++) {
			cout << Ops[i] << " ";
		}
		cout << endl;
		*/

		int result = Calc();
		MaxNum = max(result, MaxNum);
		MinNum = min(result, MinNum);
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (Op[i] != 0) {
				Ops.push_back(i);
				Op[i] -= 1;

				Solve(cnt + 1);

				Ops.pop_back();
				Op[i] += 1;
			}
		}
	}
}

int main() {
	cin >> N;

	int num = 0;
	for (int i = 0; i < N; i++) {
		cin >> num;
		Nums.push_back(num);
	}

	for (int i = 0; i < 4; i++) {
		cin >> Op[i];
		OpCnt += Op[i];
	}

	Solve(0);

	cout << MaxNum << endl;
	cout << MinNum << endl;

	return 0;
}
