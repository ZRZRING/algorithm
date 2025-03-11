#include <bits/stdc++.h>

using int64 = long long;
using A3 = std::array<int, 3>;

#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353, inf = 1e9;

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int n, m;
		std::cin >> n >> m;
		std::vector<int> a(n + 1), b(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i] >> b[i];
		}
		std::vector e(n + m + 2, std::vector<A3>());
		auto add = [&](int u, int v, int t) -> void {
			int idu = e[u].size(), idv = e[v].size();
			e[u].push_back({v, t, idv});
			e[v].push_back({u, t, idu});
		};
		int cnt1 = 0, sum = 0;
		for (int i = 1; i <= m; i++) {
			int t, x, y;
			std::cin >> x >> y >> t;
			sum += t;
			if (x == 1 || y == 1) {
				cnt1 += t;
			}
			add(x, n + i, t);
			add(y, n + i, t);
			add(n + i, n + m + 1, t);
		}
		a[1] = std::min(a[1], cnt1 + b[1]);
		for (int i = 2; i <= n; i++) {
			a[i] = std::min(a[i], a[1] - 1);
		}
		for (int i = 1; i <= n; i++) {
			add(0, i, a[i] - b[i]);
			if (a[i] < b[i]) {
				std::cout << "NO" << '\n';
				return;
			}
		}
		int ans = 0;
		std::vector<int> dep(n + m + 2), cur(n + m + 2);
		auto bfs = [&](int S) -> bool {
			dep.clear();
			dep.resize(n + m + 2);
			cur.clear();
			cur.resize(n + m + 2);
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
			return dep[n + m + 1];
		};
		auto dfs = [&](auto self, int u, int limit) -> int {
			if (u == n + m + 1) return limit;
			for (int i = cur[u]; i < e[u].size(); i++) {
				cur[u] = i;
				auto [v, t, j] = e[u][i];
				if (dep[v] != dep[u] + 1 || !t) continue;
				int flow = self(self, v, std::min(limit, t));
				if (flow) {
					e[u][i][1] -= flow;
					e[v][j][1] += flow;
					return flow;
				}
			}
			return 0;
		};
		while (bfs(0)) {
			int flow;
			while (flow = dfs(dfs, 0, inf)) {
				ans += flow;
			}
		}
		std::cout << (ans == sum ? "YES" : "NO") << '\n';
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