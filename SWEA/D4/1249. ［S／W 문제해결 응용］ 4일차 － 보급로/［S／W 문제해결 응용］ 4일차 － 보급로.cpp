#include <iostream>
#include <string>
#include <queue>
using namespace std;

int N;	// 지도 크기
int MAP[100][100];	// idx:위치  value:높이
struct Node {
	int y, x;	// 위치
	int t;	// 복구 시간
	bool operator<(Node next) const {
		if (t > next.t) return true;
		return false;
	}
};
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int visited[100][100];	//idx:위치  value:복구시간

void input();
void init();
void solution();
bool isRange(Node next);

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		// 입력
		input();
		
		// 초기화
		init();

		// 풀이
		solution();

		// 출력
		cout << "#" << t << " " << visited[N - 1][N - 1] << "\n";
	}
	return 0;
}

void init() {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			visited[i][j] = 1e9;
		}
	}
}

void input() {
	// 지도 크기
	cin >> N;
	
	// 지도 정보
	int i, j;
	string info;
	for (i = 0; i < N; i++) {
		cin >> info;
		for (j = 0; j < N; j++) {
			MAP[i][j] = int(info[j]-'0');
		}
	}
}

void solution() {
	priority_queue<Node> pq;

	// 시작점 생성
	pq.push({ 0,0,0 });

	Node now, next;
	while (!pq.empty()) {
		now = pq.top(); pq.pop();

		// 상하좌우
		for (int i = 0; i < 4; i++) {
			next.y = now.y + dy[i];
			next.x = now.x + dx[i];
			if (!isRange(next)) continue;	// PASS : MAP을 벗어난 경우
			next.t = now.t + MAP[next.y][next.x];
			if (visited[next.y][next.x] <= next.t) continue;	// PASS : 굳이
			visited[next.y][next.x] = next.t;
			pq.push(next);
		}
	}
}

bool isRange(Node next) {
	if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= N) return false;
	return true;
}