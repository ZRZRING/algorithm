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
		std::vector f(n + 1, std::vector<int>(m + 1));
		std::vector dp(n + 1, std::vector<A2>(m + 1));
		auto update = [&](A2 a, A2 b, int delta) -> void {
			auto [x1, y1] = a;
			auto [x2, y2] = b;
			if (f[x2][y2] + delta > f[x1][y1]) {
				f[x1][y1] = f[x2][y2] + delta;
				dp[x1][y1] = b;
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
				auto [x, y] = now;
				if (f[i][j] > f[x][y]) now = {i, j};
			}
		}
		std::string ans;
		// for (auto [x, y] : dp) {
		// 	std::cout << x[0] << ' ' << x[1] << ' ' << y[0] << ' ' << y[1] << '\n';
		// }
		while (now != (A2){0, 0}) {
			auto [x, y] = now;
			auto [x0, y0] = dp[x][y];
			if (f[x0][y0] + 1 == f[x][y]) ans.push_back(a[x]);
			now = dp[x][y];
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