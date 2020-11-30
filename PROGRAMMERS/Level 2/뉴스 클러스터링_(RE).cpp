#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int solution(string str1, string str2) {
    //int answer = 0;
    vector<string> v;
    map<string, int> a, b;
    
    for(int i = 0; i < str1.length() - 1; i++) {
        char c1 = tolower(str1[i]);
        char c2 = tolower(str1[i + 1]);
        string tmp = "";
        
        if(('a' <= c1 && c1 <= 'z') && ('a' <= c2 && c2 <= 'z')) {
            tmp += c1;
            tmp += c2;
        }
        if(tmp != "") {
            if(a[tmp] == 0) v.push_back(tmp);
            a[tmp] += 1;
        }
    }
    
    for(int i = 0; i < str2.length() - 1; i++) {
        char c1 = tolower(str2[i]);
        char c2 = tolower(str2[i + 1]);
        string tmp = "";
        
        if(('a' <= c1 && c1 <= 'z') && ('a' <= c2 && c2 <= 'z')) {
            tmp += c1;
            tmp += c2;
        }
        if(tmp != "") {
            if(a[tmp] == 0 && b[tmp] == 0) v.push_back(tmp);
            b[tmp] += 1;
        }
    }
    
    if(v.size() == 0) return 65536;
    
    int inter = 0;
    int uni = 0;
    
    for(int i = 0; i < v.size(); i++) {
        string s = v[i];
        inter = inter + min(a[s], b[s]);
        uni = uni + max(a[s], b[s]);
    }
    
    double answer = (double)inter / uni;
    answer = answer * 65536;
    
    return (int)answer;
}
