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
		std::vector<int64> a(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		std::vector f(n + 1, std::vector<int64>(n + 1, 0));
		for (int i = 1; i <= n; i++) {
			if (n % 2 == 1) f[i][i] = a[i];
			else f[i][i] = -a[i];
		}
		for (int len = 1; len < n; len++) {
			for (int l = 1; l + len <= n; l++) {
				int r = l + len;
				if ((n - len) % 2 == 1) f[l][r] = std::max(f[l + 1][r] + a[l], f[l][r - 1] + a[r]);
				else f[l][r] = std::min(f[l + 1][r] - a[l], f[l][r - 1] - a[r]);
			}
		}
		std::cout << f[1][n] << "\n";
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