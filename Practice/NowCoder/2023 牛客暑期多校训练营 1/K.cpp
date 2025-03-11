#include <bits/stdc++.h>

#define int64 long long

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int main() {
	int n = read(), m = read(), k = read(), d[n + 1];
	memset(d, 0, sizeof(d));
	std::vector<int> edge[n + 1];
	for (int i = 1; i <= m; i++) {
		int u = read(), v = read();
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	std::queue<int> q;
	int dis[n + 1], pre[n + 1];
	bool vis[n + 1];
	memset(pre, 0, sizeof(pre));
	memset(vis, 0, sizeof(vis));
	memset(dis, -1, sizeof(dis));
	q.push(1); dis[1] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (dis[u] == k) continue;
		for (auto v : edge[u]) {
			if (dis[v] != -1) continue;
			dis[v] = dis[u] + 1; pre[v] = u; vis[u] = 1; q.push(v);
		}
	}
	int64 ans = 1;
	for (int u = 2; u <= n; u++) {
		if (dis[u] == -1) continue;
		int64 cnt = 0;
		for (auto v : edge[u]) {
			if (v == pre[u] || u == pre[v]) continue; cnt++;
		}
		if (!vis[u]) cnt = std::max(cnt, 1ll);
		ans += (k - dis[u]) * cnt + 1;
	}
	printf("%lld", ans);
	return 0;
}