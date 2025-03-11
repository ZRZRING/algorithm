#include <bits/stdc++.h>

using int64 = long long;

#define A2 std::array<int, 2>

int main() {
	int n, m, S, T;
	std::cin >> n >> m >> S >> T;
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	a[S] = 0;
	a[T] = 0;
	std::vector<std::vector<A2>> e(n + 1);
	for (int i = 1; i <= m; i++) {
		int u, v, t;
		std::cin >> u >> v >> t;
		e[u].push_back({v, t});
		e[v].push_back({u, t});
	}
	std::vector<int> dis_S(n + 1, 1e9), dis_T(n + 1, 1e9);
	auto dij = [&](std::vector<int> &dis, int start) -> void {
		std::vector<int> vis(n + 1);
		std::priority_queue<A2, std::vector<A2>, std::greater<A2>> q;
		q.push({0, start});
		dis[start] = 0;
		while (!q.empty()) {
			int u = q.top()[1];
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
	};
	dij(dis_S, S);
	dij(dis_T, T);
	if (dis_S[T] == 1e9) {
		std::cout << "Impossible\n";
		return 0;
	}
	int ans1 = dis_S[T];
	std::vector<int> d(n + 1);
	std::vector<std::vector<int>> e2(n + 1);
	for (int u = 1; u <= n; u++) {
		for (auto [v, t] : e[u]) {
			if (dis_S[u] + dis_T[v] + t == ans1) {
				e2[u].push_back(v);
				d[v]++;
			}
		}
	}
	std::vector<int> f(n + 1, 1e9);
	std::queue<int> q;
	q.push(S);
	f[S] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		f[u] = std::max(f[u], a[u]);
		for (auto v : e2[u]) {
			f[v] = std::min(f[v], f[u]);
			d[v]--;
			if (!d[v]) q.push(v);
		}
	}
	int ans2 = f[T];
	std::cout << ans1 << ' ' << ans2 << '\n';
}
