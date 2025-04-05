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
    int u, v, nxt, flow, dis;
} edge[N];
struct PRE{
    int point, edge;
} pre[N];
int n, m, c, t1, t2, c1, c2, t[N], S, T, ans, cnt = -1, head[N], dis[N], vis[N], cur[N], flow[N];
queue<int>q;
void add(int u, int v, int flow, int t) {
    edge[++cnt] = (EDGE){u, v, head[u], flow, t}; head[u] = cnt;
}
void ins(int u, int v, int t, int val) {
    add(u, v, t, val); add(v, u, 0, -val);
}
int spfa() {
    for (int i = 1; i <= 2 * n + 2; i++) {
        dis[i] = flow[i] = inf, cur[i] = head[i], pre[i] = (PRE){0, 0};
    }
    q.push(S); dis[S] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].v;
            if (dis[u] + edge[i].dis < dis[v] && edge[i].flow) {
                dis[v] = dis[u] + edge[i].dis; pre[v] = {u, i};
                flow[v] = min(flow[u], edge[i].flow);
                if (!vis[v]) q.push(v), vis[v] = 1;
            }
        }
        vis[u] = 0;
    }
    return dis[T] != inf;
}
long long dinic() {
    long long res = 0;
    while (spfa()) {
        res += 1ll * flow[T] * dis[T]; int x = T;
        while (x != S) {
            edge[pre[x].edge].flow -= flow[T];
            edge[pre[x].edge ^ 1].flow += flow[T];
            x = pre[x].point;
        }
    }
    return res;
}
int main() {
    memset(head, -1, sizeof(head)); n = read();
    for (int i = 1; i <= n; i++) t[i] = read();
    c = read(); t1 = read(); c1 = read(); t2 = read(); c2 = read();
    S = 2 * n + 1; T = 2 * n + 2;
    for (int i = 1; i <= n; i++) {
        ins(i, T, t[i], 0); ins(S, i + n, t[i], 0); ins(S, i, inf, c);
        if (i + 1 <= n) ins(i, i + 1, inf, 0);
        if (i + t1 <= n) ins(i + n, i + t1, inf, c1);
        if (i + t2 <= n) ins(i + n, i + t2, inf, c2);
    }
    printf("%lld", dinic());
    return 0;
}