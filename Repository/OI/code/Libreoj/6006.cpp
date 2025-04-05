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
    int u, v, nxt, flow;
} edge[N];
int n, m, S, T, nd[N], head[N], cur[N], cnt = -1, sum, dep[N], ans;
void add(int u, int v, int t) {edge[++cnt] = (EDGE){u, v, head[u], t}; head[u] = cnt;}
void ins(int u, int v, int t) {add(u, v, t); add(v, u, 0);}
queue<int>q;
int bfs() {
    for (int i = 0; i <= n + m + 2; i++) dep[i] = 0, cur[i] = head[i];
    q.push(S); dep[S] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int e = head[u]; ~e; e = edge[e].nxt) {
            int v = edge[e].v;
            if (dep[v] || !edge[e].flow) continue;
            q.push(v); dep[v] = dep[u] + 1;
        }
    }
    return dep[T];
}
int dfs(int u, int limit) {
    if (!limit || u == T) return limit; int res = 0;
    for (int e = cur[u]; ~e; e = edge[e].nxt) {
        int v = edge[e].v; cur[u] = e;
        if (dep[v] != dep[u] + 1) continue;
        int tmp = dfs(v, min(limit, edge[e].flow));
        edge[e].flow -= tmp; edge[e ^ 1].flow += tmp;
        limit -= tmp; res += tmp; if (!limit) break;
    }
    if (!res) dep[u] = 0; return res;
}
void dinic() {
    while (bfs()) ans += dfs(S, inf);
}
int main() {
    m = read(); n = read(); memset(head, -1, sizeof(head)); S = n + m + 1; T = n + m + 2;
    for (int i = 1; i <= m; i++) {
        nd[i] = read(); ins(i, T, nd[i]); sum += nd[i];
    }
    for (int i = 1; i <= n; i++) {
        int tp = read(); ins(S, m + i, 1);
        for (int j = 1; j <= tp; j++) {
            int x = read(); ins(m + i, x, 1);   
        }
    }
    dinic(); if (ans < sum) {printf("No Solution!"); return 0;}
    for (int u = 1; u <= m; u++) {
        printf("%d: ", u);
        for (int e = head[u]; ~e; e = edge[e].nxt) {
            int v = edge[e].v; if (v == S || v == T) continue;
            if (edge[e].flow) printf("%d ", v - m);
        }
        printf("\n");
    }
    return 0;
}