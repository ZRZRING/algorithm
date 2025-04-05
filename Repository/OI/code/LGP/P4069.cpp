#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 123456789123456789ll
using namespace std;
void file() {
    freopen("read.in", "r", stdin);
    freopen("write.out", "w", stdout);
}
const int N = 1e6 + 10;
inline int read() {
    int sym = 0, res = 0;char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
int n, m, cnt, head[N];
int siz[N], dep[N], son[N], fa[N], top[N], dfn[N];
long long tdep[N], dep[N];
struct EDGE {
    int u, v, dis, nxt;
} edge[N];
struct ST {
    long long tmin[N], lmin[N], rmin[N];
    #define ls now << 1
    #define rs now << 1 | 1
    void build(int now, int l, int r) {
        lmin[now] = rmin[now] = tmin[now] = INF;
        if (l == r) return; int mid = l + r >> 1;
        build(ls, l, mid); build(rs, mid + 1, r);
    }
    void update(int now) {
        tmin[now] = min(tmin[now], min(tmin[ls], tmin[rs]));
    }
    long long gety(int lx, int rx, long long ly, long long ry, int x) {
        return tdep[lx] == tdep[rx] ? ly : ly + (ry - ly) / (tdep[rx] - tdep[lx]) * (tdep[x] - tdep[lx]);
    }
    void modify(int now, int l, int r, long long ly, long long ry) {
        if (ly >= lmin[now] && ry >= rmin[now]) return;
        if (ly <= lmin[now] && ry <= rmin[now]) {
            lmin[now] = ly; rmin[now] = ry; tmin[now] = min(tmin[now], min(ly, ry)); return;
        }
        int mid = l + r >> 1;
        if (gety(l, r, ly, ry, mid) < gety(l, r, lmin[now], rmin[now], mid)) {
            swap(lmin[now], ly); swap(rmin[now], ry);
            tmin[now] = min(tmin[now], min(lmin[now], rmin[now]));
        }
        if (ly < lmin[now]) modify(ls, l, mid, ly, gety(l, r, ly, ry, mid));
        else modify(rs, mid + 1, r, gety(l, r, ly, ry, mid + 1), ry);
        update(now);
    }
    void change(int now, int l, int r, int lx, int rx, long long ly, long long ry) {
        if (lx <= l && r <= rx) {
            modify(now, l, r, gety(lx, rx, ly, ry, l), gety(lx, rx, ly, ry, r)); return;
        }
        int mid = l + r >> 1;
        if (mid >= lx) change(ls, l, mid, lx, rx, ly, ry);
        if (mid + 1 <= rx) change(rs, mid + 1, r, lx, rx, ly, ry);
        update(now);
    }
    long long query(int now, int l, int r, int lx, int rx) {
        if (lx <= l && r <= rx) return tmin[now];
        long long ans = lmin[now] > rmin[now] ? gety(l, r, lmin[now], rmin[now], rx) : gety(l, r, lmin[now], rmin[now], lx);
        int mid = l + r >> 1;
        if (mid >= rx) return min(ans, query(ls, l, mid, lx, rx));
        else if (mid + 1 <= lx) return min(ans, query(rs, mid + 1, r, lx, rx));
        else return min(ans, min(query(ls, l, mid, lx, mid), query(rs, mid + 1, r, mid + 1, rx)));
    }
} T;
void add(int u, int v, int t) {
    edge[++cnt] = (EDGE){u, v, t, head[u]}; head[u] = cnt;
}
void dfs1(int u, int last) {
    siz[u] = 1; dep[u] = dep[last] + 1; fa[u] = last;
    for (int i = head[u]; i; i = edge[i].nxt) {
        int v = edge[i].v; if (v == last) continue;
        dep[v] = dep[u] + edge[i].dis; dfs1(v, u);
        siz[u] += siz[v]; if (siz[v] > siz[son[u]]) son[u] = v;
    }
}
void dfs2(int u, int front) {
    top[u] = front; dfn[u] = ++cnt; tdep[cnt] = dep[u];
    if (son[u]) dfs2(son[u], front);
    for (int i = head[u]; i; i = edge[i].nxt) {
        int v = edge[i].v; if (v == fa[u] || v == son[u]) continue; dfs2(v,v);
    }
}
int lca(int x, int y) {
    while (top[x] != top[y]) dep[top[x]] < dep[top[y]] ? y = fa[top[y]] : x = fa[top[x]];
    return dep[x] < dep[y] ? x : y;
}
void change(int x, int y, int k, int b) {
    int S1 = x, S2 = lca(x, y); long long t = dep[S1] - dep[S2];
    while (top[x] != top[y]) {
        if (dep[top[x]] > dep[top[y]]) {
            T.change(1, 1, n, dfn[top[x]], dfn[x], k * (dep[S1] - dep[top[x]]) + b, k * (dep[S1] - dep[x]) + b);
            x = fa[top[x]];
        } else {
            T.change(1, 1, n, dfn[top[y]], dfn[y], k * (t + dep[top[y]] - dep[S2]) + b, k * (t + dep[y] - dep[S2]) + b);
            y = fa[top[y]];
        }
    }
    if (dfn[x] < dfn[y]) T.change(1, 1, n, dfn[x], dfn[y], k * t + b, k * (t + dep[y] - dep[S2]) + b);
    else T.change(1, 1, n, dfn[y], dfn[x], k * t + b, k * (dep[S1] - dep[x]) + b);
}
long long query(int x, int y) {
    long long res = INF;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        res = min(res, T.query(1, 1, n, dfn[top[x]], dfn[x]));
        x = fa[top[x]];
    }
    if (dfn[x] > dfn[y]) swap(x, y);
    return min(res, T.query(1, 1, n, dfn[x], dfn[y]));
}
void debug(int now, int l, int r) {
    printf("%d %d %lld %lld %lld\n", l, r, T. lmin[now], T.rmin[now], T.tmin[now]);
    if (l == r) return; int mid = (l + r) >> 1;
    debug(ls, l, mid); debug(rs, mid + 1, r);
}
int main() {
    n = read(); m = read();
    for (int i = 1, x, y, t; i < n; i++) {
        x = read(), y = read(), t = read();
        add(x, y, t); add(y, x, t);
    }
    cnt = 0; dfs1(1, 0); dfs2(1, 1); T.build(1, 1, n);
    for (int i = 1, opt, x, y, k, b; i <= m; i++) {
        opt = read();
        if (opt == 1) {
            x = read(), y = read(), k = read(), b = read(); change(x, y, k, b);
        }
        if (opt == 2) {
            x = read(), y = read(); printf("%lld\n", query(x, y));
        }
    }
    return 0;
}