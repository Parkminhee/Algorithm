#include <string>
#include <vector>
#include <stack>

using namespace std;

bool ValidString(string s) {
    stack<char> st;
    
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(') st.push(s[i]);
        else if(s[i] == ')') {
            if(st.empty()) return false;
            else st.pop();
        }
    }
    
    if(st.empty()) return true;
    else return false;
}

string Separate(string s) {
    string u = "", v = "", ans = "";
    if(s == "") return ans;
    
    int open = 0, close = 0, idx = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(') open += 1;
        else if(s[i] == ')') close += 1;
        
        idx += 1;
        
        if(open == close) break;
    }
    
    u += s.substr(0, idx);
    v += s.substr(idx);
    
    if(ValidString(u)) {
        ans += u;
        ans += Separate(v);
    }
    else {
        ans += '(';
        ans += Separate(v);
        ans += ')';
        
        u = u.substr(1, u.length() - 2);
        for(int i = 0; i < u.length(); i++) {
            if(u[i]== '(') ans += ')';
            else if(u[i] == ')') ans += '(';
        }
    }
    
    return ans;
}

string solution(string p) {
    string answer = "";
    
    if(ValidString(p)) return p;
    answer = Separate(p);
    
    return answer;
}
