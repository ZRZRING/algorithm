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
struct EDGE{
    int u, v, nxt, flow;
} edge[N];
int n, m, S, T, cnt = -1, head[N], cur[N], dep[N], fa[N], to[N], vis[N];
queue<int>q;
void add(int u, int v, int t) {
    edge[++cnt] = (EDGE){u, v, head[u], t}; head[u] = cnt;
}
void ins(int u, int v, int t) {
    add(u, v, t); add(v, u, 0);
}
int bfs() {
    for (int i = 1; i <= 2 * n + 2; i++) dep[i] = 0, cur[i] = head[i];
    q.push(S); dep[S] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].v;
            if (dep[v] || !edge[i].flow) continue;
            dep[v] = dep[u] + 1; q.push(v);
        }
    }
    return dep[T];
}
int dfs(int u, int limit) {
    if (u == T || !limit) return limit;
    int res = 0;
    for (int i = cur[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v; cur[u] = i;
        if (dep[v] == dep[u] + 1) {
            int tmp = dfs(v, min(limit, edge[i].flow));
            edge[i].flow -= tmp; edge[i ^ 1].flow += tmp;
            res += tmp; limit -= tmp; if (!limit) break;
        }
    }
    if (!res) dep[u] = 0; return res;
}
long long dinic() {
    long long res = 0;
    while (bfs()) res += dfs(S, inf);
    return res;
}
void write(int x) {
    if (!x) return; printf("%d ", x); write(to[x]);
}
int main() {
    memset(head, -1, sizeof(head));
    n = read(); m = read(); S = n * 2 + 1; T = n * 2 + 2;
    for (int i = 1; i <= m; i++) {
        int x = read(), y = read(); ins(x, y + n, 1);
    }
    for (int i = 1; i <= n; i++) {
        ins(S, i, 1); ins(i + n, T, 1);
    }
    int ans = dinic(); vis[0] = 1;
    for (int u = 1; u <= n; u++) {
        for (int i = head[u]; ~i; i = edge[i].nxt) {
            if (edge[i].flow || edge[i].v == S) continue;
            int v = edge[i].v - n; to[u] = v; vis[v] = 1;
        }
    }
    for (int i = 1; i <= n; i++) if (!vis[i]) write(i), printf("\n");
    printf("%d", n - ans);
    return 0;
}