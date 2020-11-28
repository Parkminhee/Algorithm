/* 시간 초과
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool Check(map<string, vector<pair<string, bool>>> m) {
    for (auto it = m.begin(); it != m.end(); it++) {
        for (int i = 0; i < it->second.size(); i++) {
            if (it->second[i].second == false) return false;
        }
    }

    return true;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    map<string, vector<pair<string, bool>>> m;

    for (int i = 0; i < tickets.size(); i++) {
        m[tickets[i][0]].push_back({ tickets[i][1], false });
    }

    string start = "ICN";
    answer.push_back(start);

    sort(m[start].begin(), m[start].end());

    while (true) {
        if (Check(m)) break;

        for (int i = 0; i < m[start].size(); i++) {
            if (m[start][i].second == false) {
                answer.push_back(m[start][i].first);
                m[start][i].second = true;
                start = m[start][i].first;
                break;
            }
        }
    }

    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << " : ";
        for (int i = 0; i < it->second.size(); i++) {
            cout << it->second[i].first << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    return answer;
}
*/
