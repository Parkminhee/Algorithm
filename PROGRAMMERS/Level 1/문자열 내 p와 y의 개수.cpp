#include <string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int pCnt = 0;
    int yCnt = 0;
    
    for(int i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
        
        if(s[i] == 'p') pCnt += 1;
        if(s[i] == 'y') yCnt += 1;
    }
    
    if((pCnt == 0 && yCnt == 0) || pCnt == yCnt) answer = true;
    else answer = false;
    

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}
