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
	std::vector<std::vector<int> > edge(n + 1, std::vector<int>(n + 1));
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			edge[i][j] = read();
			edge[j][i] = edge[i][j];
		}
	}
	int64 ans = 0;
	std::vector<bool> vis(n + 1);
	std::function<void(int, int)> dfs = [&](int x, int64 t) -> void {
		if (x == n / 2 + 1) {
			ans = std::max(ans, t); return;
		}
		for (int i = 1; i <= n; i++) {
			if (vis[i]) continue;
			vis[i] = 1;
			for (int j = 1; j <= n; j++) {
				if (vis[j] || i == j) continue;
				vis[j] = 1; dfs(x + 1, t + edge[i][j]); vis[j] = 0;
			}
			vis[i] = 0;
		}
	};
	dfs(1, 0);
	printf("%lld\n", ans);
	return 0;
}