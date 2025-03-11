#include <bits/stdc++.h>

#define int64 long long
#define PII std::pair<int, int>

int64 read() {
	int64 res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int main() {
	int n = read(), m = read();
	std::vector<std::vector<int> > edge(n + 1);
	for (int i = 1; i <= m; i++) {
		int u = read(), v = read();
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	int64 ans = 0, a = 0, b = 0;
	std::vector<bool> vis(n + 1);
	std::function<int(int)> dfs = [&](int u) -> int {
		int res = 1; vis[u] = 1;
		for (auto v : edge[u]) {
			if (vis[v]) continue;
			res += dfs(v);
		}
		return res;
	};
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			int64 t = dfs(i);
			// printf("%d %d\n", t, e);
			ans += t * (t - 1) / 2;
			if (!a || t <= a) b = a, a = t;
			else {
				if (!b || t <= b) b = t;
			}
		}
	}
	if (ans - m != 0) {
		printf("%lld\n", ans - m);
	} else {
		int64 c = a + b;
		printf("%lld\n", c * (c - 1ll) / 2ll - a * (a - 1ll) / 2ll - b * (b - 1ll) / 2ll);
	}
	return 0;
}