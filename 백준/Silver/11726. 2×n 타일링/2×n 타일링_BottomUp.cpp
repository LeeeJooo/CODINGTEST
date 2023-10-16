// BOTTOM-UP
#include <iostream>
using namespace std;
int N;  // 가로 길이
int tiling[1001];   // idx:세로길이  value:타일개수

int main() {
    cin >> N;   // 가로 길이 입력

    // 2x1, 2x2 초기화
    tiling[1] = 1;
    tiling[2] = 2;

    // DP
    for (int i=3; i<=N; i++) {
        tiling[i]=(tiling[i-1]+tiling[i-2])%10007;
    }

    // 출력
    cout << tiling[N];

    return 0;
}