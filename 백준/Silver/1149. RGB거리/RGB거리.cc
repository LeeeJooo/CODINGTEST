// BOTTOM-UP
#include <iostream>
#include <algorithm>
using namespace std;

int N;  // 집 개수
int costs[1001][3]; // idx1:집번호  idx2:색  value:특정집에 특정색을 칠할 때 드는 비용
int houses[1001][3];    // idx1:집번호  idx2:색  value:누적비용  <<< tabulation

void tabulation();

int main() {
    cin >> N;   // 집 개수 입력

    // 색칠 비용 입력
    int ID,color;
    for (ID=1; ID<=N; ID++) {  // ID:집 번호
        for (color=0; color<3; color++) {   //color:RGB
            cin >> costs[ID][color];
        }
    }

    // 풀이 : BOTTOM-UP
    tabulation();

    // 출력
    int ans = min(houses[N][0],houses[N][1]);
    ans = min(ans, houses[N][2]);
    cout << ans;
    return 0;
}

void tabulation() {
    // 1번 집 누적비용
    houses[1][0] = costs[1][0], houses[1][1] = costs[1][1], houses[1][2] = costs[1][2];

    int ID;
    // N번 집까지 누적 비용 구하기
    for (ID=2; ID<=N; ID++) {
        houses[ID][0] = min(houses[ID-1][1], houses[ID-1][2])+costs[ID][0]; // ID번째 집에 빨간색을 칠했을 걍우
        houses[ID][1] = min(houses[ID-1][0], houses[ID-1][2])+costs[ID][1]; // ID번째 집에 빨간색을 칠했을 걍우
        houses[ID][2] = min(houses[ID-1][0], houses[ID-1][1])+costs[ID][2]; // ID번째 집에 빨간색을 칠했을 걍우
    }
}