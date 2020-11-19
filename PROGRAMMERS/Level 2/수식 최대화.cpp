// 참고 사이트 : https://eunchanee.tistory.com/88
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    vector<long long> num;
    vector<char> op;
    vector<char> idx;
    string str = "";
    
    for(int i = 0; i < expression.length(); i++) {
        if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
            num.push_back(stoi(str));
            str = "";
            
            if(find(op.begin(), op.end(), expression[i]) == op.end()) {
                op.push_back(expression[i]);
            }
            idx.push_back(expression[i]);
        }
        else {
            str += expression[i];
        }
    }
    
    num.push_back(stoi(str));
    // 정렬을 수행해야 next_permutation이 제대로 작동..?
    // 모든 permutation을 얻기 위해 정렬이 필요!!
    sort(op.begin(), op.end());
    
    do {
        vector<long long> tmp_num = num;
        vector<char> tmp_idx = idx;
        
        for(int i = 0; i < op.size(); i++) {
            for(int j = 0; j < tmp_idx.size(); j++) {
                if(op[i] == tmp_idx[j]) {
                    if(tmp_idx[j] == '+') {
                        tmp_num[j] = tmp_num[j] + tmp_num[j + 1];
                    }
                    else if(tmp_idx[j] == '-') {
                        tmp_num[j] = tmp_num[j] - tmp_num[j + 1];
                    }
                    else if(tmp_idx[j] == '*') {
                        tmp_num[j] = tmp_num[j] * tmp_num[j + 1];
                    }
                    
                    tmp_num.erase(tmp_num.begin() + j + 1);
                    tmp_idx.erase(tmp_idx.begin() + j);
                    j -= 1;
                }
            }
        }
        
        if(answer < abs(tmp_num[0])) answer = abs(tmp_num[0]);
    } while(next_permutation(op.begin(), op.end()));
    
    return answer;
}
