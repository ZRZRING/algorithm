#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;
using A3 = std::array<int64, 3>;

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
	int64 n, m;
	std::cin >> n >> m;
	std::vector<A3> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i][0] >> a[i][1];
		a[i][2] = 0;
	}
	std::vector<A3> q(m + 1);
	for (int i = 1; i <= m; i++) {
		std::cin >> q[i][0] >> q[i][1] >> q[i][2];
	}
	auto cal = [](A3 a) -> int {
		if (a[0] < a[1]) {
			int len = a[1] - a[0];
			if (a[2] < len) {
				return a[0] + a[2];
			} else {
				return a[1] - (a[2] - len);
			}
		} else {
			int len = a[0] - a[1];
			if (a[2] < len) {
				return a[0] - a[2];
			} else {
				return a[1] + (a[2] - len);
			}
		}
	};
	for (int i = 1; i <= m; i++) {
		// for (auto x : q[i]) {
		// 	std::cout << x << ' ';
		// }
		// std::cout << '\n';
		int res = 0;
		for (int j = 1; j <= n; j++) {
			a[j][2] = q[i][2] % (2ll * abs(a[j][1] - a[j][0]));
			int pos = cal(a[j]);
			// std::cout << pos << ' ';
			if (q[i][0] <= pos && pos <= q[i][1]) {
				res++;
			}
		}
		std::cout << res << '\n';
	}
}

int main() {
	init();
	while (T--) {
		solve();
	}
	return 0;
}