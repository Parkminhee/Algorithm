#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    string s1 = "수";
    string s2 = "박";
    
    for(int i = 1; i <= n; i++) {
        if(i % 2 == 0) answer += s2;
        else answer += s1;
    }
    
    return answer;
}
