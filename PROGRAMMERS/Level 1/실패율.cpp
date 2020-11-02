#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Cmp(pair<double, int> a, pair<double, int> b) {
    if(a.first >= b.first) {
        if(a.first == b.first) {
            if(a.second < b.second) return true;
            else return false;
        }     
        return true;
    }
    return false;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int>> v;
    
    for(int i = 1; i <= N; i++) {
        int failCnt = 0;
        int totalCnt = 0;
        for(int j = 0; j < stages.size(); j++) {
            if(stages[j] == i) failCnt += 1;
            if(stages[j] >= i) totalCnt += 1;
        }
        if(failCnt == 0) v.push_back({ 0, i });
        else v.push_back({ (double)failCnt/totalCnt, i });
    }
    
    sort(v.begin(), v.end(), Cmp);
    
    for(int i = 0; i < v.size(); i++) answer.push_back(v[i].second);
    
    return answer;
}
