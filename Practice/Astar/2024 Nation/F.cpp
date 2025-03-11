#include <bits/stdc++.h>

using int64 = long long;

const int64 mod = 998244353;

template<class T>
T MOD(T &x, int64 p = mod) {
	return x = (x % p + p) % p;
}

template<class T>
T MOD(T &&x, int64 p = mod) {
	return x = (x % p + p) % p;
}

int main() {
	int n, m, k;
	std::cin >> n >> m >> k;
	#define A2 std::array<int64, 2>
	std::vector e(n + 1, std::vector<A2>());
	for (int i = 1; i < n; i++) {
		int u, v, t;
		std::cin >> u >> v >> t;
		e[u].push_back({v, t});
		e[v].push_back({u, t});
	}
	std::vector<int> p(m + 1);
	for (int i = 1; i <= m; i++) {
		std::cin >> p[i];
	}
	std::vector<int> dep(n + 1);
	std::vector fa(n + 1, std::vector<int>(21));
	auto dfs1 = [&](auto self, int u, int last) -> void {
		dep[u] = dep[last] + 1;
		for (auto [v, t] : e[u]) {
			if (v == last) continue;
			self(self, v, u);
			fa[v][0] = u;
		}
	};
	dfs1(dfs1, 1, 1);
	for (int j = 1; j <= 20; j++) {
		for (int i = 1; i <= n; i++) {
			fa[i][j] = fa[fa[i][j - 1]][j - 1];
		}
	}
	auto lca = [&](int x, int y) -> int {
		if (dep[x] < dep[y]) std::swap(x, y);
		for (int i = 20; i >= 0; i--) {
			if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
		}
		// std::cout << x << ' ' << y << '\n';
		if (x == y) return x;
		for (int i = 20; i >= 0; i--) {
			if (fa[x][i] == fa[y][i]) continue;
			x = fa[x][i];
			y = fa[y][i];
		}
		return fa[x][0];
	};
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = i; j <= n; j++) {
	// 		std::cout << i << ' ' << j << ' ' << lca(i, j) << '\n';
	// 	}
	// }
	std::vector<int64> vis(n + 1);
	vis[p[1]]++;
	for (int i = 2; i <= m; i++) {
		int d = lca(p[i], p[i - 1]);
		vis[p[i]]++;
		vis[p[i - 1]]++;
		vis[d] -= 2;
	}
	int64 ans = 0;
	auto cal = [](int64 x, int64 y) -> int64 {
		return (x - x / 2) * y;
	};
	#define A3 std::array<int64, 3>
	std::priority_queue<A3> q;
	auto dfs2 = [&](auto self, int u, int last) -> void {
		for (auto [v, t] : e[u]) {
			if (v == last) continue;
			self(self, v, u);
			vis[u] += vis[v];
		}
		for (auto [v, t] : e[u]) {
			if (v == last) {
				q.push({cal(t, vis[u]), t, vis[u]});
				ans += t * vis[u];
			}
		}
	};
	dfs2(dfs2, 1, 1);
	if (q.empty()) {
		std::cout << ans << '\n';
		return 0;
	}
	for (int i = 1; i <= k; i++) {
		auto [x, y, z] = q.top();
		q.pop();
		if (x == 0) break;
		// std::cout << x << '\n';
		ans -= x;
		y /= 2;
		x = cal(y, z);
		q.push({x, y, z});
	}
	std::cout << ans << '\n';
}