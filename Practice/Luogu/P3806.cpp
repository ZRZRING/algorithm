#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS \
	std::ios::sync_with_stdio(false), \
	std::cin.tie(0), \
	std::cout.tie(0)

const int64 mod = 998244353;

int N = 1e7, T = 1;

void init() {
	// Fast_IOS;
	// std::cin >> T;
}

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector e(n + 1, std::vector<A2>());
	for (int i = 1; i < n; i++) {
		int u, v, t;
		std::cin >> u >> v >> t;
		e[u].push_back({v, t});
		e[v].push_back({u, t});
	}
	std::vector<int> query(m + 1), ans(m + 1);
	for (int i = 1; i <= m; i++) {
		std::cin >> query[i];
	}
	int SIZE = n;
	std::vector<int> f(N + 1), size(n + 1), vis(n + 1);
	auto get_root = [&](auto self, int u, int last) -> A2 {
		int son = 0;
		A2 res = {0, (int64)1e9};
		size[u] = 1;
		for (auto [v, t] : e[u]) {
			if (v == last || vis[v]) continue;
			A2 temp = self(self, v, u);
			if (temp[1] < res[1]) {
				res = temp;
			}
			size[u] += size[v];
			if (size[v] > size[son]) {
				son = v;
			}
		}
		A2 temp = {u, std::max(size[son], SIZE - size[u])};
		if (temp[1] < res[1]) {
			res = temp;
		}
		return res;
	};
	std::vector<int> dis;
	auto dfs = [&](auto self, int u, int last, int now) -> void {
		for (auto [v, t] : e[u]) {
			if (v == last || vis[v]) continue;
			dis.push_back(now + t);
			self(self, v, u, now + t);
		}
	};
	auto cal = [&](int u) -> void {
		std::vector<int> del;
		f[0] = 1;
		del.push_back(0);
		for (auto [v, t] : e[u]) {
			if (vis[v]) continue;
			dis.clear();
			dis.push_back(t);
			dfs(dfs, v, u, t);
			for (auto x : dis) {
				for (int i = 1; i <= m; i++) {
					if (query[i] >= x) {
						ans[i] |= (f[query[i] - x]);
					}
				}
			}
			for (auto x : dis) {
				if (x > N) continue;
				f[x] = 1;
				del.push_back(x);
			}
		}
		for (auto x : del) {
			f[x] = 0;
		}
	};
	auto divide = [&](auto self, int u) -> void {
		// std::cout << u << '\n';
		auto [root, t] = get_root(get_root, u, u);
		vis[root] = 1;
		cal(root);
		for (auto [v, t] : e[root]) {
			if (vis[v]) continue;
			SIZE = size[v];
			self(self, v);
		}
	};
	divide(divide, 1);
	for (int i = 1; i <= m; i++) {
		std::cout << (ans[i] ? "AYE" : "NAY") << '\n';
	}
}

int main() {
	init();
	while (T--) {
		solve();
	}
	return 0;
}