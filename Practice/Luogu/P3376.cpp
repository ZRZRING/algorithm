#include <bits/stdc++.h>

using int64 = long long;
using A3 = std::array<int64, 3>;

#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353, inf = 1e15;

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int n, m, S, T;
		std::cin >> n >> m >> S >> T;
		std::vector e(n + 1, std::vector<A3>());
		for (int i = 1; i <= m; i++) {
			int u, v, t;
			std::cin >> u >> v >> t;
			int idu = e[u].size(), idv = e[v].size();
			e[u].push_back({v, t, idv});
			e[v].push_back({u, 0, idu});
		}
		int64 ans = 0;
		std::vector<int> dep(n + 1), cur(n + 1);
		auto bfs = [&](int S) -> bool {
			// dep.clear();
			// dep.resize(n + 1);
			// cur.clear();
			// cur.resize(n + 1);
			std::fill(dep.begin(), dep.end(), 0);
			std::fill(cur.begin(), cur.end(), 0);
			std::queue<int> q;
			q.push(S);
			dep[S] = 1;
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				for (auto [v, t, id] : e[u]) {
					if (dep[v] || !t) continue;
					dep[v] = dep[u] + 1;
					q.push(v);
				}
			}
			return dep[T];
		};
		auto dfs = [&](auto self, int u, int64 limit) -> int64 {
			// std::cout << u << '\n';
			if (u == T) return limit;
			for (int i = cur[u]; i < e[u].size(); i++) {
				cur[u] = i + 1;
				auto [v, t, j] = e[u][i];
				if (dep[v] != dep[u] + 1 || !t) continue;
				int64 flow = self(self, v, std::min(limit, t));
				if (flow) {
					e[u][i][1] -= flow;
					e[v][j][1] += flow;
					return flow;
				} else {
					dep[v] = 0;
				}
			}
			return 0;
		};
		while (bfs(S)) {
			ans += dfs(dfs, S, inf);
			// int64 flow;
			// while (flow = dfs(dfs, S, inf)) {
			// 	ans += flow;
			// }
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