#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
#define inf 2e9
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
int n, m, S, T, head[N], dep[N], cnt = -1, ans, cur[N];
struct EDGE{
    int u, v, nxt, dis;
}edge[N];
queue<int>q;
void add(int u, int v, int t) {
    edge[++cnt] = (EDGE){u, v, head[u], t}; head[u] = cnt;
}
int bfs() {
    for (int i = 0; i <= n; i++) dep[i] = 0, cur[i] = head[i];
    q.push(S); dep[S] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].v;
            if (dep[v] || !edge[i].dis) continue;
            dep[v] = dep[u] + 1; q.push(v);
        }
    }
    return dep[T];
}
int dfs(int u, int limit) {
    if (!limit || u == T) return limit; int res = 0;
    for (int i = cur[u]; ~i; i = edge[i].nxt) {
        cur[u] = i; int v = edge[i].v;
        if (dep[v] == dep[u] + 1) {
            int tmp = dfs(v, min(limit, edge[i].dis));
            edge[i].dis -= tmp; edge[i ^ 1].dis += tmp;
            res += tmp; limit -= tmp; if (!limit) break;
        }
    }
    return res;
}
void dinic() {
    while (bfs()) ans += dfs(S, inf);
}
signed main() {
    memset(head, -1, sizeof(head));
    n = read(); m = read(); S = read(); T = read();
    for (int i = 1; i <= m; i++) {
        int x = read(), y = read(), t = read(); add(x, y, t); add(y, x, 0);
    }
    dinic(); printf("%lld\n", ans);
    return 0;
}