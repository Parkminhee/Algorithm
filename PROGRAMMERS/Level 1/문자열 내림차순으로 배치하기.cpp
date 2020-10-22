#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Cmp(char c1, char c2) {
    if(c1 > c2) return true;
    return false;
}

string solution(string s) {
    string answer = "";
    
    sort(s.begin(), s.end(), Cmp);
    
    answer = s;
    
    return answer;
}
