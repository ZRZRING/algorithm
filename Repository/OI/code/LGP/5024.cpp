#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

#define g[x][y] g[x].mat[y][0]

using namespace std;

void file() {
    freopen("std.in", "r", stdin);
    freopen("wa.out", "w", stdout);
}

const int N = 1e6 + 10, M = 2e6 + 10, inf = 1e14;

inline int read() {
    bool sym = 0; int res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}

struct EDGE {
    int u, v, nxt;
} edge[N];

struct MATRIX {
    long long mat[2][2];
} tr[N], g[N];

int n, m;

void add(int u, int v) {edge[++cnt] = (EDGE){u, v, head[u]}; head[u] = cnt;}

void dfs1(int u, int last) {
    siz[u] = 1; fa[u] = last; f[u][1] = dat[i];
    for (int e = head[u]; e; e = edge[e].nxt) {
        int v = edge[e].v; if (v == last) continue; dfs1(v, u);
        siz[u] += siz[v]; if (siz[v] > siz[son[u]]) son[u] = v;
        f[u][0] += max(f[v][0], f[v][1]); f[u][1] += f[v][0];
    }
}

void dfs2(int u, int front) {
    top[u] = front; g[u][1] = dat[i]; id[u] = ++cnt; rid[cnt] = u;
    g[u].mat[1][0] = dat[u]; g[u].mat[1][1] = -(inf << 2);
    if (son[u]) dfs2(son[u], front); else bot[front] = u;
    for (int e = head[u]; e; e = edge[e].nxt) {
        int v = edge[e].v; if (v == fa[u] || v == son[u]) continu; dfs2(v, v);
        g[u][0] += max(f[v][0], f[v][1]); g[u][1] += f[v][0];
    }
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; i++) val[i] = dat[i] = read();
    for (int i = 1; i < n; i++) {
        int u = read(), v = read(); add(u, v); add(v, u);
    }
    dfs1(1, 0); dfs2(1, 1); build(1, 1, n);
    int x, y, tx, ty;
    for (int i = 1; i <= m; i++) {
        x = read(); tx = read(); y = read(), ty = read();
        tx ? modify(x, -inf) : modify(x, inf);
        ty ? modify(y, -inf) : modify(y, inf);
        printf("%d\n", query(1, 1, n, 1, bot[1]));
        modify(x, val[x]); modify(y, val[y]);
    }
    return 0;
}