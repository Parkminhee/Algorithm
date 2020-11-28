/*
#include <string>
#include <vector>

using namespace std;

struct ROBOT {
    int r1, r2, c1, c2;
    int dir;
    int time;
};

vector<vector<int>> Map;
ROBOT Robot;

void Move();

void Up() {
    int nr1 = Robot.r1 - 1, nc1 = Robot.c1;
    int nr2 = Robot.r2 - 1, nc2 = Robot.c2;
        
    if(Map[nr1][nc1] == 0 && Map[nr2][nc2] == 0) {
        Move();
        Robot.time += 1;
    }
}

void Down() {
    int nr1 = Robot.r1 + 1, nc1 = Robot.c1;
    int nr2 = Robot.r2 + 1, nc2 = Robot.c2;
        
    if(Map[nr1][nc1] == 0 && Map[nr2][nc2] == 0) {
        Move();
        Robot.time += 1;
    }
}

void Left() {
    int nr1 = Robot.r1, nc1 = Robot.c1 - 1;
    int nr2 = Robot.r2, nc2 = Robot.c2 - 1;
        
    if(Map[nr1][nc1] == 0 && Map[nr2][nc2] == 0) {
        Move();
        Robot.time += 1;
    }
}

void Right() {
    int nr1 = Robot.r1, nc1 = Robot.c1 + 1;
    int nr2 = Robot.r2, nc2 = Robot.c2 + 1;
        
    if(Map[nr1][nc1] == 0 && Map[nr2][nc2] == 0) {
        Move();
        Robot.time += 1;
    }
}

void Rotate() {
    if(Robot.dir == 0) {
        
    }
    else if(Robot.dir == 1) {
        
    }
}

void Move() {
    Up();
    Down();
    Left();
    Right();
    Rotate();
}

void Solve() {
    if((Robot.r1 == N - 1 && Robot.c1 == N - 1) || (Robot.r2 == N - 1 && Robot.c2 == N - 1)) {
        
    }
    else {
        Move();
    }
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[i].size(); j++) {
            Map[i][j] = board[i][j];
        }
    }
    
    Robot.r1 = 0, Robot.c1 = 0;
    Robot.r2 = 0, Robot.c1 = 1;
    Robot.dir = 0;  // 가로 방향
    
    Solve();
    
    return answer;
}
*/
