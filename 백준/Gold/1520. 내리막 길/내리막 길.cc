#include <iostream>
using namespace std;


int board[500][500];
int H[500][500] = {};
int M, N;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int dfs(int, int);

int main(void) {
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			H[i][j] = -1;
		}
	}
	H[M - 1][N - 1] = 1;

	cout << dfs(0, 0);
	return 0;
}

int dfs(int y, int x) {

	if (H[y][x] >= 0)
		return H[y][x];

	H[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= M || nx < 0 || nx >= N)
			continue;

		if (board[ny][nx] < board[y][x])
			H[y][x] += dfs(ny, nx);
	}

	return H[y][x];
}