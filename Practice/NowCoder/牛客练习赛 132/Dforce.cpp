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
	int l, r;
	std::cin >> l >> r;
	int ans = 0;
	for (int a = l; a <= r; a++) {
		for (int b = a; b <= r; b++) {
			int flag = 0;
			for (int k = a; k <= b; k++) {
				if (sqrt(k) * sqrt(k) == k) flag = 1;
			}
			ans += flag;
		}
	}
	std::cout << 2 * ans << '\n';
}

int main() {
	init();
	while (T--) {
		solve();
	}
	return 0;
}