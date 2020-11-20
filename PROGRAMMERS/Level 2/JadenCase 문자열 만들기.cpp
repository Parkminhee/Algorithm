#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    string str = "";
    
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == ' ') {
            if(!isdigit(str[0])) {
                str[0] = toupper(str[0]);
                for(int j = 1; j < str.length(); j++) str[j] = tolower(str[j]);
            }
            
            answer += str;
            answer += " ";
            str = "";
        }
        else {
            str += s[i];
        }
    }
    
    if(!isdigit(str[0])) {
        str[0] = toupper(str[0]);
        for(int j = 1; j < str.length(); j++) str[j] = tolower(str[j]);
    }
    answer += str;
    
    return answer;
}
