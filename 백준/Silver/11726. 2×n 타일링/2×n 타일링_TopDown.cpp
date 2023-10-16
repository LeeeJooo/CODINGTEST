// TOP-DOWN
#include <iostream>
using namespace std;

int N;  // 가로 길이
int tiling[1001];   // idx:세로길이  value:타일개수

int DP(int n);

int main() {
    cin >> N;   // 가로 길이 입력
    
    // 2x1, 2x2 초기화
    tiling[1] = 1;
    tiling[2] = 2;

    // DP
    tiling[N] = DP(N);

    // 출력
    cout << tiling[N];

    return 0;
}

int DP(int n) {
    if (tiling[n]) return tiling[n];
    return tiling[n] = (DP(n-1) + DP(n-2))%10007;
}