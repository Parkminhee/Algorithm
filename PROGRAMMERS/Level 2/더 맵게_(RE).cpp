#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 0; i < scoville.size(); i++) pq.push(scoville[i]);
    
    while(pq.size() > 1 && pq.top() < K) {
        int n1 = pq.top();
        pq.pop();
        
        int n2 = pq.top();
        pq.pop();
        
        pq.push(n1 + (2 * n2));
        answer += 1;
    }
    
    if(pq.top() < K) answer = -1;
    
    return answer;
}
