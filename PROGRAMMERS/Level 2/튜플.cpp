#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Check[100001];

bool Cmp(pair<pair<int, int>, vector<int>> a, pair<pair<int, int>, vector<int>> b) {
    if(a.first.first <= b.first.first) {
        if(a.first.first == b.first.first) {
            if(a.first.second < b.first.second) {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<pair<pair<int, int>, vector<int>>> v;
    vector<int> tmp;
    
    string str = "";
    int idx = 0;
    bool flag = false;
    
    for(int i = 1; i < s.length() - 1; i++) {
        if(s[i] == '{') {
            flag = true;
        }
        if(s[i] == '}') {
            if(str.length() == 1) tmp.push_back(str[0] - '0');
            else tmp.push_back(stoi(str));
            
            v.push_back({ { tmp.size(), idx }, tmp });
            idx += 1;
            tmp.clear();
            str = "";
            flag = false;
        }
        else if(s[i] == ',' && flag == true) {
            if(str.length() == 1) tmp.push_back(str[0] - '0');
            else tmp.push_back(stoi(str));
            str = "";
        }
        else if(isdigit(s[i])) {
            str += s[i];
        }
    }
    
    sort(v.begin(), v.end(), Cmp);
    
    for(int i = 0; i < v.size(); i++) {
        vector<int> t = v[i].second;
        for(int j = 0; j < t.size(); j++) {
            if(Check[t[j]] == false) {
                answer.push_back(t[j]);
                Check[t[j]] = true;
            }
        }
    }
    
    return answer;
}
