#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans = 1e9;	// 정답
int N, M;	// 건물 수, 도로 수
struct Node {
	int to;		// 도착지
	int dist;	// 도로 길이
};
vector<Node> MAP[401];	// idx:출발지(from)  value:도착지,도로길이
int start;	// 출발점
bool visited[401];	// idx:건물번호  value:방문여부

void input();
void solution();
void dfs(int now, int dist);
void init();

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		// 입력
		input();

		// 풀이
		solution();

		// 출력
		cout << "#" << t << " " << ans << "\n";

		// 초기화
		init();
	}
	return 0;
}

void input() {
	// 건물 수, 도로 수 입력
	cin >> N >> M;

	// 도로 정보 입력
	int from, to, dist;
	for (int i = 0; i < M; i++) {
		cin >> from >> to >> dist;
		MAP[from].push_back({ to, dist });
	}
}

void solution() {
	for (start = 1; start <= N; start++) dfs(start, 0);
}

void dfs(int now, int dist) {	// now:출발지점  dist:이동거리
	// now 건물에서 갈 수 있는 모든 건물 탐색
	int next, added_dist;
	for (int i = 0; i < MAP[now].size(); i++) {
		next = MAP[now][i].to;	// 다음 도착지
		added_dist = MAP[now][i].dist;	// 다음 도착지로 갈 때 추가도 가야할 거리

		// PASS : 이미 방문한 경우
		if (visited[next]) continue;

		// PASS : 이미 구한 최소 거리보다 거리가 먼 경우
		if (dist + added_dist > ans) continue;

		// 싸이클을 돈 경우
		if (next == start) {
			ans = min(ans, dist + added_dist);
			return;
		}

		// 다음 건물로 이동
		visited[next] = true;
		dfs(next, dist + added_dist);
		visited[next] = false;
	}
}

void init() {
	// 정답 초기화
	ans = 1e9;

	// MAP 초기화
	int i, j;
	for (int i = 1; i <= N; i++) {
		while (MAP[i].size()) {
			MAP[i].pop_back();
		}
	}
}