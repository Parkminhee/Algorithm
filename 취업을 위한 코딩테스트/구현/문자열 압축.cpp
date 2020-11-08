#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = s.length();

    for (int i = 1; i <= s.length() / 2; i++) {
        int cnt = 1;
        string str = s.substr(0, i);
        string ret = "";

        for (int j = i; j < s.length(); j += i) {
            string tmp = s.substr(j, i);

            if (tmp == str) {
                cnt += 1;
            }
            else {
                if (cnt == 1) {
                    ret += str;
                }
                else {
                    ret += to_string(cnt);
                    ret += str;
                }

                cnt = 1;
            }
            str = tmp;
        }

        if (cnt == 1) {
            ret += str;
        }
        else {
            ret += to_string(cnt);
            ret += str;
        }

        int len = ret.length();
        answer = min(len, answer);
    }

    return answer;
}
