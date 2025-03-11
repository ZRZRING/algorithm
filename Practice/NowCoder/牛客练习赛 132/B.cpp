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
	int64 n, m, k;
	std::cin >> n >> m >> k;
	std::set<int64> s;
	for (int i = 1; i <= n; i++) {
		int64 x;
		std::cin >> x;
		s.insert(x);
	}
	std::vector<int64> a;
	for (auto x : s) {
		a.push_back(x);
	}
	n = a.size();
	int64 ans = 0;
	for (int64 r = 0, l = 0; r < n; r++) {
		while ((a[r] - a[l] + 1) - (r - l + 1) > k) {
			l++;
		}
		ans = std::max(ans, std::min({m, r - l + 1 + k}));
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