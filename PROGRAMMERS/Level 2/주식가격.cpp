#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for(int i = 0; i < prices.size(); i++) {
        int p = prices[i];
        int c = 0;
        for(int j = i + 1; j < prices.size(); j++) {
            if(p <= prices[j]) c += 1;
            else{
                c += 1;
                break;
            }
        }
        answer.push_back(c);
    }
    
    return answer;
}
