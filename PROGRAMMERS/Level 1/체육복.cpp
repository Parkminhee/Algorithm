#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int student[31] = { 0, };
    
    for(int i = 1; i <= n; i++) student[i] = 1;
    for(int i = 0; i < lost.size(); i++) student[lost[i]] -= 1;
    for(int i = 0; i < reserve.size(); i++) student[reserve[i]] += 1;
    
    for(int i = 1; i <= n; i++) {
        if(student[i] == 0) {
            if(i - 1 >= 1) {
                if(student[i - 1] == 2) {
                    student[i - 1] -= 1;
                    student[i] += 1;
                }
            }
            if(i + 1 <= n) {
                if(student[i + 1] == 2) {
                    student[i + 1] -= 1;
                    student[i] += 1;
                }
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        if(student[i] >= 1) answer += 1;
    }
    
    return answer;
}
