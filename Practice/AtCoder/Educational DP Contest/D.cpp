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
		int n, W;
		std::cin >> n >> W;
		std::vector<int> weight(n + 1), value(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> weight[i] >> value[i];
		}
		std::vector f(n + 1, std::vector<int64>(W + 1));
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= W; j++) {
				if (j >= weight[i]) {
					f[i][j] = std::max(f[i - 1][j], f[i - 1][j - weight[i]] + value[i]);
				} else {
					f[i][j] = f[i - 1][j];
				}
			}
		}
		int64 ans = 0;
		for (int i = 0; i <= W; i++) {
			ans = std::max(ans, f[n][i]);
		}
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