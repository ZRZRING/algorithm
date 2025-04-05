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
int n, m, head[N], cnt, S;
int fa[N], dep[N], siz[N], son[N], top[N];
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
        int v = edge[e].v; if (v == fa[u] || v == son[u]) continue; dfs2(v, v);
    }
}
int lca(int x, int y) {
    while (top[x] != top[y]) dep[top[x]] < dep[top[y]] ? y = fa[top[y]] : x = fa[top[x]];
    return dep[x] < dep[y] ? x : y;
}
int main() {
    n = read(); m = read(); S = read();
    for (int i = 1; i < n; i++) {
        int u = read(), v = read(); add(u, v); add(v, u);
    }
    dfs1(S, 0); dfs2(S, S);
    for (int i = 1; i <= m; i++) {
        int x = read(), y = read(); printf("%d\n", lca(x, y));
    }
    return 0;
}
