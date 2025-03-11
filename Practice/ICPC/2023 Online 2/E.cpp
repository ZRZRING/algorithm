#include <bits/stdc++.h>

#define int64 long long
#define PII std::pair<int, int>
#define dis first
#define node second

int64 read() {
	int64 res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int main() {
	int n = read(), m = read();
	std::vector<int> tree[n + 1], edge[n + 1], fa(n + 1);
	for (int v = 2; v <= n; v++) {
		int u = read();
		tree[u].push_back(v); fa[v] = u;
	}
	std::vector<bool> st(n + 1);
	for (int i = 1; i <= m; i++) {
		int u = read(), v = read();
		st[u] = 1; st[v] = 1;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	std::queue<int> q; q.push(1);
	std::vector<int> ans(n + 1);
	ans[1] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (auto v : edge[u]) {
			while (!ans[v]) {
				ans[v] = ans[u] + 1; if (st[v]) q.push(v); v = fa[v];
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		if (!ans[i]) printf("-1 "); else printf("%d ", ans[i] - 1);
	}
	puts("");
}