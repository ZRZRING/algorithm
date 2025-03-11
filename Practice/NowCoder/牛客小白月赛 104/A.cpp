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
	int a, b;
	std::cin >> a >> b;
	int ans = a + b;
	int c;
	std::cin >> c;
	int coin;
	std::cin >> coin;
	coin += c;
	for (int i = 1; i <= n; i++) {
		std::cin >> a >> b >> c;
		if (c <= coin) {
			ans = std::max(ans, a + b);
		}
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