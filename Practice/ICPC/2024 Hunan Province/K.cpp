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
		N = 2 * n + 1;
		std::vector e(N, std::vector<A2>());
		for (int i = 1; i <= m; i++) {
			int64 u, v, t;
			std::cin >> u >> v >> t;
			e[u].push_back({v, t});
			e[v].push_back({u, t});
			e[u + n].push_back({v + n, t});
			e[v + n].push_back({u + n, t});
			e[u].push_back({v + n, 0});
			e[v].push_back({u + n, 0});
		}
		for (int i = 1; i <= n; i++) {
			int64 t;
			std::cin >> t;
			e[0].push_back({i, t});
		}
		std::vector<int64> dis(N, 1e15), vis(N);
		std::priority_queue<A2, std::vector<A2>, std::greater<A2>> q;
		q.push({0, 0});
		dis[0] = 0;
		while (!q.empty()) {
			int u = q.top().at(1);
			q.pop();
			if (vis[u]) continue;
			vis[u] = 1;
			for (auto [v, t] : e[u]) {
				if (dis[u] + t < dis[v]) {
					dis[v] = dis[u] + t;
					q.push({dis[v], v});
				}
			}
		}
		int64 ans = 0;
		for (int i = 1; i <= n; i++) {
			ans = std::max(ans, std::min(dis[i], dis[i + n]));
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