#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int count = nums.size();
    int c = count / 2;
    
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    
    if(c <= nums.size()) answer = c;
    else if(c > nums.size()) answer = nums.size();
    
    
    return answer;
}
