#include <string>
#include <vector>

using namespace std;

int CountZero(string s) {
    int cnt = 0;
    
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '0') cnt += 1;
    }
    
    return cnt;
}

string Calc(int c) {
    vector<int> v;
    string result = "";
    
    while(true) {
        if(c == 1) {
            v.push_back(c);
            break;
        }
        int n = c % 2;
        int m = c / 2;
        
        v.push_back(n);
        
        c = m;
    }
    
    for(int i = v.size() - 1; i >= 0; i--) {
        result += to_string(v[i]);
    }
    
    return result;
}

vector<int> solution(string s) {
    vector<int> answer;
    int ans = 0;
    int cnt = 0;
    
    while(true) {
        if(s == "1") break;
        
        int zeroCnt = CountZero(s);
        int c = s.length() - zeroCnt;
        
        ans += zeroCnt;
        cnt += 1;
        
        string ret = Calc(c);
        s = ret;
    }
    
    answer.push_back(cnt);
    answer.push_back(ans);
    
    return answer;
}
