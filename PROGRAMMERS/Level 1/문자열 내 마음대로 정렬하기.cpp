#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;

bool Cmp(string s1, string s2) {
    if(s1[N] <= s2[N]) {
        if(s1[N] == s2[N]) {
            if(s1 < s2) return true;
            return false;
        }
        return true;
    }
    return false;
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    N = n;
    
    sort(strings.begin(), strings.end(), Cmp);
    answer = strings;
    
    return answer;
}
