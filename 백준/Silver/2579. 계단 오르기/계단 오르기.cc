// BOTTOM-UP
#include <iostream>
#include <algorithm>
using namespace std;

int N;	// 계단 개수
int scores[301];	// idx:계단 번호  value:계단 점수
int scoreSum[301][2];	// idx1:계단 번호 idx2:연속횟수  value:점수합

int main() {
	cin >> N;	// 계단 개수 입력

	// 계단 점수 입력
	for (int i = 1; i <= N; i++) cin >> scores[i];

	// 첫번째 계단, 두번째 계단 점수 합 초기화
	scoreSum[1][1] = scores[1];
	scoreSum[2][1] = scores[2];
	scoreSum[2][2] = scores[1] + scores[2];

	// DP : BOTTOM-UP
	for (int i = 3; i <= N; i++) {
		scoreSum[i][1] = max(scoreSum[i - 2][1], scoreSum[i - 2][2]) + scores[i];
		scoreSum[i][2] = scoreSum[i - 1][1] + scores[i];
	}

	// 출력
	cout << max(scoreSum[N][1], scoreSum[N][2]);
	return 0;
}