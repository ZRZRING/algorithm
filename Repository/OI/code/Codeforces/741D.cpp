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
const int N = 1e6 + 10, V = 2e7 + 10, inf = 1e9;
inline int read() {
    bool sym = 0; int res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
struct EDGE {
    int u, v, nxt, dis;
} edge[N];
int n, m, head[N], cnt, siz[N], son[N], po[N], L[N], R[N], dis[N], ans[N], mx[V], dep[N];
char ch[N];
void add(int u, int v, int t) {edge[++cnt] = (EDGE){u, v, head[u], t}; head[u] = cnt;}
void dfs1(int u) {
    siz[u] = 1; L[u] = ++cnt; po[cnt] = u;
    for (int e = head[u]; e; e = edge[e].nxt) {
        int v = edge[e].v; dis[v] = dis[u] ^ edge[e].dis; dep[v] = dep[u] + 1;
        dfs1(v); siz[u] += siz[v]; if (siz[v] > siz[son[u]]) son[u] = v;
    }
    R[u] = cnt;
}
void dfs2(int u, bool keep) {
    for (int e = head[u]; e; e = edge[e].nxt) {
        int v = edge[e].v; if (v == son[u]) continue;
        dfs2(v, 0); ans[u] = max(ans[u], ans[v]);
    }
    if (son[u]) dfs2(son[u], 1), ans[u] = max(ans[u], ans[son[u]]);
    ans[u] = max(ans[u], mx[dis[u]] - dep[u]);
    for (int i = 0; i <= 21; i++) ans[u] = max(ans[u], mx[dis[u] ^ 1 << i] - dep[u]);
    mx[dis[u]] = max(mx[dis[u]], dep[u]);
    for (int e = head[u]; e; e = edge[e].nxt) {
        int v = edge[e].v; if (v == son[u]) continue;
        for (int i = L[v], x = po[i]; i <= R[v]; i++, x = po[i]) {
            ans[u] = max(ans[u], mx[dis[x]] + dep[x] - 2 * dep[u]);
            for (int i = 0; i <= 21; i++) ans[u] = max(ans[u], mx[dis[x] ^ 1 << i] + dep[x] - 2 * dep[u]);
        }
        for (int i = L[v], x = po[i]; i <= R[v]; i++, x = po[i]) {
            mx[dis[x]] = max(mx[dis[x]], dep[x]);
        }
    }
    if (!keep) {for (int i = L[u], x = po[i]; i <= R[u]; i++, x = po[i]) mx[dis[x]] = -inf;}
}
int main() {
    n = read(); memset(mx, 128, sizeof(mx));
    for (int v = 2; v <= n; v++) {
        int u = read(); char t = getchar(); add(u, v, 1ll << t - 'a');
    }
    dep[1] = 1; dfs1(1); dfs2(1, 1); for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    return 0;
}