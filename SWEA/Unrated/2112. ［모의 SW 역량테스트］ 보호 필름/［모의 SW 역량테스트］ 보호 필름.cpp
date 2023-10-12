#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans = 1e9;	// 정답 : 최소 투입 횟수
int D, W, K;	// 두께, 가로, 합격기준
bool MAP[14][21];	// idx:위치  value:셀의 상태 (0:A  1:B)
int cnt;	// 약물 투여 횟수
vector<int> path;

void input();
void solution(int depth);
bool isValid();
void init();

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		// 입력
		input();

		// 계산
		solution(0);

		// 출력
		if (ans == 1e9) ans = 0;
		cout << "#" << t << " " << ans << "\n";

		// 초기화
		init();
	}
	return 0;
}

void input() {
	// 두께, 가로, 합격기준
	cin >> D >> W >> K;

	// 보호필름 상태 입력
	int i, j;
	for (i = 0; i < D; i++) {
		for (j = 0; j < W; j++) {
			cin >> MAP[i][j];
		}
	}
}

void solution(int depth) {
	if (depth == D) {
		// 타당성 검사
		if (isValid()) ans = min(ans, cnt);
		return;
	}

	for (int i = -1; i <= 1; i++) {
		if ((i != -1) && (cnt + 1 > K)) continue;		// 약물 투여 횟수가 합격기준보다 많은 경우 제외
		if ((i != -1) && (cnt + 1 == ans)) continue;	// 이미 구한 정답보다 적은 횟수가 아닌 경우
		
		path.push_back(i);
		if (i != -1) cnt++;
		solution(depth + 1);
		if (i != -1) cnt--;
		path.pop_back();
	}
}

bool isValid() {
	int col, row;
	int cont, maxCont;	// 현재 연속 횟수, 최대 연속 횟수
	bool prev, now;	// 이전 상태값
	for (col = 0; col < W; col++) {
		cont = 1, maxCont = 1;
		prev = MAP[0][col];
		if (path[0] != -1) prev = path[0];	// 첫번째 행에 약물을 투여한 경우, 해당 약물로 상태 변환

		// 열 별 검사
		for (row = 1; row < D; row++) {
			now = MAP[row][col];
			if (path[row] != -1) now = path[row];	// row번째 행에 약물을 투여한 경우, 해당 약물로 상태 변환

			// 연속된 상태값인 경우
			if (now == prev) {
				cont++;	// 현재 연속 횟수 UPDATE
				continue;
			}

			// 연속되지 않은 상태값인 경우
			maxCont = max(maxCont, cont);	// 최대 연속 횟수 UPDATE
			prev = now;
			cont = 1;	// 현재 연속 횟수 초기화
		}
		maxCont = max(maxCont, cont);	// 최대 연속 횟수 UPDATE

		// 해당 열 -> 합격 기준 미달
		if (maxCont < K) return false;
	}
	// 모든 열 -> 합격 기준 통과
	return true;
}

void init() {
	ans = 1e9;
	cnt = 0;
}