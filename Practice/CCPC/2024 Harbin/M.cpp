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
	int n;
	std::cin >> n;
	std::set<int> p;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			p.insert(i);
			p.insert(n / i);
		}
	}
	std::vector<int> a(0);
	for (auto x : p) {
		a.push_back(x);
	}
	int64 ans = 1;
	for (int i = 1; i < a.size(); i++) {
		ans += 1ll * (a[i] - a[i - 1]) * (n / a[i - 1]);
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