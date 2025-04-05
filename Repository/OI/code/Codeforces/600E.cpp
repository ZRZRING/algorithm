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
    return sym ? - res : res;
}
struct EDGE {
    int u, v, nxt;
} edge[N];
int n, m, c[N], head[N], cnt, son[N], siz[N], fa[N], sum[N], top, ans[N], tot[N];
void add(int u, int v) {edge[++cnt] = (EDGE){u, v, head[u]}; head[u] = cnt;}
void dfs1(int u, int last) {
    siz[u] = 1; fa[u] = last;
    for (int e = head[u]; e; e = edge[e].nxt) {
        int v = edge[e].v; if (v == last) continue;
        dfs1(v, u); siz[u] += siz[v]; if (siz[v] > siz[son[u]]) son[u] = v;
    }
}
void update(int u, int t, int s) {
    sum[tot[c[u]]] -= c[u]; tot[c[u]] += t; sum[tot[c[u]]] += c[u];
    if (sum[top + 1]) ++top; if (!sum[top]) --top;
    for (int e = head[u]; e; e = edge[e].nxt) {
        int v = edge[e].v; if (v == s || v == fa[u]) continue; update(v, t, s);
    }
}
void dfs2(int u, int keep) {
    for (int e = head[u]; e; e = edge[e].nxt) {
        int v = edge[e].v; if (v == fa[u] || v == son[u]) continue; dfs2(v, 0);
    }
    if (son[u]) dfs2(son[u], 1); update(u, 1, son[u]); ans[u] = sum[top];
    for (int i = 1; i <= top; i++) printf("%d ", sum[i]); printf("\n"); if (!keep) update(u, -1, son[u]);
}
int main() {
    n = read();
    for (int i = 1; i <= n; i++) c[i] = read();
    for (int i = 1; i < n; i++) {
        int u = read(), v = read(); add(u, v); add(v, u);
    }
    dfs1(1, 0); dfs2(1, 0);
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    return 0;
}
