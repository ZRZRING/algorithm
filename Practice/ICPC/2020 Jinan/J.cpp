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

struct EDGE {int u, v, nxt;} edge[N];

int n, m, k, cnt, c, head[N], col[N], tot[N], num[N];

long long dat[N];

void add(int u, int v) {edge[++cnt] = (EDGE){u, v, head[u]}; head[u] = cnt;}

void dfs1(int u, int last) {
	col[u] = col[last] ^ 1; num[u] = ++tot[col[u]];
	for (int e = head[u]; e; e = edge[e].nxt) {
		int v = edge[e].v; if (v == last) continue; dfs1(v, u);
	}
}

void dfs2(int u, int last) {
	if (col[u] == c) {
		dat[u] = (1ll << 59) - 1 ^ 1ll << num[u];
		for (int e = head[u]; e; e = edge[e].nxt) {
			int v = edge[e].v; if (v == last) continue; dfs2(v, u);
		}
	} else {
		dat[u] = 1ll << 59; if (last) dat[u] |= 1ll << num[last];
		for (int e = head[u]; e; e = edge[e].nxt) {
			int v = edge[e].v; if (v == last) continue; dat[u] |= 1ll << num[v]; dfs2(v, u);
		}
	}
}

void put2(long long a) {
	for (int i = 59; i >= 0; i--) printf("%d", (a & 1ll << i) ? 1 : 0); puts("");
}

// 构造

int main() {
	n = read();
	for (int i = 1; i < n; i++) {
		int u = read(), v = read(); add(u, v); add(v, u);
	}
	dfs1(1, 0); c = tot[0] < tot[1] ? 0 : 1; dfs2(1, 0);
	for (int i = 1; i <= n; i++) printf("%lld ", dat[i]);
	return 0;
}