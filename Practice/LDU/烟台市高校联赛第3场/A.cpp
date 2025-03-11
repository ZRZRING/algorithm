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
	// std::cin >> T;
}

void solve() {
	int64 n, Q;
	std::cin >> n >> Q;
	std::vector<int64> iota(n + 1);
	std::iota(iota.begin(), iota.end(), 0);
	int64 sum = std::accumulate(iota.begin(), iota.end(), 0ll);
	std::vector<int64> col(n + 1), row(n + 1);
	for (int i = 1; i <= n; i ++) {
		col[i] = 1ll * i * n + sum;
		row[i] = 1ll * i * n + sum;
	}
	int64 dcol = 0, drow = 0, ccol = 0, crow = 0;
	while (Q--) {
		int x;
		std::string s;
		std::cin >> s >> x;
		if (s[0] == 'R') {
			if (col[x] == 0) {
				std::cout << 0 << '\n';
			} else {
				std::cout << col[x] - dcol - ccol * x << '\n';
			}
			if (col[x]) {
				drow += x;
				crow ++;
				col[x] = 0;
			}
		} else {
			if (row[x] == 0) {
				std::cout << 0 << '\n';
			} else {
				std::cout << row[x] - drow - crow * x << '\n';
			}
			if (row[x]) {
				dcol += x;
				ccol ++;
				row[x] = 0;
			}
		}
	}
}

int main() {
	init();
	while (T--) {
		solve();
	}
	return 0;
}