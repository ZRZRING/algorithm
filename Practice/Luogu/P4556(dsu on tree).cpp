#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

struct cmp {
	bool operator () (A2 a, A2 b) const {
		return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
	}
};

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int n, m;
		std::cin >> n >> m;
		std::vector e(n + 1, std::vector<int>());
		std::vector fa(n + 1, std::vector<int>(30));
		std::vector<int> dep(n + 1), size(n + 1), son(n + 1), L(n + 1), R(n + 1), node(n + 1);
		for (int i = 1; i < n; i++) {
			int u, v;
			std::cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		int cnt = 0;
		auto dfs = [&](auto self, int u, int last) -> void {
			L[u] = ++cnt;
			node[cnt] = u;
			size[u] = 1;
			dep[u] = dep[last] + 1;
			for (int i = 1; i <= 20; i++) {
				if (!fa[u][i - 1]) break;
				fa[u][i] = fa[fa[u][i - 1]][i - 1];
			}
			for (auto v : e[u]) {
				if (v == fa[u][0]) continue;
				fa[v][0] = u;
				self(self, v, u);
				size[u] += size[v];
				if (size[v] > size[son[u]]) son[u] = v;
			}
			R[u] = cnt;
		};
		dfs(dfs, 1, 1);
		auto lca = [&](int x, int y) -> int {
			for (int i = dep[x] - dep[y], j = 0; i > 0; i >>= 1, j++) {
				if (i & 1) x = fa[x][j];
			}
			for (int i = dep[y] - dep[x], j = 0; i > 0; i >>= 1, j++) {
				if (i & 1) y = fa[y][j];
			}
			if (x != y) {
				for (int i = 20; i >= 0; i--) {
					if (fa[x][i] == fa[y][i]) continue;
					x = fa[x][i];
					y = fa[y][i];
				}
				x = fa[x][0];
			}
			return x;
		};
		std::vector mdf(n + 1, std::vector<A2>());
		for (int i = 1; i <= m; i++) {
			int x, y, z;
			std::cin >> x >> y >> z;
			int d = lca(x, y);
			// std::cout << d << '\n';
			mdf[x].push_back({z, 1});
			mdf[y].push_back({z, 1});
			mdf[d].push_back({z, -1});
			mdf[fa[d][0]].push_back({z, -1});
		}
		// for (int i = 1; i <= n; i++) {
		// 	std::cout << i << ": \n";
		// 	for (auto [x, y] : mdf[i]) {
		// 		std::cout << x << ' ' << y << '\n';
		// 	}
		// }
		std::vector<int> vis(1e5 + 1), ans(n + 1);
		std::set<A2, cmp> S;
		auto dfs1 = [&](auto self, int u, int last, int keep) -> void {
			for (auto v : e[u]) {
				if (v == last || v == son[u]) continue;
				self(self, v, u, 0);
			}
			// std::cout << u << " son: " << son[u] << '\n';
			if (son[u]) {
				self(self, son[u], u, 1);
			}
			for (auto v : e[u]) {
				if (v == last || v == son[u]) continue;
				for (int i = L[v]; i <= R[v]; i++) {
					for (auto [x, y] : mdf[node[i]]) {
						if (vis[x]) S.erase({vis[x], x});
						vis[x] += y;
						if (vis[x]) S.insert({vis[x], x});
					}
				}
			}
			for (auto [x, y] : mdf[u]) {
				if (vis[x]) S.erase({vis[x], x});
				vis[x] += y;
				if (vis[x]) S.insert({vis[x], x});
			}
			// std::cout << u << ' ' << S.size() << '\n';
			// for (int i = 1; i <= n; i++) {
			// 	std::cout << vis[i] << " \n"[i == n];
			// }
			if (!S.empty()) {
				ans[u] = S.begin()->at(1);
			}
			if (!keep) {
				for (int i = L[u]; i <= R[u]; i++) {
					for (auto [x, y] : mdf[node[i]]) {
						if (vis[x]) S.erase({vis[x], x});
						vis[x] -= y;
						if (vis[x]) S.insert({vis[x], x});
					}
				}
			}
		};
		dfs1(dfs1, 1, 1, 1);
		for (int i = 1; i <= n; i++) {
			std::cout << ans[i] << " \n";
		}
	}
};

int main() {
	// Fast_IOS;
	WORK work;
	int T = 1;
	// std::cin >> T;
	while (T--) {
		work.solve();
	}
	return 0;
}