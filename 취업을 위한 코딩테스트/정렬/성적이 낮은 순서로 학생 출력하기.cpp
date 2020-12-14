#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int N;
vector<pair<int, string>> Student;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int score;
		string name;

		cin >> name >> score;

		Student.push_back({ score, name });
	}

	sort(Student.begin(), Student.end());
	
	for (int i = 0; i < Student.size(); i++) cout << Student[i].second << " ";
	
	cout << endl;

	return 0;
}
