// BOTTOM-UP
#include <iostream>
#include <queue>
using namespace std;

int N;  // 최종 무게
int weights[5001];  // idx:배달한무게  value:봉지개수

int main() {
    cin >> N;  // 최종 무게 입력

    // 3kg, 5kg 초기화
    weights[3] = 1;
    weights[5] = 1;

    /*
    << 메모리 초과 원인 >>
    각 무게를 한 번씩 검사하지 않고 나올 때마다 q에 추가하여 검사
    → continue로 목표 무게를 초과한 경우를 제외해도 중복 추가되는 무게가 많아서 메모리 초과 발생
    */
    queue<int> q;   // value:지금까지 배달한 무게
    q.push(3); q.push(5);
    int now;    // 지금까지 배달한 무게
    while(!q.empty()) {
        now = q.front(); q.pop();   // 지금까지 배달한 무게

        if (now+3>N) continue;  // PASS : 목표 배달 무게를 초과한 경우
        if(!weights[now+3]) weights[now+3] = weights[now]+1;
        else weights[now+3] = min(weights[now+3], weights[now]+1);
        q.push(now+3);

        if (now+5>N) continue;  // PASS : 목표 배달 무게를 초과한 경우
        if(!weights[now+5]) weights[now+5] = weights[now]+1;
        else weights[now+5] = min(weights[now+5], weights[now]+1);
        q.push(now+5);
    }

    if (!weights[N]) cout << -1;
    else cout << weights[N];

    return 0;
}