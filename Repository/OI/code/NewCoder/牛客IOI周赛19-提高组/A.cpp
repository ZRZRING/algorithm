#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

#define mp(x, y) make_pair(x, y)

using namespace std;

void file() {
    freopen("std.in", "r", stdin);
    freopen("wa.out", "w", stdout);
}

const int N = 1e6 + 10, M = 2e6 + 10, inf = 0x3f3f3f3f;

inline int read() {
    bool sym = 0; int res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}

struct EDGE {
    int u, v, nxt, dis;
} edge[N], kru[N];

int n, m, head[N], cnt, dis[N], vis[N], fa[N], to[N];

priority_queue<pair<int, int> >q;

void add(int u, int v, int t) {edge[++cnt] = (EDGE){u, v, head[u], t}; head[u] = cnt;}

bool cmp(EDGE a, EDGE b) {return a.dis < b.dis;}

int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read(), t = read(); add(u, v, t); add(v, u, t);
    }
    int k = read(); memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= k; i++) {int x = read(); q.push(mp(0, x)); to[x] = x; dis[x] = 0;}
    while (!q.empty()) {
        int u = q.top().second; q.pop(); if (vis[u]) continue; vis[u] = 1;
        for (int e = head[u]; e; e = edge[e].nxt) {
            int v = edge[e].v, d = edge[e].dis;
            if (dis[u] + d < dis[v]) dis[v] = dis[u] + d, to[v] = to[u], q.push(mp(-dis[v], v));
        }
    }
    cnt = 0;
    for (int u = 1; u <= n; u++) {
        for (int e = head[u]; e; e = edge[e].nxt) {
            int v = edge[e].v, d = edge[e].dis;
            if (to[u] != to[v]) {
                kru[++cnt] = (EDGE){to[u], to[v], 0, dis[u] + dis[v] + d};
            }
        }
    }
    for (int i = 1; i <= cnt; i++) {
        printf("%d %d %d\n", kru[i].u, kru[i].v, kru[i].dis);
    }
    sort(kru + 1, kru + cnt + 1, cmp); int ans = 0;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= n; i++) {
        int fu = find(kru[i].u), fv = find(kru[i].v);
        if (fu != fv) fa[fu] = fv, ans = kru[i].dis;
    }
    printf("%d", ans);
    return 0;
}