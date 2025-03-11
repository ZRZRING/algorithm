> 给一堆双关键字元素，找到一组元素使得元素数量最多且满足双关键字单调

实际上按第一关键字排序就成了LIS，然后我选择建图找最长路

```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

void file() {
    freopen("std.in", "r", stdin);
    freopen("wa.out", "w", stdout);
}

const int N = 1e4 + 10, M = 2e6 + 10, inf = 1e9;

inline int read() {
    bool sym = 0; int res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}

int n, m, cnt, x[N], y[N], d[N], dis[N], pre[N], id[N];

bool vis[5010][5010];

queue<int>q;

void dfs(int x) {if (pre[x]) dfs(pre[x]); printf("%d ", id[x]);}

int main() {
    n = read(); x[0] = read(); y[0] = read();
    for (int i = 1; i <= n; i++) {
        int tx = read(), ty = read(); if (tx <= x[0] || ty <= y[0]) continue;
        x[++cnt] = tx; y[cnt] = ty; id[cnt] = i;
    }
    n = cnt;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (x[i] < x[j] && y[i] < y[j]) vis[i][j] = 1, d[j]++;
        }
    }
    q.push(0); d[0] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v = 0; v <= n; v++) {
            if (!vis[u][v]) continue;
            if (dis[u] + 1 > dis[v]) dis[v] = dis[u] + 1, pre[v] = u;
            d[v]--; if (!d[v]) q.push(v);
        }
    }
    int ans = 0, x = 0;
    for (int i = 1; i <= n; i++) if (dis[i] > ans) ans = dis[i], x = i;
    printf("%d\n", ans); if (x) dfs(x);
    return 0;
}
```