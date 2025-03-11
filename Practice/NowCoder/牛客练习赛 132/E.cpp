#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;
using A3 = std::array<int64, 3>;

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

const int go[4][2] = {
	{0, 1},
	{1, 0},
	{0, -1},
	{-1, 0}
};

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector a(n + 2, std::vector(m + 2, int64()));
	std::vector b(n + 2, std::vector(m + 2, int64()));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cin >> a[i][j];
		}
	}
	if (n <= 2 || m <= 2) {
		int64 Sum = 0, Xor = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				Sum += a[i][j];
				Xor ^= a[i][j];
			}
		}
		std::cout << Sum << ' ' << Xor << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		b[i][1] = a[i][1];
		b[i][m] = a[i][m];
	}
	for (int i = 1; i <= m; i++) {
		b[1][i] = a[1][i];
		b[n][i] = a[n][i];
	}
	std::priority_queue<A3, std::vector<A3>, std::greater<A3>> q;
	auto push = [&](int x, int y) -> void {
		int64 min = 1e15;
		for (int i = 0; i < 4; i++) {
			int dx = x + go[i][0], dy = y + go[i][1];
			if (dx < 0 || dx > n || dy < 0 || dy > m) continue;
			if (!b[dx][dy]) continue;
			min = std::min(min, b[dx][dy]);
		}
		q.push({min, x, y});
	};
	for (int i = 2; i <= n - 1; i++) {
		push(i, 2);
		push(i, m - 1);
	}
	for (int i = 2; i <= m - 1; i++) {
		push(2, i);
		push(n - 1, i);
	}
	while (!q.empty()) {
		auto [d, x, y] = q.top();
		q.pop();
		if (b[x][y]) continue;
		b[x][y] = std::max(a[x][y], d + 1);
		for (int i = 0; i < 4; i++) {
			int dx = x + go[i][0], dy = y + go[i][1];
			push(dx, dy);
		}
	}
	int64 Sum = 0, Xor = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			Sum += b[i][j];
			Xor ^= b[i][j];
		}
	}
	std::cout << Sum << ' ' << Xor << '\n';
}

int main() {
	init();
	while (T--) {
		solve();
	}
	return 0;
}