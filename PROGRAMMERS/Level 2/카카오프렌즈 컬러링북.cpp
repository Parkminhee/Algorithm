#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

bool Visited[101][101];

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int BFS(int m, int n, int i, int j, vector<vector<int>> picture) {
    queue<pair<int, int>> q;
    int cnt = 1;
    int num = picture[i][j];
    
    q.push({ i, j });
    Visited[i][j] = true;
    
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        
        for(int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            
            if(nr >= 0 && nc >= 0 && nr < m && nc < n) {
                if(Visited[nr][nc] == false && picture[nr][nc] == num) {
                    q.push({ nr, nc });
                    Visited[nr][nc] = true;
                    cnt += 1;
                }
            }
        }
    }
    
    return cnt;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    memset(Visited, false, sizeof(Visited));
    
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(picture[i][j] != 0 && Visited[i][j] == false) {
                int ret = BFS(m, n, i, j, picture);
                
                max_size_of_one_area = max(max_size_of_one_area, ret);
                number_of_area += 1;
            } 
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    
    return answer;
}
