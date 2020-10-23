#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    string str = "";
    
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == ' ') {
            for(int j = 0; j < str.length(); j++) {
                if(j % 2 == 0) str[j] = toupper(str[j]);
                else str[j] = tolower(str[j]);
            }
            answer += str;
            answer += " ";
            str = "";
        }
        else str += s[i];
    }
    
    for(int i = 0; i < str.length(); i++) {
        if(i % 2 == 0) str[i] = toupper(str[i]);
        else str[i] = tolower(str[i]);
    }
    
    answer += str;
    
    return answer;
}
