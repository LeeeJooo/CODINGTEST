#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int max_res = -1e9, min_res = 1e9;
int N;	// 피연산자 개수
int ops[4];		// idx:연산자종류(0:+  1:-  2:*  3:/)  value:개수
int nums[13];	// idx:순서  value:숫자
int res;	// 연산 결과
vector<int> path;	// idx:연산자 순서  value:연산자종류

void input();
void init();
void solution(int depth);
void calc();

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		// 입력
		input();

		// 풀이
		solution(0);

		// 출력
		cout << "#" << t << " " << max_res - min_res << "\n";

		// 초기화
		init();
	}
	return 0;
}

void input() {
	// 피연산자 개수
	cin >> N;

	// 연산자 개수
	int i;
	for (i = 0; i < 4; i++) {
		cin >> ops[i];
	}

	// 피연산자 입력
	for (i = 0; i < N; i++) cin >> nums[i];
}

void init() {
	// 최댓값, 최솟값 초기화
	max_res = -1e9;
	min_res = 1e9;

	// 연산자 개수 초기화
	for (int i = 0; i < 4; i++) ops[i] = 0;
}

void solution(int depth) {
	if (depth == N - 1) {
		calc();
		
		max_res = max(max_res, res);
		min_res = min(min_res, res);

		return;
	}

	int i;
	for (i = 0; i < 4; i++) {	// j:연산자종류
		if (!ops[i]) continue;	// PASS : 사용할 연산자가 없는 경우
		path.push_back(i);
		ops[i]--;	// 해당 연산자 사용
		solution(depth + 1);
		path.pop_back();
		ops[i]++;	// 복구
	}
}

void calc() {
	res = nums[0];
	for (int i = 0; i < N-1; i++) {
		if (path[i] == 0) res += nums[i + 1];	// 덧셈
		if (path[i] == 1) res -= nums[i + 1];	// 뺄셈
		if (path[i] == 2) res *= nums[i + 1];	// 곱셈
		if (path[i] == 3) res /= nums[i + 1];	// 나눗셈
	}
	return;
}