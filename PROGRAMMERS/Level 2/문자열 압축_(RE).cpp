#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = s.length();
    
    for(int len = 1; len <= s.length() / 2; len++) {
        string result = "";
        string tmp = s.substr(0, len);
        int cnt = 1;
        int i;
        
        for(i = len; i <= s.length(); i += len) {
            if(tmp == s.substr(i, len)) cnt += 1;
            else {
                if(cnt == 1) result += tmp;
                else {
                    result += to_string(cnt);
                    result += tmp;
                }
                tmp = s.substr(i, len);
                cnt = 1;
            }
        }
        
        if(i > s.length()) {
            if(cnt == 1) result += tmp;
            else {
                result += to_string(cnt);
                result += tmp;
            }
        }
        
        int retLen = result.length();
        answer = min(answer, retLen);
    }
    
    return answer;
}
