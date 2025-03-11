#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

class WORK {
public:
	int N = 1e5;

	WORK() {}

	void solve() {
		int n, W;
		std::cin >> n >> W;
		std::vector<int> weight(n + 1), value(n + 1);
		for(int i = 1; i <= n; i++) {
			std::cin >> weight[i] >> value[i];
		}
		std::vector f(n + 1, std::vector<int64>(N + 1, 1e15));
		int64 sum = 0;
		f[0][0] = 0;
		for (int i = 1; i <= n; i++) {
			sum += value[i];
			for (int j = 0; j <= sum; j++) {
				if (j >= value[i]) {
					f[i][j] = std::min(f[i - 1][j], f[i - 1][j - value[i]] + weight[i]);
				} else {
					f[i][j] = f[i - 1][j];
				}
			}
		}
		int ans = 0;
		for (int i = 0; i <= sum; i++) {
			if (f[n][i] <= W) {
				ans = i;
			}
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