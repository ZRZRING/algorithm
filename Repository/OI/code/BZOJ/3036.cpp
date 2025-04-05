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
    int u, v, dis, nxt;
} edge[N];
int n, m, vis[N], cd[N], head[N], cnt;
double f[N];
void add(int u, int v, int t) {edge[++cnt] = (EDGE){u, v, t, head[u]}; head[u] = cnt;}
void dfs(int u) {
    if (!vis[u]) vis[u] = 1; else return;
    for (int e = head[u]; e; e = edge[e].nxt) {
        int v = edge[e].v; dfs(v); f[u] += edge[e].dis + f[v];
    }
    if (cd[u]) f[u] /= cd[u];
}
int main() {
    n = read(); m = read();
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read(), t = read(); add(u, v, t); cd[u]++;
    }
    dfs(1);
    printf("%.2lf", f[1]);
    return 0;
}