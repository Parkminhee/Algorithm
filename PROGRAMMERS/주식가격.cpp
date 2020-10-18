#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for(int i = 0; i < prices.size(); i++) {
        int price = prices[i];
        int count = 0;
        
        for(int j = i + 1; j < prices.size(); j++) {
            if(price <= prices[j]) count += 1;
            else {
                count += 1;
                break;
            }
        }
        
        answer.push_back(count);
    }
    
    return answer;
}
