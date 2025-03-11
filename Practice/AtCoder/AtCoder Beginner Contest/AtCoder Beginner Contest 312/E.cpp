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

const int N = 2e5 + 10, mod = 998244353, inf = 0x3f3f3f3f;

int main() {
	int n = read();
	int vis[101][101][101]; init_0(vis);
	std::set<int> ans[n + 1];
	for (int x = 1; x <= n; x++) {
		int x1 = read(), y1 = read(), z1 = read(), x2 = read() - 1, y2 = read() - 1, z2 = read() - 1;
		for (int i = x1; i <= x2; i++) {
			for (int j = y1; j <= y2; j++) {
				for (int k = z1; k <= z2; k++) {
					vis[i][j][k] = x; int a;
					if (i <= 100) {
						a = vis[i + 1][j][k]; if (a && a != x) ans[x].emplace(a), ans[a].emplace(x);
					}
					if (j <= 100) {
						a = vis[i][j + 1][k]; if (a && a != x) ans[x].emplace(a), ans[a].emplace(x);
					}
					if (k <= 100) {
						a = vis[i][j][k + 1]; if (a && a != x) ans[x].emplace(a), ans[a].emplace(x);
					}
					if (i) {
						a = vis[i - 1][j][k]; if (a && a != x) ans[x].emplace(a), ans[a].emplace(x);
					}
					if (j) {
						a = vis[i][j - 1][k]; if (a && a != x) ans[x].emplace(a), ans[a].emplace(x);
					}
					if (k) {
						a = vis[i][j][k - 1]; if (a && a != x) ans[x].emplace(a), ans[a].emplace(x);
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) printf("%d\n", ans[i].size());
	return 0;
}