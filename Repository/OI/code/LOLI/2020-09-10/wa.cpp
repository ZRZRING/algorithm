#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
void file() {
    freopen("std.in", "r", stdin);
    freopen("wa.out", "w", stdout);
}
const int N = 1e6 + 10, inf = 1e9;
inline int read() {
    bool sym = 0; int res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
struct EDGE {
	int u, v, nxt, t;
} edge[N];
struct NODE {
	int dis, nxt;
} f[N];
int n, m, head[N], cnt, val[N], fa[N];
void add(int u, int v, int t) {
	edge[++cnt] = (EDGE){u, v, head[u], t}; head[u] = cnt;
}
void dfs1(int u, int last) {
	fa[u] = last; int p = 0, mi = inf;
	if (val[u] == 0) {
		for (int e = head[u]; e; e = edge[e].nxt) {
			int v = edge[e].v; if (v == last) continue; val[v] = edge[e].t; dfs1(v, u);
		}
	}
	if (val[u] == 1) {
		for (int e = head[u]; e; e = edge[e].nxt) {
			int v = edge[e].v; if (v == last) continue; val[v] = edge[e].t; dfs1(v, u);
			if (val[v] >= 2 && f[v].dis < f[u].dis) f[u] = (NODE){f[v].dis + 1, v};
		}
	}
	if (val[u] >= 2) {
		for (int e = head[u]; e; e = edge[e].nxt) {
			int v = edge[e].v; if (v == last) continue; val[v] = edge[e].t; dfs1(v, u);
			if (val[v] == 1) f[u] = (NODE){0, v};
			if (f[v].dis < f[u].dis) f[u] = (NODE){f[v].dis + 1, v};
		}
	}
}
void dfs2(int u) {
	for (int e = head[u]; e; e = edge[e].nxt) {
		int v = edge[e].v; if (v == fa) continue;
	}
}
int main() {
    n = read();
    for (int i = 1; i < n; i++) {
    	int u = read(), v = read(), c = read(), g = read();
    	add(u, v, c ^ g); add(v, u, c ^ g);
    }
	for (int i = 1; i <= n; i++) f[i].dis = inf;
    dfs1(1, 0);
	for (int i = 1; i <= n; i++) printf("%d %d\n", f[i].dis, f[i].nxt);
	for (int i = 1; i <= n; i++) printf("%d\n", val[i]);
	dfs2(1);
    return 0;
}