#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
void file() {
    freopen("read.in", "r", stdin);
    freopen("write.out", "w", stdout);
}
const int N = 5e5 + 10;
inline int read() {
    int sym = 0, res = 0;char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
int n, m, root, lrz, cnt, head[N], a[N];
int fa[N], dep[N], siz[N], top[N], son[N], dfn[N], dat[N];
struct EDGE{
    int u, v, nxt;
} edge[N];
struct Seg_T{
    #define ls x << 1
    #define rs x << 1 | 1
    #define len (r - l + 1)
    int sum[N], tag[N];
    void pushup(int x) {
        sum[x] = (1ll * sum[ls] + sum[rs]) % lrz;
    }
    void build(int x, int l, int r) {
        if (l == r) {
            sum[x] = dat[l]; return;
        }
        int mid = l + r >> 1;
        build(ls, l, mid); build(rs, mid + 1, r);
        pushup(x);
    }
    void modify(int x, int l, int r, int t) {
        sum[x] = (1ll * sum[x] + len * t % lrz) % lrz; tag[x] = (1ll * tag[x] + t) % lrz;
    }
    void pushdown(int x ,int l, int r) {
        if (!tag[x]) return; int mid = l + r >> 1;
        modify(ls, l, mid, tag[x]); modify(rs, mid + 1, r, tag[x]);
        tag[x] = 0;
    }
    void change(int x, int l, int r, int ln, int rn, int t) {
        if (ln <= l && r <= rn) {
            modify(x, l, r, t); return;
        }
        pushdown(x, l, r); int mid = l + r >> 1;
        if (mid >= ln) change(ls, l, mid, ln, rn, t);
        if (mid + 1 <= rn) change(rs, mid + 1, r, ln, rn, t);
        pushup(x);
    }
    int query(int x, int l, int r, int ln, int rn) {
        if (ln <= l && r <= rn) {
            return sum[x];
        }
        pushdown(x, l, r); int mid = l + r >> 1, res = 0;
        if (mid >= ln) res = (1ll * res + query(ls, l, mid, ln, rn)) % lrz;
        if (mid + 1 <= rn) res = (1ll * res + query(rs, mid + 1, r, ln, rn)) % lrz;
        return res;
    }
} T;
void add(int u, int v) {
    edge[++cnt] = (EDGE){u, v, head[u]};
    head[u] = cnt;
}
void dfs1(int u, int last) {
    fa[u] = last; dep[u] = dep[last] + 1; siz[u] = 1;
    for (int e = head[u]; e; e = edge[e].nxt) {
        int v = edge[e].v; if (v == last) continue; dfs1(v, u);
        siz[u] += siz[v]; if (siz[v] > siz[son[u]]) son[u] = v;
    }
}
void dfs2(int u, int front) {
    top[u] = front; dfn[u] = ++cnt; dat[cnt] = a[u];
    if (son[u]) dfs2(son[u], front);
    for (int e = head[u]; e; e = edge[e].nxt) {
        int v = edge[e].v; if (v == fa[u] || v == son[u]) continue; dfs2(v, v);
    }
}
void change(int x, int y, int t) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        T.change(1, 1, n, dfn[top[x]], dfn[x], t);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    T.change(1, 1, n, dfn[x], dfn[y], t);
}
int query(int x, int y) {
    int res = 0;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        res = (res + T.query(1, 1, n, dfn[top[x]], dfn[x])) % lrz;
        x = fa[top[x]];
    }
    if (dfn[x] > dfn[y]) swap(x, y);
    return (1ll * res + T.query(1, 1, n, dfn[x], dfn[y])) % lrz;
}
int main() {
    n = read(); m = read(); root = read(); lrz = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i < n; i++) {
        int u = read(), v = read(); add(u, v); add(v, u);
    }
    cnt = 0; dfs1(root, 0); dfs2(root, root); T.build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int opt = read();
        if (opt == 1) {
            int x = read(), y = read(), t = read() % lrz; change(x, y, t);
        }
        if (opt == 2) {
            int x = read(), y = read(); printf("%d\n", query(x, y));
        }
        if (opt == 3) {
            int x = read(), t = read() % lrz; T.change(1, 1, n, dfn[x], dfn[x] + siz[x] - 1, t);
        }
        if (opt == 4) {
            int x = read(); printf("%d\n", T.query(1, 1, n, dfn[x], dfn[x] + siz[x] - 1));
        }
    }
    return 0;
}