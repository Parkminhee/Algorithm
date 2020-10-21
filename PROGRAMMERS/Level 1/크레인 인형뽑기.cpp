#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int N = board[0].size();
    stack<int> s;
    
    for(int i = 0; i < moves.size(); i++) {
        int col = moves[i] - 1;
        int num = 0;
        
        for(int j = 0; j < N; j++) {
            if(board[j][col] != 0) {
                num = board[j][col];
                board[j][col] = 0;
                break;
            }
        }
        
        if(num != 0) {
            if(!s.empty()) {
                int n = s.top();

                if(num == n) {
                    s.pop();
                    answer += 2;
                }
                else {
                    s.push(num);
                }
            }
            else {
                s.push(num);
            }
        }
    }
    
    return answer;
}
