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
		std::vector<double> p(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> p[i];
		}
		std::vector f(n + 1, std::vector<double>(n + 1));
		f[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			f[i][0] = f[i - 1][0] * (1.0 - p[i]);
			f[i][i] = f[i - 1][i - 1] * p[i];
			for (int j = 1; j <= i - 1; j++) {
				f[i][j] = p[i] * f[i - 1][j - 1] + (1.0 - p[i]) * f[i - 1][j];
			}
		}
		double ans = 0;
		for (int i = (n + 1) / 2; i <= n; i++) {
			ans += f[n][i];
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