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
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	std::stable_sort(a.begin() + 1, a.end());
	std::swap(a[2], a[n]);
	long double ans = 0;
	for (int i = 1; i < n; i++) {
		ans += 1.0 * (a[i] + a[i + 1]) / 2.0;
	}
	std::cout << std::fixed << std::setprecision(2);
	std::cout << ans << '\n';
}

int main() {
	init();
	while (T--) {
		solve();
	}
	return 0;
}