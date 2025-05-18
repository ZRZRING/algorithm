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
		std::vector fa(n + 1, std::vector<int>(30));
		std::vector e(n + 1, std::vector<int>());
		for (int i = 1; i <= n; i++) {
			std::cin >> fa[i][0];
			e[fa[i][0]].push_back(i);
		}
		std::vector<int> dep(n + 1), size(n + 1), son(n + 1);
		std::vector<int> L(n + 1), R(n + 1), node;
		auto dfs = [&](auto self, int u) -> void {
			node.push_back(u);
			L[u] = node.size() - 1;
			size[u] = 1;
			dep[u] = dep[fa[u][0]] + 1;
			for (int i = 1; i <= 20; i++) {
				if (!fa[u][i - 1]) break;
				fa[u][i] = fa[fa[u][i - 1]][i - 1];
			}
			for (auto v : e[u]) {
				if (v == fa[u][0]) continue;
				fa[v][0] = u;
				self(self, v);
				size[u] += size[v];
				if (size[v] > size[son[u]]) son[u] = v;
			}
			R[u] = node.size() - 1;
		};
		dfs(dfs, 0);
		int Q;
		std::cin >> Q;
		auto anc = [&](int x, int k) -> int {
			for (int i = 20; i >= 0; i--) {
				if ((k >> i & 1)) x = fa[x][i];
			}
			return x;
		};
		std::vector qry(n + 1, std::vector<A2>());
		for (int i = 1; i <= Q; i++) {
			int v, k;
			std::cin >> v >> k;
			int u = anc(v, k);
			// std::cout << u << ' ' << v << ' ' << k << '\n';
			if (u) {
				qry[u].push_back({dep[v], i});
			}
		}
		std::vector<int> vis(n + 2), ans(Q + 1);
		auto dfs1 = [&](auto self, int u, int keep) -> void {
			for (auto v : e[u]) {
				if (v == son[u]) continue;
				self(self, v, 0);
			}
			if (son[u]) {
				self(self, son[u], 1);
			}
			for (auto v : e[u]) {
				if (v == son[u]) continue;
				for (int i = L[v]; i <= R[v]; i++) {
					int x = node[i];
					vis[dep[x]]++;
				}
			}
			vis[dep[u]]++;
			for (auto [x, i] : qry[u]) {
				ans[i] = vis[x] - 1;
			}
			if (!keep) {
				for (int i = L[u]; i <= R[u]; i++) {
					int x = node[i];
					vis[dep[x]]--;
				}
			}
		};
		dfs1(dfs1, 0, 1);
		for (int i = 1; i <= Q; i++) {
			std::cout << ans[i] << " \n"[i == Q];
		}
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