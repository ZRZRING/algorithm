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
int n, m, S, T, head[N], cur[N], ans, maxf, cnt = -1, dep[N];
queue<int>q;
void add(int u, int v, int f) {
    edge[++cnt] = (EDGE){u, v, head[u], f}; head[u] = cnt;
}
void ins(int u, int v, int f) {
    add(u, v, f); add(v, u, 0);
}
int bfs() {
    for (int i = 0; i <= n + m + 2; i++) dep[i] = 0, cur[i] = head[i];
    q.push(S); dep[S] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].v;
            if (dep[v] || !edge[i].flow) continue;
            q.push(v); dep[v] = dep[u] + 1;
        }
    }
    return dep[T];
}
int dfs(int u, int limit) {
    if (u == T || !limit) return limit; int res = 0;
    for (int i = cur[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v; cur[u] = i;
        if (dep[u] + 1 == dep[v]) {
            int tmp = dfs(v, min(limit, edge[i].flow));
            edge[i].flow -= tmp; edge[i ^ 1].flow += tmp;
            limit -= tmp; res += tmp; if (!limit) break;
        }
    }
    if (!res) dep[u] = 0; return res;
}
void dinic() {
    while (bfs()) ans += dfs(S, inf);
}
int main() {
    memset(head, -1, sizeof(head));
    n = read(); m = read(); S = n + m + 1; T = n + m + 2;
    for (int i = 1; i <= n; i++) {int x = read(); ins(S, i, x); maxf += x;}
    for (int i = 1; i <= m; i++) {int x = read(); ins(i + n, T, x);}
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ins(i, j + n, 1);
        }
    }
    dinic(); if (ans != maxf) {puts("0"); return 0;}
    printf("1\n");
    for (int u = 1; u <= n; u++) {
        for (int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].v;
            if (!edge[i].flow) printf("%d ", edge[i].v - n);
        }
        printf("\n");
    }
    return 0;
}