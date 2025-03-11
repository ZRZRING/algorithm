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

struct TREE {
	int n, flag = 0, dfn_cnt = 0;

	std::vector<std::vector<int>> e, fa;
	
	std::vector<int> dep, dfn, vis;
	
	TREE(int n) : n(n) {
		e.resize(n);
		fa.resize(n);
		dep.resize(n);
		dfn.resize(n);
		vis.resize(n);
		for (int i = 0; i < n; i++) {
			fa[i].resize(21);
		}
	}

	void add(int u, int v) {
		e[u].push_back(v);
		e[v].push_back(u);
	}

	void dfs(int u, int last) {
		dfn[u] = ++dfn_cnt;
		dep[u] = dep[last] + 1;
		for (int i = 1; i <= 20; i++) {
			if (!fa[u][i - 1]) break;
			fa[u][i] = fa[fa[u][i - 1]][i - 1];
		}
		for (auto v : e[u]) {
			if (v == fa[u][0]) continue;
			fa[v][0] = u;
			dfs(v, u);
		}
	}

	int lca(int x, int y) {
		for (int i = dep[x] - dep[y], j = 0; i > 0; i >>= 1, j++) {
			if (i & 1) x = fa[x][j];
		}
		for (int i = dep[y] - dep[x], j = 0; i > 0; i >>= 1, j++) {
			if (i & 1) y = fa[y][j];
		}
		if (x != y) {
			for (int i = 20; i >= 0; i--) {
				if (fa[x][i] == fa[y][i]) continue;
				x = fa[x][i];
				y = fa[y][i];
			}
			x = fa[x][0];
		}
		return x;
	};

	PII cal(int u, int last) {
		int64 cnt = 0;
		PII res = {0, 0};
		if (vis[u]) res.second = 1;
		for (auto v : e[u]) {
			if (v == last) continue;
			auto [x, y] = cal(v, u);
			if (vis[u]) {
				res.first += x + y;
			} else {
				res.first += x + cnt * y;
				res.second += y;
				cnt += y;
			}
		}
		return res;
	}
};

int solve() {
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> col(n + 1);
	for (int i = 1; i <= n; i++) {
		int x;
		std::cin >> x;
		col[x].push_back(i);
	}
	TREE t1(n + 1);
	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		t1.add(u, v);
	}
	t1.dfs(1, 1);
	int64 ans = 0;
	std::vector<int> vis(n + 1);
	for (int i = 1; i <= n; i++) {
		if (col[i].empty() || col[i].size() == 1) continue;
		for (auto x : col[i]) {
			vis[x] = 1;
		}
		sort(col[i].begin(), col[i].end(), [&](int a, int b) {
			return t1.dfn[a] < t1.dfn[b];
		});
		int t = col[i].size();
		for (int j = 1; j < t; j++) {
			col[i].push_back(t1.lca(col[i][j - 1], col[i][j]));
		}
		sort(col[i].begin(), col[i].end(), [&](int a, int b) {
			return t1.dfn[a] < t1.dfn[b];
		});
		int len = unique(col[i].begin(), col[i].end()) - col[i].begin();
		col[i].resize(len);
		// for (auto x : col[i]) {
		// 	std::cout << x << ' ';
		// }
		// std::cout << endl;
		std::map<int, int> map;
		TREE t2(col[i].size());
		for (int j = 0; j < col[i].size(); j++) {
			map[col[i][j]] = j;
			if (vis[col[i][j]]) t2.vis[j] = 1;
		}
		for (int j = 1; j < col[i].size(); j++) {
			int u = col[i][j], v = t1.lca(col[i][j - 1], col[i][j]);
			// std::cout << u << ' ' << v << endl;
			t2.add(map[u], map[v]);
		}
		ans += t2.cal(0, 0).first;
		for (auto x : col[i]) {
			vis[x] = 0;
		}
	}
	std::cout << ans << endl;
	return 0;
}

int main() {
	// Fast_IOS;
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