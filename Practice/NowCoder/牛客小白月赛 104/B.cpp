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
	std::vector<double> p(5);
	for (int i = 0; i < 5; i++) {
		std::cin >> p[i];
	}
	double P = p[0] + p[1] + p[2];
	double ans = 1.0 - pow(P, 10) - 10.0 * pow(P, 9) * (1.0 - P);
	std::cout << std::fixed << std::setprecision(10);
	std::cout << ans << '\n';
}

int main() {
	init();
	while (T--) {
		solve();
	}
	return 0;
}