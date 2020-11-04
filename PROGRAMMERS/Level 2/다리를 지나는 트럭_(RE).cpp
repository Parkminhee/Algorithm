#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int sum = 0;
    queue<int> q;
    
    for(int i = 0; i < truck_weights.size(); i++) {
        int w = truck_weights[i];
        
        while(true) {
            if(q.empty()) {
                q.push(w);
                sum += w;
                answer += 1;
                break;
            }
            else if(q.size() == bridge_length) {
                sum -= q.front();
                q.pop();
            }
            else {
                if(sum + w > weight) {
                    q.push(0);
                    answer += 1;
                }
                else {
                    q.push(w);
                    sum += w;
                    answer += 1;
                    break;
                }
            }
        }
    }
    
    // 마지막 트럭은 이제 막 다리에 올라온 것이므로 bridge_length만큼 초를 더해줘야 함!
    return answer + bridge_length;
}
