#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'
#define PII std::pair<int, int>
#define init_0(x) memset(x, 0, sizeof(x))
#define init_inf(x) memset(x, 0x3f, sizeof(x))

inline int64 read() {
    bool sym = 0; int64 res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}

const int64 mod = 998244353, N = 2e5 + 10;

struct EDGE {
    int u, v, nxt, dis;
} edge[N];

int n, m, cnt, head[N], to[N];

int fa[N], top[N], siz[N], son[N], dep[N], dfn[N];

int64 dis[N], f1[N], f2[N], g[N];

void add(int u, int v, int t) {
    edge[++cnt] = (EDGE){u, v, head[u], t};
    head[u] = cnt;
}

void dfs1(int u, int last) {
    siz[u] = 1; fa[u] = last; dep[u] = dep[last] + 1; dfn[u] = ++cnt;
    for (int e = head[u]; e; e = edge[e].nxt) {
        int v = edge[e].v;
        if (v == last) continue;
        dis[v] = dis[u] + edge[e].dis;
        dfs1(v, u);
        siz[u] += siz[v];
        if (siz[v] > siz[son[u]]) son[u] = v;
    }
}

void dfs2(int u, int front) {
    top[u] = front;
    if (son[u]) dfs2(son[u], front);
    for (int e = head[u]; e; e = edge[e].nxt) {
        int v = edge[e].v;
        if (v == fa[u] || v == son[u]) continue; dfs2(v, v);
    }
}

void dfs3(int u) {
    for (int e = head[u]; e; e = edge[e].nxt) {
        int v = edge[e].v, t = edge[e].dis;
        if (v == fa[u]) continue; dfs3(v);
        if (f1[v] + t > f1[u]) f2[u] = f1[u], f1[u] = f1[v] + t, to[u] = v;
        else if (f1[v] + t > f2[u]) f2[u] = f1[v] + t;
    }
}

void dfs4(int u) {
    for (int e = head[u]; e; e = edge[e].nxt) {
        int v = edge[e].v, t = edge[e].dis;
        if (v == fa[u]) continue;
        if (v == to[u]) g[v] = std::max(f2[u], g[u]) + t;
        else g[v] = std::max(f1[u], g[u]) + t;
        dfs4(v);
    }
}

bool check(int x, int y) {
    while (top[x] != top[y]) {
        x = top[x];
        if (fa[x] == y) {
            if (to[y] == x) return 1; else return 0;
        }
        if (dep[x] <= dep[y]) return 0;
        x = fa[x];
    }
    return son[y] == to[y];
}

int64 lca(int x, int y) {
    int64 res = 0;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
        res += dis[x] - dis[fa[top[x]]], x = fa[top[x]];
    }
    if (dep[x] < dep[y]) std::swap(x, y);
    return res + dis[x] - dis[y];
}

int main() {
    n = read(); m = read();
    for (int i = 1; i < n; i++) {
        int u = read(), v = read(), t = read();
        add(u, v, t); add(v, u, t);
    }
    cnt = 0;
    dfs1(1, 0); dfs2(1, 1); dfs3(1); dfs4(1);
    for (int i = 1; i <= m; i++) {
        int x = read(), y = read();
        if (dep[x] < dep[y]) std::swap(x, y);
        if (x == y) {
            printf("%lld\n", f1[x] + std::max(f2[x], g[x]));
            continue;
        }
        if (dep[x] != dep[y] && dfn[y] <= dfn[x] && dfn[x] <= dfn[y] + siz[y]) {
            if (check(x, y)) printf("%lld\n", std::max(f2[y], g[y]) + f1[x] + lca(x, y));
            else printf("%lld\n", std::max(f1[y], g[y]) + f1[x] + lca(x, y));
        } else {
            printf("%lld\n", f1[x] + f1[y] + lca(x, y));
        }
    }
    return 0;
}