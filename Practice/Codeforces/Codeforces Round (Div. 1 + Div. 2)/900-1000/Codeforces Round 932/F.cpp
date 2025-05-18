#include <bits/stdc++.h>

using int64 = long long;

#define NO 2
#define YES 1
#define endl '\n'
#define lg(x) ((int)log10(x))
#define log(x) ((int)log2(x))
#define PII std::pair<int64, int64>
#define abs(x) ((x) < 0 ? -(x) : (x))
#define MOD(x) ((x) = ((x) % mod + mod) % mod)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0)
#define debug(x) std::cerr << "In Line " << __LINE__ << " the " << #x << " = " << x << '\n';

const int64 mod = 998244353;

struct DSU {
	int group;

	std::vector<int> fa, size;

	DSU(int n) : group(n) {
		fa.resize(n);
		size.resize(n);
		std::iota(fa.begin(), fa.end(), 0);
	}

	int find(int x) {
		return fa[x] == x ? x : fa[x] = find(fa[x]);
	}

	int merge(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return 0;
		group--;
		if (size[x] < size[y]) std::swap(x, y);
		fa[y] = x;
		size[x] += size[y];
		return 1;
	}
};

int solve() {
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> e(n + 1);
	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	std::vector<int> max(n + 1), min(n + 1);
	std::vector<int> in(n + 1), out(n + 1);
	std::vector<int> ord(1);
	auto dfs1 = [&](auto self, int u, int last) -> void {
		min[u] = max[u] = u;
		in[u] = ord.size();
		ord.push_back(u);
		for (auto v : e[u]) {
			if (v == last) continue;
			self(self, v, u);
			max[u] = std::max(max[u], max[v]);
			min[u] = std::min(min[u], min[v]);
		}
		out[u] = ord.size() - 1;
	};
	dfs1(dfs1, 1, 0);
	std::vector<int> premax(n + 2, 0), premin(n + 2, n);
	std::vector<int> sufmax(n + 2, 0), sufmin(n + 2, n);
	for (int i = 1; i <= n; i++) {
		premax[i] = std::max(premax[i - 1], ord[i]);
		premin[i] = std::min(premin[i - 1], ord[i]);
	}
	for (int i = n; i >= 1; i--) {
		sufmax[i] = std::max(sufmax[i + 1], ord[i]);
		sufmin[i] = std::min(sufmin[i + 1], ord[i]);
	}
	std::vector<int> max_up(n + 1), min_up(n + 1);
	for (int i = 1; i <= n; i++) {
		int u = ord[i];
		max_up[u] = std::max(premax[in[u] - 1], sufmax[out[u] + 1]);
		min_up[u] = std::min(premin[in[u] - 1], sufmin[out[u] + 1]);
	}
	std::vector<int> val(n + 1);
	std::vector<std::vector<PII>> ans(n + 1);
	auto isanc = [&](int x, int y) {
		return in[x] <= in[y] && in[y] <= out[x];
	};
	auto dfs2 = [&](auto self, int u, int last) -> void {
		int _ID = 0;
		std::map<int, int> ID;
		for (int i = 0; i < e[u].size(); i++) {
			int v = e[u][i];
			if (v == last) {
				_ID = i;
			} else {
				self(self, v, u);
				ID[in[v]] = i;
			}
		}
		// for (auto [x, y] : ID) {
		// 	std::cout << x << ' ' << y << endl;
		// }
		DSU dsu(e[u].size());
		auto getid = [&](int v) -> int {
			if (!isanc(u, v)) return _ID;
			return (--ID.upper_bound(in[v])) -> second;
		};
		auto add = [&](int x, int y) -> void {
			if (x < 1 || y > n || x == u || y == u) return;
			if (dsu.merge(getid(x), getid(y))) {
				ans[u].push_back({x, y});
				val[u] += abs(x - y);
			}
		};
		for (auto v : e[u]) {
			if (v == last) {
				add(min_up[u] - 1, min_up[u]);
				add(max_up[u], max_up[u] + 1);
			} else {
				add(min[v] - 1, min[v]);
				add(max[v], max[v] + 1);
			}
		}
		if (dsu.group > 1) {
			add(u - 1, u + 1);
		}
		assert(dsu.group == 1);
	};
	dfs2(dfs2, 1, 0);
	for (int i = 1; i <= n; i++) {
		std::cout << val[i] << ' ' << ans[i].size() << endl;
		for (auto [x, y] : ans[i]) {
			std::cout << x << ' ' << y << endl;
		}
		std::cout << endl;
	}
	return 0;
}

int main() {
	Fast_IOS;
	int T = 1;
	std::cin >> T;
	while (T--) {
		int t = solve();
		if (t == 0) continue;
		if (t == YES) std::cout << "YES" << endl;
		if (t == NO) std::cout << "NO" << endl;
	}
	return 0;
}