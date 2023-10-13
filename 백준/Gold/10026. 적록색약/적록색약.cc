#include <iostream>
using namespace std;

int N;  // map 크기
char MAP[101][101];         // value: 비적록색약 정보
char MAP_RG[101][101];      // value: 적록색약 정보
int visited[101][101];      // value: 비적록색약 그룹 인식 정보
int visited_RG[101][101];   // value: 적록색약 그룹 인식 정보
int dy[4] = {-1,1,0,0}; // 상하좌우
int dx[4] = {0,0,-1,1};
int g[2] = {1,1};   // 그룹 개수

void input();
void group();
void dfs(int y, int x, int group, char map[101][101], int v[101][101]);

int main() {
    cin >> N;   // map 크기

    // 색 정보 입력
    input();

    // 그룹화
    group();

    // 출력
    cout << g[0]-1 << " " << g[1]-1;

    return 0;
}

void input() {
    int i, j;
    char color;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            cin >> color;
            // 비적록색약
            MAP[i][j] = color;

            // 적록색약
            if (color == 'G') MAP_RG[i][j] = 'R';
            else MAP_RG[i][j] = color;
        }
    }
}

void group() {
    int i,j;

    // 비적록색약 그룹화
    for (i=0; i<N; i++) {
        for (j=0;j<N;j++) {
            if (visited[i][j]) continue;    // PASS : 이미 그룹화한 경우
            dfs(i,j,g[0], MAP, visited);
            g[0]++;
        }
    }

    // 적록색약 그룹화
    for (i=0; i<N; i++) {
        for (j=0;j<N;j++) {
            if (visited_RG[i][j]) continue;    // PASS : 이미 그룹화한 경우
            dfs(i,j,g[1], MAP_RG, visited_RG);
            g[1]++;
        }
    }
}

void dfs(int y, int x, int group, char map[101][101], int v[101][101]) {
    // 상하좌우
    int y_, x_;
    for (int i=0; i<4; i++) {
        y_ = y + dy[i];
        x_ = x + dx[i];

        // PASS : MAP을 벗어난 경우
        if (y_<0 || y_>=N || x_<0 || x_>=N) continue;

        // PASS : 이미 그룹화한 경우
        if (v[y_][x_]) continue;

        // PASS : 색이 다른 경우
        if (map[y][x] != map[y_][x_]) continue;

        v[y_][x_] = group;
        dfs(y_,x_,group,map,v);
    }
}