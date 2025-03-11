#include <bits/stdc++.h>

#define int64 long long
#define PII std::pair<int, int>
#define endl '\n'

int64 read() {
	int64 res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int inf = 1e9 + 7;

int main() {
	int A = read(), B = read(), C = A + B - read();
	int SA = read(), SB = read(), n = read(), m = read();
	std::vector<int> edge[n + 1];
	for (int i = 1; i <= m; i++) {
		int u = read(), v = read();
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	auto solve = [&](int s) -> std::vector<int> {
		std::priority_queue<PII, std::vector<PII>, std::greater<PII> > q;
		std::vector<int> dis(n + 1, inf);
		bool vis[n + 1];
		memset(vis, 0, sizeof(vis));
		dis[s] = 0; q.push({0, s});
		while (!q.empty()) {
			int u = q.top().second; q.pop(); if (vis[u]) continue; vis[u] = 1;
			for (auto v : edge[u]) {
				if (vis[v]) continue;
				if (dis[u] + 1 < dis[v]) {
					dis[v] = dis[u] + 1; q.push({dis[v], v});
				}
			}
		}
		return dis;
	};
	std::vector<int> disA = solve(SA);
	std::vector<int> disB = solve(SB);
	std::vector<int> disN = solve(n);
	if (disN[SA] == inf || disN[SB] == inf) {printf("-1\n"); return 0;}
	int ans = 2e9;
	for (int i = 1; i <= n; i++) {
		ans = std::min(ans, disA[i] * A + disB[i] * B + disN[i] * C);
	}
	printf("%lld\n", ans);
}