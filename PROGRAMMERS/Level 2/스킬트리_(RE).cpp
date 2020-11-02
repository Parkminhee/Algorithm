#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map<char, int> m;
    
    for(int i = 0; i < skill.length(); i++) m[skill[i]] = i + 1;
    
    for(int i = 0; i < skill_trees.size(); i++) {
        int cnt = 1;
        bool flag = true;
        for(int j = 0; j < skill_trees[i].length(); j++) {
            if(m[skill_trees[i][j]] > cnt) {
                flag = false;
                break;
            }
            else if(m[skill_trees[i][j]] == cnt) cnt += 1;
        }
        if(flag) answer += 1;
    }
    
    return answer;
}
