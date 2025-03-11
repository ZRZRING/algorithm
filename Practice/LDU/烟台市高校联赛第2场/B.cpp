#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int m, n;
		std::cin >> m >> n;
		long double ans = 0;
		for (int i = 1; i <= m; i++) {
			ans += (powl(1.0 * i / m, n) - powl(1.0 * (i - 1) / m, n)) * i;
		}
		std::cout << std::fixed << std::setprecision(10);
		std::cout << ans << '\n';
	}
};

int main() {
	Fast_IOS;
	WORK work;
	int T = 1;
	// std::cin >> T;
	while (T--) {
		work.solve();
	}
	return 0;
}