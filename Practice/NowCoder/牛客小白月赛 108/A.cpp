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
	Fast_IOS;
	std::cin >> T;
}

void solve() {
	int x, y;
	std::cin >> x >> y;
	if (y == 0) {
		std::cout << 0 << '\n';
	} else if (x == 0) {
		std::cout << y * 2 - 1 << '\n';
	} else {
		std::cout << y / (x + 1) * 2 + (y % (x + 1) >= 1) + (y % (x + 1) >= 2) << '\n';
	}
}

int main() {
	init();
	while (T--) {
		solve();
	}
	return 0;
}