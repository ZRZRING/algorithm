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
	std::vector a(n, std::vector(m, int()));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> a[i][j];
		}
	}
	int flag = 1;
	while (flag) {
		flag = 0;
		for (int i = n - 2; i >= 1; i--) {
			for (int j = 1; j <= m - 2; j++) {
				int t = std::min({
					a[i][j + 1],
					a[i][j - 1],
					a[i + 1][j],
					a[i - 1][j],
				});
				if (t >= a[i][j]) {
					a[i][j]++;
					flag = 1;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cout << a[i][j] << ' ';
		}
		std::cout << '\n';
	}
}

int main() {
	init();
	while (T--) {
		solve();
	}
	return 0;
}