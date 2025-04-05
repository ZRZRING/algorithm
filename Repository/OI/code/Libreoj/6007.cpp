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
const int N = 5e6 + 10;
inline int read() {
    int sym = 0, res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
struct EDGE {
    int u, v, nxt, flow;
} edge[N];
int n, m, S, T, ans, cnt = -1, head[N], dep[N], cur[N];
queue<int>q;
int cal(int x, int y) {return (x - 1) * m + y;}
void add(int u, int v, int t) {edge[++cnt] = (EDGE){u, v, head[u], t}; head[u] = cnt;}
void ins(int u, int v, int t) {add(u, v, t); add(v, u, 0);}
int bfs() {
    for (int i = 0; i <= n * m + 2; i++) {dep[i] = 0; cur[i] = head[i];}
    q.push(S); dep[S] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int e = head[u]; ~e; e = edge[e].nxt) {
            int v = edge[e].v;
            if (dep[v] || !edge[e].flow) continue;
            dep[v] = dep[u] + 1; q.push(v);
        }
    }
    return dep[T];
}
int dfs(int u, int limit) {
    if (!limit || u == T) return limit; int res = 0;
    for (int e = head[u]; ~e; e = edge[e].nxt) {
        int v = edge[e].v; cur[u] = e;
        if (dep[v] != dep[u] + 1) continue;
        int tmp = dfs(v, min(limit, edge[e].flow));
        edge[e].flow -= tmp; edge[e ^ 1].flow += tmp;
        limit -= tmp; res += tmp; if (!limit) break;
    }
    return res;
}
void dinic() {
    while (bfs()) ans -= dfs(S, inf);
}
int main() {
    n = read(); m = read(); S = n * m + 1; T = n * m + 2;
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x = read(); ans += x;
            if ((i + j) % 2) ins(S, cal(i, j), x);
            else ins(cal(i, j), T, x);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if ((i + j) % 2) {
                if (i < n) ins(cal(i, j), cal(i + 1, j), inf);
                if (j < m) ins(cal(i, j), cal(i, j + 1), inf);
                if (i > 1) ins(cal(i, j), cal(i - 1, j), inf);
                if (j > 1) ins(cal(i, j), cal(i, j - 1), inf);
            }
        }
    }
    dinic(); printf("%d", ans);
    return 0;
}