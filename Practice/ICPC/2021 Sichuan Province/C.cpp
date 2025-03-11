#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>
#include <functional>

#define int64 long long

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int N = 1e5 + 10;

int main() {
	int T = read();
	while (T--) {
		int n = read(), m = read(), cnt = 0;
		std::vector<int> edge[n + 1];
		bool vis[n + 1] = {0}, del[n + 1] = {0};
		for (int i = 1; i <= n; i++) vis[i] = 0, edge[i].clear();
		for (int i = 1; i <= m; i++) {
			int u = read(), v = read();
			edge[u].push_back(v);
			edge[v].push_back(u);
			if (u == v + 1) del[v] = 1, cnt++;
			if (v == u + 1) del[u] = 1, cnt++;
		}
		for (int i = 1; i <= n; i++) {
			if (del[i]) {
				for (auto v : edge[i]) {
					edge[i + 1].push_back(v);
					edge[v].push_back(i + 1);
				}
			}
		}
		int ans = 0;
		std::function<int(int, int)> dfs = [&](int u, int len) -> int{
			
		};
		for (int i = 1; i <= n; i++) if (!vis[i]) ans = std::max(ans, dfs(i, 0));
		printf("%d\n", n - 1 - ans - cnt);
	}
	return 0;
}