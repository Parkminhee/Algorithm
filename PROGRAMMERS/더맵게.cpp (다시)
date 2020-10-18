/* 효율성 : 시간초과 코드
#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

bool Check(deque<int> d, int K) {
    for(int i = 0; i < d.size(); i++) {
        if(d[i] < K) return false;
    }
    return true;
}

int solution(vector<int> scoville, int K) {
    int answer = 0;
    deque<int> d;
    
    for(int i = 0; i < scoville.size(); i++) d.push_back(scoville[i]);
    
    while(true) {
        sort(d.begin(), d.end());
        
        if(d.size() == 1) break;
        if(d.size() > 1 && Check(d, K)) break;
        
        int idx1 = d[0];
        int idx2 = d[1];
        d.pop_front();
        d.pop_front();
        
        d.push_back(idx1 + (2 * idx2));
        answer += 1;
    }
    
    if(d[0] < K) answer = -1;
    
    return answer;
}
*/
