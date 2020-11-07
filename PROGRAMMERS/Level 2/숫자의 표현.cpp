#include <string>
#include <vector>

using namespace std;

int answer;

void Calc(int i, int n) {
    int sum = 0;
    int idx = i;
    while(true) {
        if(sum == n) {
            answer += 1;
            break;
        }
        else if(sum > n) break;
        
        sum += idx;
        idx += 1;
    }
}

int solution(int n) {
    for(int i = 1; i <= n; i++) {
        Calc(i, n);
    }
    
    return answer;
}
