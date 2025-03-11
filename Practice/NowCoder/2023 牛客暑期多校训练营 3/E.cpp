#include <bits/stdc++.h>

#define int64 long long

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int N = 2e5 + 10, mod = 998244353, inf = 0x3f3f3f3f;

int main() {
	int T = read();
	while (T--) {
		int n = read(), m = read();
		std::vector<int> edge[n + 1];
		for (int i = 1; i <= m; i++) {
			int u = read(), v = read();
			edge[u].push_back(v);
		}
		bool flag = 0;
		bool vis[n + 1];
		memset(vis, 0, sizeof(vis));
		std::function<void(int)> dfs = [&](int u) {
			vis[u] = 1;
			for (auto v : edge[u]) {
				if (vis[v]) {flag = 1; return;}
				vis[v] = 1; dfs(v); vis[v] = 0;
			}
			vis[u] = 0;
		};
	}
	return 0;
}