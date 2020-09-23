#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int Ans;
int Dump;
int Box[100];

void Init() {
	memset(Box, 0, sizeof(Box));
}

void Input() {
	cin >> Dump;
	for (int i = 0; i < 100; i++) {
		cin >> Box[i];
	}
}

void Calc() {
	sort(Box, Box + 100);
	Ans = Box[99] - Box[0];
}

void Solve() {
	for (int i = 1; i <= Dump; i++) {
		sort(Box, Box + 100);
		Box[0] += 1;
		Box[99] -= 1;
	}

	Calc();
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
