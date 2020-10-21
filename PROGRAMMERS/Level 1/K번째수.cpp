#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> tmp;
    
    for(int c = 0; c < commands.size(); c++) {
        int i = commands[c][0] - 1;
        int j = commands[c][1];
        int k = commands[c][2];
        
        bool flag = false;
        for(int a = 0; a < array.size(); a++) {
            if(a == i) flag = true;
            else if(a == j) flag = false;
            
            if(flag) tmp.push_back(array[a]);
        }
        
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[k - 1]);
        
        tmp.clear();
    }
    
    return answer;
}
