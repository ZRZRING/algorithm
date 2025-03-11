#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

#define file(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout);
#define dbg(x) cerr<<"In Line"<<__LINE__<<" the "<<#x<<" = "<<x<<'\n';
#define abs(x) ((x) < 0 ? -(x) : (x))

using namespace std;

const int N = 2e6 + 10;

inline int read() {
	bool sym = 0; int res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int n, m, a[N], b[N], ans, f[N];

bool vis[N];

int dfs(int u, int x) {
	vis[u] = 1;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) dfs();
	}
	vis[u] = 0;
	return f[u];
}

int main() {
	n = read(); int ans = 1e9 + 7;
	for (int i = 1; i <= n; i++) a[i] = read(), b[i] = read();
	for (int i = 1; i <= n; i++) memset(f, 0x3f, sizeof(f)), ans = min(ans, dfs(i, b[i]));
	printf("%d", ans);
	return 0;
}