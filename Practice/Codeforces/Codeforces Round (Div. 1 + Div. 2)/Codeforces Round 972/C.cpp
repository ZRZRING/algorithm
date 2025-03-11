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
		int n, m;
		std::cin >> n >> m;
		std::string P = "narek";
		std::vector f(n + 1, std::vector<int>(5, -1e9));
		std::vector g(n + 1, std::vector<int>(5));
		std::vector to(n + 1, std::vector<int>(5));
		for (int i = 1; i <= n; i++) {
			std::string s;
			std::cin >> s;
			for (int start = 0; start < 5; start++) {
				int now = start;
				for (int j = 0; j < m; j++) {
					int flag = 0;
					for (int k = 0; k < 5; k++) {
						if (s[j] == P[k]) flag = 1;
					}
					if (!flag) continue;
					g[i][start]--;
					if (s[j] == P[now]) {
						now = (now + 1) % 5;
						if (now == 0) {
							g[i][start] += 10;
						}
					}
				}
				to[i][start] = now;
			}
		}
		f[0][0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 5; j++) {
				f[i][j] = std::max(f[i][j], f[i - 1][j]);
				f[i][to[i][j]] = std::max(f[i][to[i][j]], f[i - 1][j] + g[i][j]);
			}
			// for (int j = 0; j < 5; j++) {
			// 	std::cout << f[i][j] << " \n"[j == 4];
			// }
		}
		int ans = 0;
		for (int i = 0; i < 5; i++) {
			ans = std::max(ans, f[n][i]);
		}
		std::cout << ans << '\n';
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