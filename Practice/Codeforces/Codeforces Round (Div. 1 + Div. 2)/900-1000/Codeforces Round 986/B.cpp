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
	int64 n, b, c;
	std::cin >> n >> b >> c;
	if (b == 0) {
		if (c < n - 1) {
			std::cout << -1 << '\n';
			return;
		}
	}
	std::cout << n - (n - c) / b << '\n';
}

int main() {
	init();
	while (T--) {
		solve();
	}
	return 0;
}