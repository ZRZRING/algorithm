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

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector a(n + 1, std::vector(m + 1, int(-1e9)));
	std::vector f(n + 2, std::vector(m + 1, int(-1e9)));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cin >> a[i][j];
		}
	}
	f[n + 1][(m + 1) / 2] = 0;
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= m; j++) {
			if (j - 1 >= 1) {
				f[i][j] = std::max(f[i][j], f[i + 1][j - 1] + a[i][j]);
			}
			if (j + 1 <= m) {
				f[i][j] = std::max(f[i][j], f[i + 1][j + 1] + a[i][j]);
			}
			f[i][j] = std::max(f[i][j], f[i + 1][j] + a[i][j]);
		}
	}
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		ans = std::max(ans, f[1][i]);
	}
	std::cout << ans << '\n';
}

int main() {
	init();
	while (T--) {
		solve();
	}
	return 0;
}