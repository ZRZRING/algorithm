#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define inf 1e9
using namespace std;
void file() {
    freopen("read.in", "r", stdin);
    freopen("write.out", "w", stdout);
}
const int N = 1e7 + 10;
inline int read() {
    int sym = 0, res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
struct EDGE {
    int u, v, nxt;
} edge[N];
int n, m, head[N], cnt, x[N], y[N], type[N], tn, rt[N];
int fa[N], dep[N], siz[N], son[N], top[N];
int tot, tmax[N], tag[N], ls[N], rs[N], ans[N];
void add(int u, int v) {
    edge[++cnt] = (EDGE){u, v, head[u]}; head[u] = cnt;
}
void dfs1(int u, int last) {
    fa[u] = last; dep[u] = dep[last] + 1; siz[u] = 1;
    for (int e = head[u]; e; e = edge[e].nxt) {
        int v = edge[e].v; if (v == last) continue;
        dfs1(v, u); siz[u] += siz[v];
        if (siz[v] > siz[son[u]]) son[u] = v;
    }
}
void dfs2(int u, int front) {
    top[u] = front; if (son[u]) dfs2(son[u], front);
    for (int e = head[u]; e; e = edge[e].nxt) {
        int v = edge[e].v; if (top[v]) continue; dfs2(v, v);
    }
}
int lca(int x, int y) {
    while (top[x] != top[y]) dep[top[x]] < dep[top[y]] ? y = fa[top[y]] : x = fa[top[x]];
    return dep[x] < dep[y] ? x : y;
}
void pushup(int x) {
    if (tmax[ls[x]] >= tmax[rs[x]]) tmax[x] = tmax[ls[x]], tag[x] = tag[ls[x]];
    else tmax[x] = tmax[rs[x]], tag[x] = tag[rs[x]];
}
int change(int x, int l, int r, int goal, int t) {
    if (!x) x = ++tot;
    if (l == r) {tmax[x] += t; tag[x] = l; return x;}
    int mid = l + r >> 1;
    if (mid >= goal) ls[x] = change(ls[x], l, mid, goal, t);
    else rs[x] = change(rs[x], mid + 1, r, goal, t);
    pushup(x); return x;
}
int merge(int x, int y, int l, int r) {
    if (!x || !y) return x | y;
    if (l == r) {tmax[x] += tmax[y]; tag[x] = l; return x;}
    int mid = l + r >> 1;
    ls[x] = merge(ls[x], ls[y], l, mid);
    rs[x] = merge(rs[x], rs[y], mid + 1, r);
    pushup(x); return x;
}
void dfs3(int u) {
    for (int e = head[u]; e; e = edge[e].nxt) {
        int v = edge[e].v; if (v == fa[u]) continue; dfs3(v);
        rt[u] = merge(rt[u], rt[v], 1, tn);
    }
    if (tmax[rt[u]]) ans[u] = tag[rt[u]];
}
int main() {
    n = read(); m = read();
    for (int i = 1; i < n; i++) {
        int u = read(), v = read(); add(u, v); add(v, u);
    }
    dfs1(1, 0); dfs2(1, 1);
    for (int i = 1; i <= m; i++) {
        x[i] = read(); y[i] = read(); type[i] = read(); tn = max(tn, type[i]);
    }
    for (int i = 1; i <= m; i++) {
        rt[x[i]] = change(rt[x[i]], 1, tn, type[i], 1);
        rt[y[i]] = change(rt[y[i]], 1, tn, type[i], 1);
        int z = lca(x[i], y[i]);
        rt[z] = change(rt[z], 1, tn, type[i], -1);
        if (fa[z]) rt[fa[z]] = change(rt[fa[z]], 1, tn, type[i], -1);
    }
    dfs3(1);
    for (int i = 1; i <= n; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}