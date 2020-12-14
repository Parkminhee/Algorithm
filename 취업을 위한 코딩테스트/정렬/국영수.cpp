/* 시간초과 코드
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct Student {
	string name;
	int korean;
	int english;
	int math;
};

int N;
vector<Student> S;

bool NameCmp(string n1, string n2) {
	int idx = 0;

	while (true) {
		if (idx == n1.length() || idx == n2.length()) break;

		int c1 = n1[idx] - '0';
		int c2 = n2[idx] - '0';

		if (c1 < c2) return true;
		else if (c1 > c2) return false;

		idx += 1;
	}

	return true;
}

bool MyCmp(Student s1, Student s2) {
	if (s1.korean <= s2.korean) {
		if (s1.korean == s2.korean) {
			if (s1.english <= s2.english) {
				if (s1.english == s2.english) {
					if (s1.math <= s2.math) {
						if (s1.math == s2.math) {
							if (NameCmp(s1.name, s2.name)) {
								return true;
							}
							return false;
						}
						return false;
					}
					return true;
				}
				return true;
			}
			return false;
		}
		return false;
	}
	return true;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		string n;
		int a, b, c;

		cin >> n >> a >> b >> c;

		S.push_back({ n, a, b, c });
	}

	sort(S.begin(), S.end(), MyCmp);

	for (int i = 0; i < N; i++) {
		cout << S[i].name << endl;
	}

	return 0;
}
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct Student {
	string name;
	int korean;
	int english;
	int math;
};

int N;
vector<Student> S;

bool MyCmp(Student s1, Student s2) {
	if (s1.korean == s2.korean && s1.english == s2.english && s1.math == s2.math) return s1.name < s2.name;
	if (s1.korean == s2.korean && s1.english == s2.english) return s1.math > s2.math;
	if (s1.korean == s2.korean) return s1.english < s2.english;
	return s1.korean > s2.korean;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		string n;
		int ko, en, ma;

		cin >> n >> ko >> en >> ma;

		S.push_back({ n, ko, en, ma });
	}

	sort(S.begin(), S.end(), MyCmp);

	for (int i = 0; i < N; i++) {
		// endl 하면 시간초과
		// endl은 버퍼를 flush하는 역할을 겸하기 때문에
		// 이 문제처럼 많은 출력을 하는 경우에는
		// endl 사용을 지양하고 '\n'을 사용해야 함!
		cout << S[i].name << '\n';
	}

	return 0;
}
