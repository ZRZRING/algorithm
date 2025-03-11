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
	int64 HR, VR, HS, VS;
	std::cin >> HR >> VR >> HS >> VS;
	int64 n;
	std::cin >> n;
	int64 ans = 1e15;
	for (int i = 1; i <= n; i++) {
		int64 hr, vr, hs, vs, cost;
		std::cin >> hr >> vr >> hs >> vs >> cost;
		ans = std::min(ans, cost *
			std::max((HS + hs - 1) / hs, (HR + hr - 1) / hr) *
			std::max((VS + vs - 1) / vs, (VR + vr - 1) / vr));
		std::swap(hr, vr);
		std::swap(hs, vs);
		ans = std::min(ans, cost *
			std::max((HS + hs - 1) / hs, (HR + hr - 1) / hr) *
			std::max((VS + vs - 1) / vs, (VR + vr - 1) / vr));
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