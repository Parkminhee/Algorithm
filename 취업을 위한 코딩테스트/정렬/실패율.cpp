#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Cmp(pair<double, int> p1, pair<double, int> p2) {
    if(p1.first >= p2.first) {
        if(p1.first == p2.first) {
            if(p1.second < p2.second) return true;
            return false;
        }
        return true;
    }
    return false;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int>> v;
    
    for(int i = 1; i <= N; i++) {
        int sum = 0;
        int people = 0;
        for(int j = 0; j < stages.size(); j++) {
            if(stages[j] == i) sum += 1;
            if(stages[j] >= i) people += 1;
        }
        
        if(sum == 0) v.push_back({ 0, i });
        else v.push_back({ (double)sum/people, i });
    }
    
    sort(v.begin(), v.end(), Cmp);
    
    for(int i = 0; i < v.size(); i++) answer.push_back(v[i].second);
    
    return answer;
}
