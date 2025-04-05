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
int n, m, dfn[N], cnt, head[N], low[N], ans[N], tot;
void add(int u, int v) {edge[++cnt] = (EDGE){u, v, head[u]}; head[u] = cnt;}
void dfs(int u, int root) {
    dfn[u] = low[u] = ++cnt; int child = 0;
    for (int e = head[u]; e; e = edge[e].nxt) {
        int v = edge[e].v;
        if (!dfn[v]) {
            dfs(v, root); low[u] = min(low[u], low[v]);
            if (u != root && low[v] >= dfn[u]) ans[u] = 1;
            if (u == root) child++;
        } else {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (u == root && child >= 2) ans[u] = 1;
}
int main() {
    n = read(); m = read();
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read(); add(u, v); add(v, u);
    }
    cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) dfs(i, i);
    }
    for (int i = 1; i <= n; i++) if (ans[i]) tot++;
    printf("%d\n", tot);
    for (int i = 1; i <= n; i++) if (ans[i]) printf("%d ", i);
    return 0;
}