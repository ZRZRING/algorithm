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
		int n, k, m = 0, ans1 = 0;
		std::cin >> n >> k;
		std::vector<A2> a;
		for (int i = 1; i <= n; i++) {
			int x, y;
			std::cin >> x >> y;
			if (y <= k) {
				m += k - y;
				ans1 += x;
			} else {
				a.push_back({x, y - k});
			}
		}
		std::vector<int64> f(m + 1);
		for (int i = 0; i < a.size(); i++) {
			for (int j = m; j >= a[i][1]; j--) {
				f[j] = std::max(f[j], f[j - a[i][1]] + a[i][0]);
			}
		}
		int64 ans2 = 0;
		for (int i = 0; i <= m; i++) {
			ans2 = std::max(ans2, f[i]);
		}
		std::cout << ans1 + ans2 << '\n';
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