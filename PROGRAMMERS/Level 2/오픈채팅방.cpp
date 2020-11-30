#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;
    vector<pair<string, string>> command;
    
    for(int i = 0; i < record.size(); i++) {
        int idx = 0;
        string str = "";
        string str1 = "";
        string str2 = "";
        for(int j = 0; j < record[i].length(); j++) {
            if(record[i][j] == ' ' && idx == 0) idx += 1;
            else if(record[i][j] == ' ' && idx == 1) idx += 1;
            
            if(idx == 0) str += record[i][j];
            else if(record[i][j] != ' ' && idx == 1) str1 += record[i][j];
            else if(record[i][j] != ' ' && idx == 2) str2 += record[i][j];
        }
        
        if(str != "Change") command.push_back({ str, str1 });
        if(str != "Leave") m[str1] = str2;
    }
    
    for(int i = 0; i < command.size(); i++) {
        string com = command[i].first;
        string uid = command[i].second;
        string ret = "";
        
        if(com == "Enter") {
            ret += m[uid];
            ret += "님이 들어왔습니다.";
        }
        else if(com == "Leave") {
            ret += m[uid];
            ret += "님이 나갔습니다.";
        }
        
        answer.push_back(ret);
    }
    
    return answer;
}
