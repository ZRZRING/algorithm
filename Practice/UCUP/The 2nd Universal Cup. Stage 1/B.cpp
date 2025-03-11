#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'
#define PII std::pair<int, int>
#define init_0(x) memset(x, 0, sizeof(x))
#define init_inf(x) memset(x, 0x3f, sizeof(x))

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int N = 2e5, mod = 998244353, inf = 0x3f3f3f3f;

struct EDGE {
	int v; int64 t;
};

void solve() {
	int n = read(), m = read(), Q = read();
	std::vector<int> col(n + 1);
	for (int i = 1; i <= m; i++) col[read()] = 1;
	std::vector<EDGE> edge[n + 1];
	for (int i = 1; i < n; i++) {
		int u = read(), v = read(); int64 t = read();
		edge[u].push_back({v, t});
		edge[v].push_back({u, t});
	}
	std::vector<int64> dis(n + 1), max(n + 1), dep(n + 1);
	std::vector<std::vector<int> > fa(n + 1, std::vector<int>(20));
	std::function<void(int, int64)> dfs = [&](int u, int64 c) -> void {
		if (col[u]) c = 0; max[u] = c;
		for (int i = 1; i <= 17; i++) {
			fa[u][i] = fa[fa[u][i - 1]][i - 1];
			if (!fa[u][i]) break;
		}
		for (auto [v, t] : edge[u]) {
			if (v == fa[u][0]) continue;
			fa[v][0] = u; dis[v] = dis[u] + t; dep[v] = dep[u] + 1;
			dfs(v, c + t);
		}
	};
	dfs(1, 0);
	// for (int i = 1; i <= n; i++) printf("%lld ", max[i]); puts("");
	auto lca = [&](int x, int y) -> int {
		if (dep[x] < dep[y]) std::swap(x, y);
		for (int i = dep[x] - dep[y], j = 0; i; i >>= 1, j++) {
			if (i & 1) x = fa[x][j];
		}
		if (x != y) {
			for (int i = 18; i >= 0; i--) {
				if (fa[x][i] == fa[y][i]) continue;
				x = fa[x][i]; y = fa[y][i];
			}
			x = fa[x][0];
		}
		return x;
	};
	while (Q--) {
		n = read(); std::vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) a[i] = read();
		std::sort(a.begin() + 1, a.end(), [&](int a, int b) {return max[a] > max[b];});
		int x = a[1], z = a[1];
		int64 ans = 0;
		for (int i = 1; i <= n; i++) {
			int y = a[i], d = lca(z, y); ans = std::max(ans, max[y]);
			if (dis[d] <= std::max(dis[z] - max[z], dis[y] - max[y])) break;
			z = d; ans = std::min(ans, dis[x] - dis[z]);
			// printf("debug: %lld %lld %lld %lld %lld %lld %lld %lld\n", 
			// 	d, x, y, dis[d], dis[x], dis[y], max[x], max[y]
			// );
		}
		printf("%lld\n", ans);
	}
}

int main() {
	int T = read();
	while (T--) solve();
	return 0;
}