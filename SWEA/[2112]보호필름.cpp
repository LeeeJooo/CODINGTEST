#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans = 1e9;	// ���� : �ּ� ���� Ƚ��
int D, W, K;	// �β�, ����, �հݱ���
bool MAP[14][21];	// idx:��ġ  value:���� ���� (0:A  1:B)
int cnt;	// �๰ ���� Ƚ��
vector<int> path;

void input();
void solution(int depth);
bool isValid();
void init();

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		// �Է�
		input();

		// ���
		solution(0);

		// ���
		if (ans == 1e9) ans = 0;
		cout << "#" << t << " " << ans << "\n";

		// �ʱ�ȭ
		init();
	}
	return 0;
}

void input() {
	// �β�, ����, �հݱ���
	cin >> D >> W >> K;

	// ��ȣ�ʸ� ���� �Է�
	int i, j;
	for (i = 0; i < D; i++) {
		for (j = 0; j < W; j++) {
			cin >> MAP[i][j];
		}
	}
}

void solution(int depth) {
	if (depth == D) {
		// Ÿ�缺 �˻�
		if (isValid()) ans = min(ans, cnt);
		return;
	}

	for (int i = -1; i <= 1; i++) {
		if ((i != -1) && (cnt + 1 > K)) continue;		// �๰ ���� Ƚ���� �հݱ��غ��� ���� ��� ����
		if ((i != -1) && (cnt + 1 == ans)) continue;	// �̹� ���� ���亸�� ���� Ƚ���� �ƴ� ���
		
		path.push_back(i);
		if (i != -1) cnt++;
		solution(depth + 1);
		if (i != -1) cnt--;
		path.pop_back();
	}
}

bool isValid() {
	int col, row;
	int cont, maxCont;	// ���� ���� Ƚ��, �ִ� ���� Ƚ��
	bool prev, now;	// ���� ���°�
	for (col = 0; col < W; col++) {
		cont = 1, maxCont = 1;
		prev = MAP[0][col];
		if (path[0] != -1) prev = path[0];	// ù��° �࿡ �๰�� ������ ���, �ش� �๰�� ���� ��ȯ

		// �� �� �˻�
		for (row = 1; row < D; row++) {
			now = MAP[row][col];
			if (path[row] != -1) now = path[row];	// row��° �࿡ �๰�� ������ ���, �ش� �๰�� ���� ��ȯ

			// ���ӵ� ���°��� ���
			if (now == prev) {
				cont++;	// ���� ���� Ƚ�� UPDATE
				continue;
			}

			// ���ӵ��� ���� ���°��� ���
			maxCont = max(maxCont, cont);	// �ִ� ���� Ƚ�� UPDATE
			prev = now;
			cont = 1;	// ���� ���� Ƚ�� �ʱ�ȭ
		}
		maxCont = max(maxCont, cont);	// �ִ� ���� Ƚ�� UPDATE

		// �ش� �� -> �հ� ���� �̴�
		if (maxCont < K) return false;
	}
	// ��� �� -> �հ� ���� ���
	return true;
}

void init() {
	ans = 1e9;
	cnt = 0;
}