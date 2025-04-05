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
    int u, v, nxt;
} edge[N];
struct LIMIT {
    int mi, mx;
} limit[N];
int n, head[N], cnt, in[N], out[N], fa[N], siz[N], flag;
int l, r, m;
void add(int u, int v) {
    edge[++cnt] = (EDGE){u, v, head[u]}; head[u] = cnt;
}
void dfs(int u, int last) {
    fa[u] = last; siz[u] = 1; limit[u].mi = in[u]; int sum = 0;
    for (int e = head[u]; e; e = edge[e].nxt) {
        int v = edge[e].v; if (v == last) continue;
        dfs(v, u); siz[u] += siz[v]; sum += limit[v].mi;
    }
    limit[u].mi = max(limit[u].mi, sum);
    if (limit[u].mi > siz[u] || out[u] > n - siz[u]) flag = 1;
}
bool check(int u) {
	limit[u].mx = m - out[u]; int sum = 1;
	for(int e = head[u]; e; e = edge[e].nxt) {
		int v = edge[e].v; if (v == fa[u]) continue;
        if (!check(v)) return 0; sum += limit[v].mx;
	}
	limit[u].mx = min(limit[u].mx, sum);
	if (limit[u].mi > limit[u].mx) return 0; return 1;
}
int main() {
    n = read(); r = n + 1;
    for (int i = 2; i <= n; i++) {
        int u = read(), v = read(); add(u, v); add(v, u);
    }
    int A = read(); for (int i = 1; i <= A; i++) {int x = read(); in[x] = max(in[x], read());}
    int B = read(); for (int i = 1; i <= B; i++) {int x = read(); out[x] = max(out[x], read());}
    if (out[1]) {printf("-1"); return 0;}
    for (int i = 1; i <= n; i++) l = max(l, in[i] + out[i]); if (l > r) {printf("-1"); return 0;}
    dfs(1, 0); if (flag) {printf("-1"); return 0;}
    while (l < r) {
        m = l + r >> 1; if (check(1)) r = m; else l = m + 1;
    }
    if (r > n) {printf("-1"); return 0;} printf("%d", r);
    return 0;
}