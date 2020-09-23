#include<iostream>
#include<string>

using namespace std;

string str;
string findStr;
int Ans;

bool Check(int idx) {
	int findIdx = 0;
	for (int i = idx; i < idx + findStr.length(); i++) {
		if (findStr[findIdx] != str[i]) return false;
		findIdx++;
	}
	return true;
}

int main(int argc, char** argv)
{
	int tc = 0;
	for (int test_case = 1; test_case <= 10; ++test_case)
	{
		cin >> tc;
		cin >> findStr;
		cin >> str;

		for (int i = 0; i < str.length(); i++) {
			if (str[i] == findStr[0]) {
				if (Check(i)) {
					Ans += 1;
				}
			}
		}

		cout << "#" << test_case << " " << Ans << endl;

		findStr = "";
		str = "";
		Ans = 0;
	}
	return 0;
}
