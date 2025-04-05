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
} edge[N], Edge[N];
int n, m, head[N], Head[N], cnt, val[N], dfn[N], low[N], s[N], top;
int color[N], scnt, Val[N], d[N], dis[N], ans;
queue<int>q;
void add(int u, int v) {edge[++cnt] = (EDGE){u, v, head[u]}; head[u] = cnt;}
void Add(int u, int v) {Edge[++cnt] = (EDGE){u, v, Head[u]}; Head[u] = cnt;}
void dfs(int u) {
    dfn[u] = low[u] = ++cnt; s[++top] = u;
    for (int e = head[u]; e; e = edge[e].nxt) {
        int v = edge[e].v;
        if (!dfn[v]) {
            dfs(v); low[u] = min(low[u], low[v]);
        } else if (!color[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        color[u] = ++scnt; Val[scnt] += val[u];
        while (s[top] != u) {color[s[top]] = scnt; Val[scnt] += val[s[top]]; top--;} top--;
    }
}
int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; i++) val[i] = read();
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read(); add(u, v);
    }
    cnt = 0;
    for (int i = 1; i <= n; i++) if (!dfn[i]) dfs(i);
    cnt = 0;
    for (int u = 1; u <= n; u++) {
        for (int e = head[u]; e; e = edge[e].nxt) {
            int v = edge[e].v; if (color[u] != color[v]) Add(color[u], color[v]), d[color[v]]++;
        }
    }
    for (int i = 1; i <= scnt; i++) {
        if (!d[i]) q.push(i), dis[i] = Val[i];
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int e = Head[u]; e; e = Edge[e].nxt) {
            int v = Edge[e].v; dis[v] = max(dis[v], Val[v] + dis[u]);
            d[v]--; if (!d[v]) q.push(v);
        }
    }
    for (int i = 1; i <= scnt; i++) ans = max(ans, dis[i]);
    printf("%d", ans);
    return 0;
}