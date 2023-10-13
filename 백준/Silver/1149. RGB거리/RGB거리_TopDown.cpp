// TOP-DOWN
#include <iostream>
#include <algorithm>
using namespace std;

int N;  // 집 개수
int costs[1001][3]; // idx1:집번호  idx2:색  value:특정집에 특정색을 칠할 때 드는 비용
int houses[1001][3];    // idx1:집번호  idx2:색  value:누적비용  <<< memoization

void memoization();
int DP(int ID, int color);

int main() {
    cin >> N;   // 집 개수 입력

    // 색칠 비용 입력
    int ID,color;
    for (ID=1; ID<=N; ID++) {  // ID:집 번호
        for (color=0; color<3; color++) {   //color:RGB
            cin >> costs[ID][color];
        }
    }

    // 풀이 : TOP-DOWN
    memoization();

    // 출력
    int ans = min(houses[N][0],houses[N][1]);
    ans = min(ans, houses[N][2]);
    cout << ans;
    return 0;
}

void memoization() {
    // 1번 집 누적 비용
    houses[1][0] = costs[1][0], houses[1][1] = costs[1][1], houses[1][2] = costs[1][2];

    for (int color = 0; color<3; color++) {
        houses[N][color] = DP(N, color);
    }
}

int DP(int ID, int color) {
    // 이미 값이 구해진 경우
    if (houses[ID][color]) return houses[ID][color];

    // 값을 구해야 하는 경우
    if (color==0) return houses[ID][color] = min(DP(ID-1, 1), DP(ID-1, 2)) + costs[ID][color];
    if (color==1) return houses[ID][color] = min(DP(ID-1, 0), DP(ID-1, 2)) + costs[ID][color];
    if (color==2) return houses[ID][color] = min(DP(ID-1, 0), DP(ID-1, 1)) + costs[ID][color];
    return 0;
}