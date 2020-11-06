#include <string>
#include <vector>

using namespace std;

int Bin(int n) {
    int cnt = 0;
    
    while(true) {
        if(n == 1) {
            cnt += 1;
            break;
        }
        if(n % 2 == 1) cnt += 1;
        n /= 2;
    }
    
    return cnt;
}

int solution(int n) {
    int answer = 0;
    int count = Bin(n);
    int num = n + 1;
    
    while(true) {
        int ret = Bin(num);
        
        if(ret == count) {
            answer = num;
            break;
        }
        num += 1;
    }
    
    return answer;
}
