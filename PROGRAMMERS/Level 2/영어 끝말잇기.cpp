#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string, int> m;
    int people = 0;
    int cnt = 1;
    bool flag = false;
    
    for(int i = 0; i < words.size(); i++) {
        people %= n;
        
        if(m[words[i]] == 1) {
            flag = true;
            answer.push_back(people + 1);
            answer.push_back(cnt);
            break;
        }
        if(i > 0) {
            if(words[i][0] != words[i - 1][words[i - 1].length() - 1]) {
                flag = true;
                answer.push_back(people + 1);
                answer.push_back(cnt);
                break;
            }
        }
        m[words[i]] += 1;
        people += 1;
        if((i + 1) % n == 0) cnt += 1;
    }
    
    if(!flag) {
        answer.push_back(0);
        answer.push_back(0);
    }
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다. 
    //cout << "Hello Cpp" << endl;

    return answer;
}
