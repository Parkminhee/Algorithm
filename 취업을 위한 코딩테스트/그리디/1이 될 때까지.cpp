#include <iostream>
//#include <ctime>

using namespace std;

int N, K;

int main() {
	//clock_t start, end;
	//double result;
	int count = 0;

	cin >> N >> K;

	//start = clock();

	while (true) {
		if (N == 1) break;

		if (N % K == 0) N /= K;
		else N -= 1;

		count += 1;
	}

	cout << count << endl;

	//end = clock();
	//result = (double)(end - start) / CLOCKS_PER_SEC;

	//cout << result << endl;

	return 0;
}
