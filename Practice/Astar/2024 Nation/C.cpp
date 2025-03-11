#include <bits/stdc++.h>

using int64 = long long;

#define A3 std::array<int, 3>

const int N = 1e3, go[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

int main() {
	int n, sx, sy, tx, ty;
	std::cin >> n >> sx >> sy >> tx >> ty;
	std::vector map(N + 2, std::vector<int>(N + 2));
	std::vector vis(N + 2, std::vector<int>(N + 2));
	std::vector f(N + 2, std::vector<int>(N + 2, 1e9));
	for (int i = 1; i <= n; i++) {
		int x, y;
		std::cin >> x >> y;
		map[x][y] = 1;
	}
	std::priority_queue<A3, std::vector<A3>, std::greater<A3>> q;
	f[sx][sy] = 0;
	q.push({0, sx, sy});
	while (!q.empty()) {
		auto [t, x, y] = q.top();
		q.pop();
		if (vis[x][y]) continue;
		vis[x][y] = 1;
		for (int i = 0; i < 4; i++) {
			int xx = x + go[i][0], yy = y + go[i][1];
			// std::cout << xx << ' ' << yy << '\n';
			if (xx < 0 || xx > N + 1 || yy < 0 || yy > N + 1) continue;
			if (vis[xx][yy]) continue;
			if (f[xx][yy] > f[x][y] + map[xx][yy]) {
				f[xx][yy] = f[x][y] + map[xx][yy];
				q.push({f[xx][yy], xx, yy});
			}
		}
	}
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= n; j++) {
	// 		std::cout << f[i][j] << ' ';
	// 	}
	// 	std::cout << '\n';
	// }
	std::cout << f[tx][ty] << '\n';
}