#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    for(int i = 1; i <= sqrt(n); i++) {
        if(pow(i, 2) == n) {
            answer = i;
            break;
        }
    }
    
    if(answer == 0) return -1;
    else return pow(answer + 1, 2);
    
    //return answer;
}
