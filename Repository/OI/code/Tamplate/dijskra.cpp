#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define mp(x, y) make_pair(x, y)
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
    int u, v, nxt, dis;
} edge[N];
int n, m, s, head[N], cnt, dis[N], vis[N];
void add(int u, int v, int t) {edge[++cnt] = (EDGE){u, v, head[u], t}; head[u] = cnt;}
priority_queue<pair<int, int> >q;
void dij() {
    memset(dis, 0x3f, sizeof(dis)); dis[s] = 0; q.push(mp(0, s));
    while (!q.empty()) {
        int u = q.top().second; q.pop();
        if (vis[u]) continue; vis[u] = 1;
        for (int e = head[u]; e; e = edge[e].nxt) {
            int v = edge[e].v;
            if (dis[u] + edge[e].dis < dis[v]) {
                dis[v] = dis[u] + edge[e].dis;
                q.push(mp(-dis[v], v));
            }
        }
    }
}
int main() {
    n = read(); m = read(); s = read();
    for (int i = 1, u, v, t; i <= m; i++) {
        u = read(), v = read(), t = read(); add(u, v, t);
    }
    dij(); for (int i = 1; i <= n; i++) printf("%d ", dis[i]);
    return 0;
}