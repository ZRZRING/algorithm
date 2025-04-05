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
const int N = 5e5 + 10;
bool ent = 0;
inline int read() {
    int sym = 0, res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    if (ch == '\n') ent = 1;
    return sym ? -res : res;
}
struct EDGE{
    int u, v, nxt, dis;
} edge[N];
bool vis[N];
int n, m, S, T, head[N], cnt = -1, ans, cur[N], dep[N];
queue<int>q;
void add(int u, int v, int t) {
    edge[++cnt] = (EDGE){u, v, head[u], t}; head[u] = cnt;
}
void insert(int u, int v, int t) {add(u, v, t); add(v, u, 0);}
int bfs() {
    for (int i = 0; i <= 200; i++) dep[i] = 0, cur[i] = head[i];
    dep[S] = 1; q.push(S);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].v; 
            if (dep[v] || edge[i].dis <= 0) continue;
            dep[v] = dep[u] + 1; q.push(v);
        }
    }
    return dep[T];
}
int dfs(int u, int limit) {
    if (u == T || !limit) return limit; int res = 0;
    for (int i = cur[u]; ~i; i = edge[i].nxt) {
        cur[u] = i; int v = edge[i].v;
        if (dep[v] == dep[u] + 1) {
            int tmp = dfs(v, min(limit, edge[i].dis));
            edge[i].dis -= tmp; edge[i ^ 1].dis += tmp;
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
    m = read(); n = read(); int tmp = 0; S = n + m + 1; T = n + m + 2;
    for (int i = 1; i <= m; i++) {
        int x = read(); insert(S, i, x); tmp += x; 
        ent = 0; while (!ent) {int x = read(); insert(i, m + x, inf);}
    }
    for (int i = 1; i <= n; i++) {
        int t = read(); insert(m + i, T, t);
    }
    dinic(); int flag = 0;
    for (int i = 1; i <= m; i++) {
        if (dep[i]) {
            if(flag) printf(" "); printf("%d", i); flag = 1;
        }
    }
    printf("\n"); flag = 0;
    for (int i = 1; i <= n; i++) {
        if (dep[m + i]) {
            if (flag) printf(" "); printf("%d", i); flag = 1;
        }
    }
    printf("\n%d", tmp - ans);
    return 0;
}