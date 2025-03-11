#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS \
	std::ios::sync_with_stdio(false), \
	std::cin.tie(0), \
	std::cout.tie(0)

const int64 mod = 998244353;

int N, T = 1;

void init() {
	// Fast_IOS;
	// std::cin >> T;
}

const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

void solve() {
	int n;
	std::cin >> n;
	n *= 2;
	std::vector map(n + 1, std::string());
	for (int i = 1; i <= n; i++) {
		std::string s;
		std::cin >> s;
		map[i] = " " + s;
	}
	std::vector vis(n + 2, std::vector(n + 2, int()));
	for (int i = 0; i <= n + 1; i++) {
		vis[0][i] = 1;
		vis[i][0] = 1;
		vis[n + 1][i] = 1;
		vis[i][n + 1] = 1;
	}
	int start = 0;
	auto dfs = [&](auto self, int x, int y, int dir, int cnt) -> void {
		vis[x][y] = 1;
		int xx = x + dx[dir], yy = y + dy[dir];
		if (vis[xx][yy]) {
			dir++;
			if (dir == 4) return;
			xx = x + dx[dir];
			yy = y + dy[dir];
			if (map[x][y] == 'X' && map[xx][yy] == 'O' && !start) {
				start = cnt;
			}
			self(self, xx, yy, dir, cnt + 1);
		} else {
			if (map[x][y] == 'X' && map[xx][yy] == 'O' && !start) {
				start = cnt;
			}
			self(self, xx, yy, dir, cnt + 1);
		}
	};
	std::vector<int> ans(4);
	for (int i = 1; i <= n / 2; i++) {
		start = 0;
		dfs(dfs, i, i, 0, 1);
		int rn = n / 2 - i + 1, min = 1e9;
		// std::cout << start << '\n';
		for (int j = rn, k = 0; j <= 4 * (2 * rn - 1); j += 2 * rn - 1, k++) {
			// std::cout << i << ' ' << j << ' ' << k << '\n';
			if (j - start < 0) {
				ans[k] += j + 4 * (2 * rn - 1) - start;
			} else {
				ans[k] += j - start;
			}
		}
	}
	int min = 1e9;
	for (int i = 0; i < 4; i++) {
		min = std::min(min, ans[i]);
	}
	std::cout << min << '\n';
}

int main() {
	init();
	while (T--) {
		solve();
	}
	return 0;
}