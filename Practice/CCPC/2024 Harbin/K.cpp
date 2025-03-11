#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;
using A3 = std::array<int64, 3>;

#define Fast_IOS \
	std::ios::sync_with_stdio(false), \
	std::cin.tie(0), \
	std::cout.tie(0)

const int64 mod = 998244353, inf = 1e12;

int N, T = 1;

void init() {
	// Fast_IOS;
	// std::cin >> T;
}

void solve() {
	int n;
	int64 m;
	std::cin >> n >> m;
	std::vector<A3> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	std::sort(a.rbegin(), a.rend() - 1);
	// for (auto [x, y, z] : a) {
	// 	std::cout << x << ' ' << y << ' ' << z << '\n';
	// }
	int64 min = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += a[i][1] * a[i][0];
		m -= a[i][1];
	}
	min = ans;
	ans += m * a[1][0];
	std::vector<int64> cost = {0, a[1][2] - a[1][1]};
	std::vector<int64> value = {0, a[1][0] * (a[1][2] - a[1][1])};
	for (int i = 2; i <= n; i++) {
		cost.push_back(inf);
		value.push_back(value.back() + a[i][0] * (a[i][2] - a[i][1]));
		// std::cout << "cost: ";
		// for (auto x : cost) {
		// 	std::cout << x << ' ';
		// }
		// std::cout << '\n';
		int p = std::upper_bound(cost.begin(), cost.end(), a[i][1] + m) - cost.begin() - 1;
		// std::cout << a[i][1] << ' ' << p << '\n';
		int64 temp = min - a[i][1] * a[i][0] + value[p] + a[p + 1][0] * (a[i][1] + m - cost[p]);
		// std::cout << temp << '\n';
		ans = std::max(ans, temp);
		cost.pop_back();
		cost.push_back(cost.back() + a[i][2] - a[i][1]);
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