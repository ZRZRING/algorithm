#include <bits/stdc++.h>

using int64 = long long;
using A3 = std::array<int, 3>;

#define Fast_IOS \
	std::ios::sync_with_stdio(false), \
	std::cin.tie(0), \
	std::cout.tie(0)

const int64 mod = 998244353, inf = 1e9;

int N, T = 1;

void init() {
	// Fast_IOS;
	// std::cin >> T;
}

void solve() {
	int n;
	std::cin >> n;
	int S = 0, T = 2 * n + 1;
	std::vector e(T + 1, std::vector(0, A3()));
	auto add = [&](int u, int v) -> void {
		int t1 = e[u].size(), t2 = e[v].size();
		e[u].push_back({v, 1, t2});
		e[v].push_back({u, 0, t1});
	};
	for (int i = 1; i <= n; i++) {
		int k;
		std::cin >> k;
		for (int j = 0; j < k; j++) {
			int x;
			std::cin >> x;
			add(i, n + x);
		}
		add(S, i);
		add(n + i, T);
	}
	int F = 0;
	std::vector<int> dep(T + 1), cur(T + 1);
	auto bfs = [&](int u) -> int {
		std::fill(dep.begin(), dep.end(), 0);
		std::fill(cur.begin(), cur.end(), 0);
		std::queue<int> q;
		q.push(S);
		dep[S] = 1;
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (auto [v, t, id] : e[u]) {
				if (!t || dep[v]) continue;
				dep[v] = dep[u] + 1;
				q.push(v);
			}
		}
		return dep[T];
	};
	auto dfs = [&](auto self, int u, int limit) -> int {
		if (u == T) return limit;
		for (int i = cur[u]; i < e[u].size(); i++) {
			cur[u] = i + 1;
			auto [v, t, j] = e[u][i];
			if (!t || dep[v] != dep[u] + 1) continue;
			int flow = self(self, v, std::min(limit, t));
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
		// std::cout << 'q';
		int flow = 0;
		while (flow = dfs(dfs, S, inf)) {
			F += flow;
		}
		// F += dfs(dfs, S, inf);
	}
	if (F != n) {
		std::cout << "kou is angry" << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		for (auto [v, t, id] : e[i]) {
			if (t == 0) {
				std::cout << v - n << ' ';
				break;
			}
		}
	}
	std::cout << '\n';
}

int main() {
	init();
	while (T--) {
		solve();
	}
	return 0;
}