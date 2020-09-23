#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int Ans;
int N;
int Building[1000];

void Init() {
	Ans = 0;
	memset(Building, 0, sizeof(Building));
}

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> Building[i];
	}
}

void Solve() {
	for (int i = 2; i < N - 1; i++) {
		int curHeight = Building[i];
		int leftMaxHeight = max(Building[i - 2], Building[i - 1]);
		int rightMaxHeight = max(Building[i + 1], Building[i + 2]);
		int maxHeight = max(leftMaxHeight, rightMaxHeight);

		if (curHeight > maxHeight) {
			Ans += curHeight - maxHeight;
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		Init();
		Input();
		Solve();

		cout << "#" << test_case << " " << Ans << endl;
	}
	return 0;
}
