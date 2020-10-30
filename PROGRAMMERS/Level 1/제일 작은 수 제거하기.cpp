#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    int minNum = arr[0], idx = 0;
    for(int i = 1; i < arr.size(); i++) {
        if(minNum > arr[i]) {
            minNum = arr[i];
            idx = i;
        }
    }
    
    // erase 사용법!!
    arr.erase(arr.begin() + idx);
    
    if(arr.empty()) answer.push_back(-1);
    else answer = arr;
    
    return answer;
}
