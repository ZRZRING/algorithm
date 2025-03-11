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
		std::string a, b;
		std::cin >> a >> b;
		int n = a.length(), m = b.length();
		a = " " + a;
		b = " " + b;
		std::map<A2, int> f;
		std::map<A2, A2> dp;
		auto update = [&](A2 a, A2 b, int delta) -> void {
			if (f[b] + delta > f[a]) {
				f[a] = f[b] + delta;
				dp[a] = b;
			}
		};
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				A2 x = {i, j};
				update(x, {i - 1, j}, 0);
				update(x, {i, j - 1}, 0);
				if (a[i] == b[j]) {
					update(x, {i - 1, j - 1}, 1);
				}
			}
		}
		A2 now = {0, 0};
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				A2 x = {i, j};
				if (f[x] > f[now]) now = x;
			}
		}
		std::string ans;
		// for (auto [x, y] : dp) {
		// 	std::cout << x[0] << ' ' << x[1] << ' ' << y[0] << ' ' << y[1] << '\n';
		// }
		while (dp.find(now) != dp.end()) {
			auto [x, y] = now;
			if (a[x] == b[y]) ans.push_back(a[x]);
			now = dp[now];
		}
		std::reverse(ans.begin(), ans.end());
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