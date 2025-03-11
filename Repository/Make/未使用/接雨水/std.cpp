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
		int n;
		std::cin >> n;
		std::vector<int64> a(n + 1), l(n + 1), r(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		int64 max = 0;
		for (int i = 1; i <= n; i++) {
			max = std::max(max, a[i]);
			l[i] = max;
		}
		max = 0;
		for (int i = n; i >= 1; i--) {
			max = std::max(max, a[i]);
			r[i] = max;
		}
		int64 ans = 0;
		for (int i = 1; i <= n; i++) {
			ans += std::min(l[i], r[i]) - a[i];
		}
		std::cout << ans << '\n';
	}
};

int main() {
	Fast_IOS;
	WORK work;
	int T = 1;
	std::cin >> T;
	while (T--) {
		work.solve();
	}
	return 0;
}