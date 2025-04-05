#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define q(x, y) SEG::query(1, 1, n, x, y)
#define inf 1e9
using namespace std;
void file() {
    freopen("read.in", "r", stdin);
    freopen("write.out", "w", stdout);
}
const int N = 1e6 + 10;
inline int read() {
    int sym = 0, res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
struct EDGE {
    int u, v, nxt;
} edge[N];
int n, m, head[N], cnt, dfn[N], siz[N], dep[N], rev[N];
void add(int u, int v) {edge[++cnt] = (EDGE){u, v, head[u]}; head[u] = cnt;}
namespace SEG {
    int tmax[N], tag[N];
    #define ls x << 1
    #define rs x << 1 | 1
    void pushup(int x) {tmax[x] = max(tmax[ls], tmax[rs]);}
    void update(int x, int t) {tmax[x] += t; tag[x] += t;}
    void pushdown(int x, int l, int r, int mid) {
        if (tag[x]) {
            update(ls, tag[x]); update(rs, tag[x]); tag[x] = 0;
        }
    }
    void build(int x, int l, int r) {
        if (l == r) {tmax[x] = dep[rev[l]]; return;}
        int mid = l + r >> 1;
        build(ls, l, mid); build(rs, mid + 1, r);
        pushup(x);
    }
    void change(int x, int l, int r, int ln, int rn, int t) {
        if (ln <= l && r <= rn) {update(x, t); return;}
        int mid = l + r >> 1; pushdown(x, l, r, mid);
        if (mid >= ln) change(ls, l, mid, ln, rn, t);
        if (mid + 1 <= rn) change(rs, mid + 1, r, ln, rn, t);
        pushup(x);
    }
    int query(int x, int l, int r, int ln, int rn) {
        if (ln <= l && r <= rn) return tmax[x];
        int mid = l + r >> 1, res = 0; pushdown(x, l, r, mid);
        if (mid >= ln) res = max(res, query(ls, l, mid, ln, rn));
        if (mid + 1 <= rn) res = max(res, query(rs, mid + 1, r, ln, rn));
        return res;
    }
}
namespace LCT {
    int son[N][2], fa[N];
    #define ls son[x][0]
    #define rs son[x][1]
    bool l_r(int x) {return x == son[fa[x]][1];}
    bool isroot(int x) {return son[fa[x]][0] != x && son[fa[x]][1] != x;}
    int findrt(int x) {while (ls) x = ls; return x;}
    void rotate(int x) {
        int y = fa[x], z = fa[y], kind = l_r(x);
        if (!isroot(y)) son[z][l_r(y)] = x;
        son[y][kind] = son[x][kind ^ 1]; fa[son[x][kind ^ 1]] = y;
        son[x][kind ^ 1] = y; fa[y] = x; fa[x] = z;
    }
    void splay(int x) {
        for (int y = fa[x]; !isroot(x); y = fa[x]) {
            if (!isroot(y)) rotate(l_r(x) == l_r(y) ? y : x); rotate(x);
        }
    }
    void access(int x) {
        int c;
        for (int y = 0; x; y = x, x = fa[x]) {
            splay(x);
            if (rs) c = findrt(rs), SEG::change(1, 1, n, dfn[c], dfn[c] + siz[c] - 1, 1);
            if (rs = y) c = findrt(y), SEG::change(1, 1, n, dfn[c], dfn[c] + siz[c] - 1, -1);
        }
    }
}
namespace LCA {
    int top[N], son[N], fa[N];
    void dfs1(int u, int last) {
        dep[u] = dep[last] + 1; siz[u] = 1; fa[u] = last;
        for (int e = head[u]; e; e = edge[e].nxt) {
            int v = edge[e].v; if (v == last) continue; dfs1(v, u);
            siz[u] += siz[v]; if (siz[v] > siz[son[u]]) son[u] = v;
        }
    }
    void dfs2(int u, int front) {
        dfn[u] = ++cnt; rev[cnt] = u; top[u] = front; if (son[u]) dfs2(son[u], front);
        for (int e = head[u]; e; e = edge[e].nxt) {
            int v = edge[e].v; if (v == fa[u] || v == son[u]) continue; dfs2(v, v);
        }
    }
    int lca(int x, int y) {
        while (top[x] != top[y]) dep[top[x]] < dep[top[y]] ? y = fa[top[y]] : x = fa[top[x]];
        return dep[x] < dep[y] ? x : y;
    }
}
int main() {
    n = read(); m = read();
    for (int i = 1; i < n; i++) {
        int u = read(), v = read(); add(u, v); add(v, u);
    }
    cnt = 0; LCA::dfs1(1, 0); LCA::dfs2(1, 1); cnt = 0; SEG::build(1, 1, n);
    for (int i = 1; i <= n; i++) LCT::fa[i] = LCA::fa[i];
    for (int i = 1; i <= m; i++) {
        int opt = read(), x = read();
        if (opt == 1) LCT::access(x);
        if (opt == 2) {
            int y = read(), lca = LCA::lca(x, y);
            printf("%d\n", q(dfn[x], dfn[x]) + q(dfn[y], dfn[y]) - 2 * q(dfn[lca], dfn[lca]) + 1);
        }
        if (opt == 3) {
            printf("%d\n", q(dfn[x], dfn[x] + siz[x] - 1));
        }
    }
    return 0;
}