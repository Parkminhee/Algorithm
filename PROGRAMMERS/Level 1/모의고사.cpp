#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int p1[5] = { 1, 2, 3, 4, 5 };
    int p2[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
    int p3[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    
    for(int i = 0; i < answers.size(); i++) {
        int idx1 = i % 5;
        int idx2 = i % 8;
        int idx3 = i % 10;
        
        if(answers[i] == p1[idx1]) count1++;
        if(answers[i] == p2[idx2]) count2++;
        if(answers[i] == p3[idx3]) count3++;
    }
    
    int maxScore = max(count1, max(count2, count3));
    
    if(count1 == maxScore) answer.push_back(1);
    if(count2 == maxScore) answer.push_back(2);
    if(count3 == maxScore) answer.push_back(3);
    
    return answer;
}
