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

void solve() {
	int n = read(), k = read(), cnt = 0;
	std::vector<int> to(n + 1, 0), d(n + 1, 0), vis(n + 1, 0);
	if (k == 1) {
		std::vector<int> a(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			a[i] = read();
		}
		for (int i = 1; i <= n; i++) {
			if (a[i] != i) {
				printf("No\n"); return;
			}
		}
		printf("Yes\n"); return;
	}
	for (int i = 1; i <= n; i++) {
		int x = read(); to[i] = x; d[x]++;
	}
	std::queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (!d[i]) q.push(i);
	}
	while (!q.empty()) {
		int u = q.front(); q.pop(); vis[u] = 1;
		if (--d[to[u]] == 0) q.push(to[u]); 
	}
	std::function<bool(int, int)> dfs = [&](int u, int t) -> bool {
		if (vis[u]) {
			return t - vis[u] != k;
		}
		vis[u] = t;
		return dfs(to[u], t + 1);
	};
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		if (dfs(i, 1)) {
			printf("No\n"); return;
		}
	}
	printf("Yes\n");
}

int main() {
	int T = read();
	while (T--) solve();
	return 0;
}