#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

bool Visited[101][101];

int BFS(int r, int c, int m, int n, vector<vector<int>> p) {
    int count = 1;
    int color = p[r][c];
    queue<pair<int, int>> q;
    
    q.push({r, c});
    Visited[r][c] = true;
    
    while(!q.empty()) {
        int rr = q.front().first;
        int cc = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nr = rr + dr[i];
            int nc = cc + dc[i];
            
            if(nr >= 0 && nc >= 0 && nr < m && nc < n) {
                if(Visited[nr][nc] == false) {
                    if(p[nr][nc] == color) {
                        Visited[nr][nc] = true;
                        q.push({nr, nc});
                        count += 1;
                    }
                }
            }
        }
    }
    
    return count;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<int> answer(2);
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            Visited[i][j] = false;
        }
    }
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(Visited[i][j] == true) continue;
            if(picture[i][j] == 0) continue;
            
            int ret = BFS(i, j, m, n, picture);
            max_size_of_one_area = max(max_size_of_one_area, ret);
            number_of_area += 1;
        }
    }
    
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    
    return answer;
}
