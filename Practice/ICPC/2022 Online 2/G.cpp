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

const int N = 2e6 + 10, mod = 1e9 + 7;

inline int read() {
	bool sym = 0; int res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int n, m, fa[N], head[N], cnt, f[N], mul[N];

struct DAT {
	int l, r, len;
} dat[N];

struct EDGE {
	int u, v, nxt;
} edge[N];

bool cmp(DAT a, DAT b) {
	return a.l == b.l ? a.r > b.r : a.l < b.l;
}

void add(int u, int v) {
	edge[++cnt] = (EDGE){u, v, head[u]}; head[u] = cnt;
}

void dfs(int u) {
	f[u] = 1; int cnt = 0, sum = 0;
	for (int e = head[u]; e; e = edge[e].nxt) {
		int v = edge[e].v; if (v == fa[u]) continue; dfs(v);
		cnt++; sum += dat[v].len; f[u] = 1ll * f[u] * f[v] % mod;
	}
	f[u] = 1ll * f[u] * mul[dat[u].len - sum + cnt] % mod;
}

int main() {
	n = read(); m = read(); mul[1] = 1;
	for (int i = 2; i <= n; i++) mul[i] = 1ll * mul[i - 1] * i % mod;
	for (int i = 1; i <= m; i++) {
		dat[i].l = read(); dat[i].r = read(); dat[i].len = dat[i].r - dat[i].l + 1;
	}
	sort(dat + 1, dat + m + 1, cmp);
	// for (int i = 1; i <= m; i++) printf("%d %d %d\n", dat[i]);
	int u = 0; dat[0].len = n;
	for (int v = 1; v <= m; v++) {
		while (dat[v].l > dat[u].r && u) u = fa[u]; add(u, v); fa[v] = u; u = v;
	}
	dfs(0); printf("%d", f[0]);
	return 0;
}