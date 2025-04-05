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
const int N = 1e7 + 10;
inline int read() {
    int sym = 0, res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
struct EDGE {
    int u, v, nxt, dis;
} edge[N];
int n, m, rt, siz[N], head[N], cnt, vis[N], maxs[N], query[N];
int sum, tcnt, dis[N], tmp[N], est[N], ans[N], q[N];
void add(int u, int v, int t) {edge[++cnt] = (EDGE){u, v, head[u], t}; head[u] = cnt;}
void getrt(int u, int last) {
    siz[u] = 1; maxs[u] = 0;
    for (int e = head[u]; e; e = edge[e].nxt) {
        int v = edge[e].v; if (v == last || vis[v]) continue;
        getrt(v, u); siz[u] += siz[v]; maxs[u] = max(maxs[u], siz[v]);
    }
    maxs[u] = max(maxs[u], sum - siz[u]); if (maxs[u] < maxs[rt]) rt = u;
}
void getdis(int u, int last) {
    tmp[++tcnt] = dis[u];
    for (int e = head[u]; e; e = edge[e].nxt) {
        int v = edge[e].v; if (v == last || vis[v]) continue;
        dis[v] = dis[u] + edge[e].dis; getdis(v, u);
    }
}
void cal(int u) {
    cnt = 0;
    for (int e = head[u]; e; e = edge[e].nxt) {
        int v = edge[e].v; if (vis[v]) continue;
        tcnt = 0; dis[v] = edge[e].dis; getdis(v, u);
        for (int i = tcnt; i >= 1; i--) {
            for (int j = 1; j <= m; j++) {
                if (query[j] >= tmp[i]) ans[j] |= est[query[j] - tmp[i]];
            }
        }
        for (int i = tcnt; i >= 1; i--) q[++cnt] = tmp[i], est[tmp[i]] = 1;
    }
    for (int i = 1; i <= cnt; i++) est[q[i]] = 0;
}
void solve(int u) {
    vis[u] = est[0] = 1; cal(u);
    for (int e = head[u]; e; e = edge[e].nxt) {
        int v = edge[e].v; if (vis[v]) continue;
        sum = siz[v]; rt = 0; maxs[rt] = inf; getrt(v, 0); solve(rt);
    }
}
int main() {
	n = read(); m = read();
    for (int i = 1, u, v, t; i < n; i++) {
        u = read(); v = read(); t = read(); add(u, v, t); add(v, u, t);
    }
    for (int i = 1; i <= m; i++) query[i] = read();
    maxs[rt] = sum = n; getrt(1, 0); solve(rt);
    for (int i = 1; i <= m; i++) printf(ans[i] ? "AYE\n" : "NAY\n");
    return 0;
}