#include <string>
#include <cmath>
#include <vector>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    string str = "";
    vector<int> v;
    
    for(int i = 0; i < dartResult.length(); i++) {
        if(dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T') {
            int num = stoi(str);
            int cal = 0;
            if(dartResult[i] == 'S') {
                cal = pow(num, 1);
            }
            if(dartResult[i] == 'D') {
                cal = pow(num, 2);
            }
            if(dartResult[i] == 'T') {
                cal = pow(num, 3);
            }
            v.push_back(cal);
            str = "";
        }
        else if(dartResult[i] == '*' || dartResult[i] == '#') {
            if(dartResult[i] == '*') {
                if(v.size() == 1) v[0] *= 2;
                else if(v.size() == 2) {
                    v[0] *= 2;
                    v[1] *= 2;
                }
                else {
                    for(int j = v.size() - 1; j >= v.size() - 2; j--) {
                        v[j] *= 2;
                    }
                }
            }
            if(dartResult[i] == '#') {
                v[v.size() - 1] *= -1;
            }
        }
        else if(isdigit(dartResult[i])) {
            str += dartResult[i];
        }
    }
    
    for(int i = 0; i < v.size(); i++) answer += v[i];
    
    return answer;
}
