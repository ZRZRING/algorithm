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
	std::vector<int64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	int64 l = 1, r = 1e9;
	auto check = [&](int64 rd) -> bool {
		std::vector<int64> b = a;
		int64 sum = 0, d = 0;
		for (int i = 1; i <= n; i++) {
			b[i] = std::max(0ll, b[i] - rd);
			sum += b[i];
		}
		for (int i = 2; i <= n; i++) {
			int t = std::min(b[i - 1], b[i]);
			d += t;
			b[i - 1] -= t;
			b[i] -= t;
		}
		d = std::min(d, rd);
		return d * 2ll + (2ll * rd - d) >= sum;
	};
	while (l < r) {
		int64 mid = l + r >> 1;
		if (check(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	std::cout << r << '\n';
}

int main() {
	init();
	while (T--) {
		solve();
	}
	return 0;
}