#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

void file() {
    freopen("snackstore.in", "r", stdin);
    freopen("snackstore.out", "w", stdout);
}

const int N = 110, M = 1e4 + 10, inf = 1e9;

inline int read() {
    bool sym = 0; int res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}

struct EDGE {
    int u, v, nxt, dis;
} edge[M << 1];

int n, m, head[N], cnt, dis[N], limit[N];
bool vis[N], p[N];
queue<int>q;

void add(int u, int v, int t) {edge[++cnt] = (EDGE){u, v, head[u], t}; head[u] = cnt;}

int bfs(int s, int c, int d) {
    memset(vis, 0, sizeof(vis)); memset(dis, 0x3f, sizeof(dis)); memset(p, 0, sizeof(p));
    q.push(s); vis[s] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int e = head[u]; e; e = edge[e].nxt) {
            int v = edge[e].v; dis[v] = min(dis[v], dis[u] + edge[e].dis); p[v] = 1;
            if (!vis[v] && limit[v] <= c && dis[v] <= d) {q.push(v); vis[v] = 1;}
        }
    }
    int res = 0; for (int i = 1; i <= n; i++) res += p[i]; return res;
}

int main() { file();
    n = read(); m = read(); int Q = read();
    for (int i = 1; i <= n; i++) limit[i] = read();
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read(), t = read(); add(u, v, t); add(v, u, t);
    }
    for (int i = 1; i <= Q; i++) {
        int s = read(), c = read(), d = read();
        printf("%d\n", bfs(s, c, d));
    }
    return 0;
}