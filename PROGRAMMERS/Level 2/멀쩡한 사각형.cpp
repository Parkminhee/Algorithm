using namespace std;

long long gcd(int w, int h) {
    while(h != 0) {
        long long r = w % h;
        w = h;
        h = r;
    }
    return w;
}

long long solution(int w,int h) {
    long long answer = 1;
    long long width = w;
    long long height = h;
    
    long long ret = gcd(w, h);
    
    answer = (width * height) - ((w + h) - ret);
    
    return answer;
}
