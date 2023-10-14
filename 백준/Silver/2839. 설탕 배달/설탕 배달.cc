// TOP-DOWN
#include <iostream>
#include <algorithm>
using namespace std;

int N;  // 최종 무게
int weights[5001];  // idx:배달한무게  value:봉지개수

int Memoization(int now);

int main() {
    cin >> N;   // 최종 무게 입력

    // 3kg, 5kg 값
    weights[3] = 1;
    weights[5] = 1;

    // 풀이
    weights[N] = Memoization(N);

    // 출력
    if (!weights[N]) cout << -1;
    else cout << weights[N];

    return 0;
}

int Memoization(int now) {
    // 이미 구한 경우 >> 그 값을 반환
    if (weights[now]) return weights[now];

    // (now-3) / (now-5)kg을 옮기는 데 필요한 봉지 수, 옮길 수 없는 경우 0 이하
    int added_3 = 0, added_5 = 0;
    if (now-3>=3) added_3 = Memoization(now-3);
    if (now-5>=3) added_5 = Memoization(now-5);

    if (added_3>0 && added_5>0) return weights[now] = min(added_3, added_5) + 1;
    if (added_3>0) return weights[now] = added_3+1;
    if (added_5>0) return weights[now] = added_5+1;
    return -1;
}