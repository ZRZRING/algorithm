#include <bits/stdc++.h>

#define int64 long long

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int64 inf = 1e15;

int main() {
	int n = read(), cost[n + 1];
	std::vector<int> edge[n + 1];
	for (int i = 1; i <= n; i++) {
		int u = read(); cost[u] = read();
		int x = read();
		while (x--) {
			int v = read();
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
	}
	int64 f[n + 1][3];
	std::function<void(int, int)> dfs = [&](int u, int last) {
		if (edge[u].size() == 1 && u != 1) {
			f[u][0] = 0; f[u][1] = cost[u]; f[u][2] = cost[u]; return;
		}
		f[u][0] = 0; f[u][1] = inf; f[u][2] = 0;
		for (auto v : edge[u]) {
			if (v == last) continue; dfs(v, u);
			f[u][0] += f[v][1];
			f[u][1] = std::min(f[u][1], f[v][2] - f[v][1]);
			f[u][2] += f[v][0];
		}
		f[u][1] += f[u][0]; f[u][2] += cost[u];
		f[u][1] = std::min(f[u][1], f[u][2]);
		f[u][0] = std::min(f[u][0], f[u][1]);
	};
	dfs(1, 1);
	printf("%lld\n", f[1][1]);
	return 0;
}