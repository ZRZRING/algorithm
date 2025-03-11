#include <bits/stdc++.h>

using int64 = long long;

struct TREE {
	int n, flag = 0;

	std::vector<std::vector<int>> e, fa;
	
	std::vector<int> dep;
	
	TREE(int n) : n(n) {
		e.resize(n);
		fa.resize(n);
		dep.resize(n);
		for (int i = 0; i < n; i++) {
			fa[i].resize(21);
		}
	}

	void add(int u, int v) {
		e[u].push_back(v);
		e[v].push_back(u);
	}

	void dfs(int u, int last) {
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
};