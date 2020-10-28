#include <iostream>
#include <string>

using namespace std;

string S;
string Answer;

int main() {
  // 입력 중간에 공백 존재하면 getline() 함수를 이용하기!
	getline(cin, S);

	bool flag = false;
	string str = "";

	for (int i = 0; i < S.length(); i++) {
		if (S[i] == '<') {
			if (str != "") {
				for (int j = str.length() - 1; j >= 0; j--) {
					Answer += str[j];
				}
				str = "";
			}

			Answer += S[i];
			flag = true;
		}
		else if (S[i] == '>') {
			Answer += S[i];
			flag = false;
		}
		else if (flag && S[i] == ' ') {
			Answer += " ";
		}
		else if (!flag && S[i] == ' ') {
			if (str != "") {
				for (int j = str.length() - 1; j >= 0; j--) {
					Answer += str[j];
				}
				str = "";
			}

			Answer += " ";
		}
		else if (flag) {
			Answer += S[i];
		}
		else if(!flag) {
			str += S[i];
		}
	}

	if (str != "") {
		for (int j = str.length() - 1; j >= 0; j--) {
			Answer += str[j];
		}
		str = "";
	}

	cout << Answer << endl;

	return 0;
}
