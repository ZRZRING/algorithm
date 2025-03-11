#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'
#define PII std::pair<int, int>

int64 read() {
	int64 res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int main() {
	int n = read();
	std::vector<int> vis(1e6 + 10, 0), to(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		int x = read();
		to[vis[x]] = i; vis[x] = i;
	}
	std::queue<int> q;
	q.push(1);
	std::vector<int> ans(n + 1, 0);
	while (!q.empty()) {
		int u = q.front(); q.pop(); if (u == n) break;
		if (to[u] && !ans[to[u]]) ans[to[u]] = ans[u] + 1, q.push(to[u]);
		if (u + 1 <= n && !ans[u + 1]) ans[u + 1] = ans[u] + 1, q.push(u + 1);
		if (u - 1 > 1 && !ans[u - 1]) ans[u - 1] = ans[u] + 1, q.push(u - 1);
	}
	printf("%d\n", ans[n]);
}