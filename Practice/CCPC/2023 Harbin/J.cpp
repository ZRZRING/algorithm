#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'
#define lg(x) ((int)log10(x))
#define log(x) ((int)log2(x))
#define PII std::pair<int64, int64>
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0)
#define debug(x) std::cerr << "In Line " << __LINE__ << " the " << #x << " = " << x << '\n';

const int64 mod = 998244353;

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int> > e(n + 1);
	for (int i = 1; i <= m; i++) {
		int u, v;
		std::cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	std::vector<int> size(n + 1), sg(n + 1);
	auto dfs = [&](auto self, int u, int last) -> void {
		size[u] = 1;
		for (auto v : e[u]) {
			if (v == last) continue;
			self(self, v, u);
			size[u] += size[v];
		}
	};
	int all = 0;
	auto cal = [](int x) -> int {
		if (x == 0) return 0;
		return x % 2 == 0 ? 2 : 1;
	};
	for (int i = 1; i <= n; i++) {
		if (!size[i]) {
			dfs(dfs, i, i);
			sg[i] = cal(size[i]);
			all ^= sg[i];
		}
	}
	int ans = 0;
	auto SG_edge = [&](auto self, int u, int last, int m) -> void {
		for (auto v : e[u]) {
			if (v == last) continue;
			ans += !(bool)(all ^ cal(size[v]) ^ cal(m - size[v]));
			self(self, v, u, m);
		}
	};
	for (int i = 1; i <= n; i++) {
		if (!sg[i]) continue;
		all ^= sg[i];
		SG_edge(SG_edge, i, i, size[i]);
		all ^= sg[i];
	}
	auto SG_node = [&](auto self, int u, int last, int m) -> void {
		int x = all;
		for (auto v : e[u]) {
			if (v == last) continue;
			x ^= cal(size[v]);
			self(self, v, u, m);
		}
		x ^= cal(m - size[u]);
		ans += !(bool)x;
	};
	for (int i = 1; i <= n; i++) {
		if (!sg[i]) continue;
		all ^= sg[i];
		SG_node(SG_node, i, i, size[i]);
		all ^= sg[i];
	}
	std::cout << ans << endl;
}

int main() {
	Fast_IOS;
	int T = 1;
	// std::cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}