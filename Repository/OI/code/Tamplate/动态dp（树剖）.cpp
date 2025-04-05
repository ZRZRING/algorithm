#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

#define ls x << 1
#define rs x << 1 | 1

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

struct MATRIX {
    int mat[2][2];
    MATRIX() {memset(mat, 0, sizeof(mat));}
} tr[N], g[N];

struct EDGE {
    int u, v, nxt;
} edge[N];

int n, m, dat[N], head[N], cnt, f[N][2];
int fa[N], siz[N], son[N], top[N], id[N], rid[N], bot[N];

MATRIX operator * (const MATRIX x1, const MATRIX x2) {
    MATRIX x;
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {
            for (int k = 0; k <= 1; k++) {
                x.mat[i][j] = max(x.mat[i][j], x1.mat[i][k] + x2.mat[k][j]);
            }
        }
    }
    return x;
}

void add(int u, int v) {edge[++cnt] = (EDGE){u, v, head[u]}; head[u] = cnt;}

void dfs1(int u, int last) {
    fa[u] = last; siz[u] = 1; f[u][1] = dat[u];
    for (int e = head[u]; e; e = edge[e].nxt) {
        int v = edge[e].v; if (v == last) continue; dfs1(v, u);
        siz[u] += siz[v]; if (siz[v] > siz[son[u]]) son[u] = v;
        f[u][1] += f[v][0]; f[u][0] += max(f[v][0], f[v][1]);
    }
}

void dfs2(int u, int front) {
    top[u] = front; id[u] = ++cnt; rid[cnt] = u;
    g[u].mat[1][0] = dat[u]; g[u].mat[1][1] = -inf;
    if (son[u]) dfs2(son[u], front); else {bot[front] = cnt; return;}
    for (int e = head[u]; e; e = edge[e].nxt) {
        int v = edge[e].v; if (v == fa[u] || v == son[u]) continue; dfs2(v, v);
        g[u].mat[0][0] += max(f[v][0], f[v][1]); g[u].mat[1][0] += f[v][0];
    }
    g[u].mat[0][1] = g[u].mat[0][0];
}

void pushup(int x) {tr[x] = tr[ls] * tr[rs];}

void build(int x, int l, int r) {
    if (l == r) {tr[x] = g[rid[l]]; return;} int mid = l + r >> 1;
    build(ls, l, mid); build(rs, mid + 1, r); pushup(x);
}

void modify(int x, int l, int r, int pos) {
    if (l == r) {tr[x] = g[rid[l]]; return;} int mid = l + r >> 1;
    if (mid >= pos) modify(ls, l, mid, pos); else modify(rs, mid + 1, r, pos); pushup(x);
}

MATRIX query(int x, int l, int r, int ln, int rn) {
    if (ln <= l && r <= rn) return tr[x]; int mid = l + r >> 1;
    if (mid >= rn) return query(ls, l, mid, ln, rn);
    if (mid + 1 <= ln) return query(rs, mid + 1, r, ln, rn);
    return query(ls, l, mid, ln, rn) * query(rs, mid + 1, r, ln, rn);
}

void modify(int x, int t) {
    g[x].mat[1][0] += t - dat[x]; dat[x] = t;
    while (x) {
        MATRIX last = query(1, 1, n, id[top[x]], bot[top[x]]);
        modify(1, 1, n, id[x]);
        MATRIX now = query(1, 1, n, id[top[x]], bot[top[x]]);
        x = fa[top[x]];
        g[x].mat[0][0] += max(now.mat[0][0], now.mat[1][0]);
        g[x].mat[0][0] -= max(last.mat[0][0], last.mat[1][0]);
        g[x].mat[0][1] = g[x].mat[0][0];
        g[x].mat[1][0] += now.mat[0][0] - last.mat[0][0];
    }
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; i++) dat[i] = read();
    for (int i = 1; i < n; i++) {int u = read(), v = read(); add(u, v); add(v, u);}
    cnt = 0; dfs1(1, 0); dfs2(1, 1); build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int x = read(), t = read(); modify(x, t);
        MATRIX ans = query(1, 1, n, 1, bot[1]); printf("%d\n", max(ans.mat[0][0], ans.mat[1][0]));
    }
    return 0;
}