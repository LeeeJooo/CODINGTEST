// BOTTOM-UP
#include <iostream>
#include <algorithm>
using namespace std;

int N;  // 최종 무게
int weights[5001];  // idx:배달한무게  value:봉지개수

int main() {
    cin >> N;  // 최종 무게 입력

    // 3kg, 5kg 초기화
    weights[3] = 1;
    weights[5] = 1;

    int n =6;
    for (n=6; n<=N; n++) {
        // 5의 배수인 경우
        if (n%5==0) {
            weights[n] = weights[n-5]+1;
            continue;
        }

        // 3의 배수인 경우
        if (n%3==0) {
            weights[n] = weights[n-3]+1;
            continue;
        }

        // 그 외
        if (weights[n-3] && weights[n-5]) weights[n] = min(weights[n-3], weights[n-5])+1;
        else if (weights[n-3]) weights[n] = weights[n-3]+1;
        else if (weights[n-5]) weights[n] = weights[n-5]+1;
    }

    if (!weights[N]) cout << -1;
    else cout << weights[N];

    return 0;
}