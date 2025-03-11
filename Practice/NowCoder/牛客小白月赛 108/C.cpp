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
	int n;
	std::cin >> n;
	std::map<int, int> vis;
	for (int i = 1; i <= n; i++) {
		int x;
		std::cin >> x;
		vis[x]++;
	}
	int ans = 0;
	for (auto [x, y] : vis) {
		ans += (y % 2 == 0 ? 2 : 1);
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