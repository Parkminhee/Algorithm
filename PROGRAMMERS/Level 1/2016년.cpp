#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string Day[7] = { "THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED" };
    int month[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int totalDay = 0;
    
    for(int i = 1; i < a; i++) totalDay += month[i];
    totalDay += b;
    
    int day = totalDay % 7;
    
    return Day[day];
}
