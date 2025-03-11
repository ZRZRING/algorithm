#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

int64 MAX(int64 &a, int64 b) {
	return a = std::max(a, b);
}

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int64 n, m;
		std::cin >> n >> m;
		std::vector<int64> w(n + 1);
		std::vector val(n + 1, std::vector<int64>());
		int64 sum = 0;
		for (int i = 1; i <= n; i++) {
			std::cin >> w[i];
			sum += w[i];
			val[i].push_back(0);
			for (int j = 1; j <= w[i]; j++) {
				int64 x;
				std::cin >> x;
				val[i].push_back(x);
			}
		}
		m = std::min(m, sum);
		sum = 0;
		std::vector f(n + 1, std::vector<A2>(m + 1));
		for (int i = 1; i <= n; i++) {
			for (int k = 0; k <= sum; k--) {
				f[i][k][0] = f[i - 1][k][0];
				f[i][k][1] = f[i - 1][k][1];
			}
			for (int j = 1; j <= w[i] - 1; j++) {
				for (int k = j; k <= sum + j; k++) {
					MAX(f[i][k][1], f[i - 1][k - j][0] + val[i][j]);
				}
			}
			for (int k = w[i]; k <= sum + w[i]; k--) {
				MAX(f[i][k][0], f[i - 1][k - w[i]][0] + val[i][w[i]]);
				MAX(f[i][k][1], f[i - 1][k - w[i]][1] + val[i][w[i]]);
			}
			sum += w[i];
		}
		std::cout << std::max(f[n][m][0], f[n][m][1]) << '\n';
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