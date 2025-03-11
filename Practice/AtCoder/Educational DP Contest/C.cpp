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
		std::vector a(n + 1, std::vector<int>(3));
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i][0] >> a[i][1] >> a[i][2];
		}
		std::vector f(n + 1, std::vector<int>(3));
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					if (j == k) continue;
					f[i][j] = std::max(f[i][j], f[i - 1][k] + a[i][j]);
				}
			}
		}
		std::cout << std::max({f[n][0], f[n][1], f[n][2]}) << '\n';
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