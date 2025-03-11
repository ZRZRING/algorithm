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
		int n, m, l, r;
		std::cin >> n >> m >> l >> r;
		N += n * m;
		if (n < m) std::swap(n, m);
		std::vector d(n + 1, std::vector<int>());
		for (int i = l; i <= r; i++) {
			for (int j = i; j <= n; j += i) {
				d[j].push_back(i);
			}
		}
		std::vector f(n + 1, std::vector<int>(m + 1));
		for (int i = 0; i <= n; i++) {
			f[i][0] = 1;
		}
		for (int i = 0; i <= m; i++) {
			f[0][i] = 1;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				for (auto x : d[i]) {
					if (x > j) break;
					f[i][j] |= f[i][j - x];
				}
				for (auto x : d[j]) {
					if (x > i) break;
					f[i][j] |= f[i - x][j];
				}
			}
		}
		std::cout << (f[n][m] ? "YES" : "NO") << '\n';
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
	std::cout << work.N << '\n';
	return 0;
}