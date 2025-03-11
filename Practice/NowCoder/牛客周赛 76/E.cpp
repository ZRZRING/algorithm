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
	int64 n, k;
	std::cin >> n >> k;
	int64 c = powl(n, 1.0 / k), x = 1;
	for (int i = c - 3; i <= c + 3; i++) {
		if (i <= 0) continue;
		if (abs(n - powl(i, k)) < abs(n - powl(x, k))) {
			x = i;
		}
	}
	std::cout << x << '\n';
}

int main() {
	init();
	while (T--) {
		solve();
	}
	return 0;
}