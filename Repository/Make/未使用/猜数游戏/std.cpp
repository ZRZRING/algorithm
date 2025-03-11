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
		int n, m, q;
		std::cin >> n >> m >> q;
		std::vector f(n + 1, std::vector<int>(m + 1, m + 1));
		for (int i = 0; i <= m; i++) {
			f[1][i] = i;
		}
		for (int i = 2; i <= n; i++) {
			f[i][0] = 0;
			f[i][1] = 1;
			for (int j = 2; j <= m; j++) {
				for (int k = 1; k <= j; k++) {
					f[i][j] = std::min(f[i][j], std::max(f[i - 1][k - 1], f[i][j - k]) + 1);
				}
			}
		}
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				std::cout << f[j][i] << " \n"[j == n];
			}
		}
		std::cout << f[n][m] << '\n';
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