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
int n, m, S, T, a[N], dp[N], head[N], cur[N], cnt = -1, dep[N], ans;
queue<int>q;
void add(int u, int v, int f) {
    edge[++cnt] = (EDGE){u, v, head[u], f}; head[u] = cnt;
}
void ins(int u, int v, int f) {
    // printf("%d %d %d\n", u, v, f);
    add(u, v, f); add(v, u, 0);
}
int bfs() {
    for (int i = 0; i <= n + n + 2; i++) dep[i] = 0, cur[i] = head[i];
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
    if (u == T || !limit) return limit; int res = 0;
    for (int i = cur[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v; cur[u] = i;
        if (dep[v] == dep[u] + 1) {
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
    n = read(); S = n + n + 1; T = n + n + 2;
    if (n == 1) {printf("1\n1\n1"); return 0;}

    //q1
    int s = 0;
    for (int i = 1; i <= n; i++) a[i] = read(), dp[i] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (a[j] <= a[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
        s = max(s, dp[i]);
    }
    printf("%d\n", s);

    //q2
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= n; i++) {
        ins(i, i + n, 1);
        if (dp[i] == 1) ins(S, i, 1);
        if (dp[i] == s) ins(i + n, T, 1);
        for (int j = 1; j < i; j++) {
            if (dp[j] + 1 == dp[i] && a[j] <= a[i]) {
                ins(j + n, i, 1);
            }
        }
    }
    dinic(); printf("%d\n", ans);

    //q3
    ins(S, 1, inf); ins(1, n + 1, inf);
    if (dp[n] == s) ins(n, T, inf); ins(n, n + n, inf);
    dinic(); printf("%d", ans);

    return 0;
}