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
		if (n == 1) {
			std::cout << 0 << '\n';
			return;
		}
		std::vector e(n + 1, std::vector<int>());
		for (int i = 1; i < n; i++) {
			int u, v;
			std::cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		int64 ans = 0;
		std::vector f(n + 1, std::vector<A2>(4));
		std::vector<A2> G0(n + 1), G1(n + 1);
		std::vector<int64> g(n + 1);
		auto dfs1 = [&](auto self, int u, int last) -> void {
			for (auto v : e[u]) {
				if (v == last) continue;
				self(self, v, u);
				A2 t1 = {f[v][0][0] + a[v], v};
				for (int i = 0; i < 4; i++) {
					if (t1 < f[u][i]) continue;
					for (int j = 3; j > i; j--) {
						f[u][j] = f[u][j - 1];
					}
					f[u][i] = t1;
					break;
				}
				A2 t2 = {std::max(G0[v][0], g[v]), v};
				if (t2 >= G0[u]) {
					G1[u] = G0[u];
					G0[u] = t2;
				} else if (t2 >= G1[u]) {
					G1[u] = t2;
				}
			}
			g[u] = f[u][0][0] + f[u][1][0] + a[u];
		};
		dfs1(dfs1, 1, 1);
		// for (int i = 1; i <= n; i++) {
		// 	for (int j = 0; j < 4; j++) {
		// 		std::cout << f[i][j][0] << " \n"[j == 3];
		// 	}
		// }
		// for (int i = 1; i <= n; i++) {
		// 	for (int j = 0; j < 4; j++) {
		// 		std::cout << f[i][j][1] << " \n"[j == 3];
		// 	}
		// }
		// for (int i = 1; i <= n; i++) {
		// 	std::cout << G0[i][0] << ' ' << G1[i][0] << '\n';
		// }
		auto dfs2 = [&](auto self, int u, int last, int64 up, int64 upmax) -> void {
			std::vector<int64> b(5);
			for (int i = 0; i < 4; i++) {
				b[i] = f[u][i][0];
			}
			b[4] = up;
			std::sort(b.begin(), b.end(), std::greater<int64>());
			int64 res = 0;
			for (int i = 0; i < 4; i++) {
				res += b[i];
			}
			// std::cout << u << ' ' << res << ' ' << upmax << ' ' << g[u] << '\n';
			ans = std::max({ans, res, upmax + g[u]});
			for (auto v : e[u]) {
				if (v == last) continue;
				int64 t1 = up + a[u], t2 = upmax;
				if (v == f[u][0][1]) {
					t1 = std::max(t1, f[u][1][0] + a[u]);
					t2 = std::max(t2, f[u][1][0] + up + a[u]);
					t2 = std::max(t2, f[u][1][0] + f[u][2][0] + a[u]);
				} else if (v == f[u][1][1]) {
					t1 = std::max(t1, f[u][0][0] + a[u]);
					t2 = std::max(t2, f[u][0][0] + up + a[u]);
					t2 = std::max(t2, f[u][0][0] + f[u][2][0] + a[u]);
				} else {
					t1 = std::max(t1, f[u][0][0] + a[u]);
					t2 = std::max(t2, f[u][0][0] + up + a[u]);
					t2 = std::max(t2, f[u][0][0] + f[u][1][0] + a[u]);
				}
				if (v == G0[u][1]) {
					t2 = std::max(t2, G1[u][0]);
				} else {
					t2 = std::max(t2, G0[u][0]);
				}
				self(self, v, u, t1, t2);
			}
		};
		dfs2(dfs2, 1, 1, 0, 0);
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