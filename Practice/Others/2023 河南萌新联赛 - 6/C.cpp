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

int main() {
	int n = read();
	std::vector<int> edge[n + 1], size(n + 1, 0);
	for (int i = 1; i < n; i++) {
		int u = read(), v = read();
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	std::vector<double> E(n + 1, 0);
	std::function<void(int, int)> dfs1 = [&](int u, int last) {
		for (auto v : edge[u]) {
			if (v == last) continue; dfs1(v, u);
			E[u] += E[v] + 1; size[u]++;
		}
		if (size[u]) E[u] /= size[u];
	};
	std::function<void(int, int, double)> dfs2 = [&](int u, int last, double t) {
		E[u] = (E[u] * size[u] + t + 1) / (size[u] + 1);
		for (auto v : edge[u]) {
			if (v == last) continue;
			dfs2(v, u, (E[u] * (size[u] + 1) - E[v] - 1) / size[u]);
		}
	};
	dfs1(1, 1);
	for (auto v : edge[1]) dfs2(v, 1, (E[1] * size[1] - E[v] - 1) / std::max(1, size[1] - 1));
	// for (int i = 1; i <= n; i++) printf("%d %lf\n", i, E[i]);
	double ans = 0;
	for (int i = 1; i <= n; i++) ans = std::max(ans, E[i]);
	printf("%.3lf\n", ans);
	return 0;
}