> 给定一棵以1号节点为根的树，点有权值，然后将其该树分成若干条垂直路径，使得每一个点仅被一条垂直路径覆盖，同时，每条垂直路径长度不能超过L，点权和不能超过S，求最少需要几条垂直路径才能满足要求，无解输出-1

> 垂直路径是一条包含点集$u_i$的路径，使得$u_i(i\geq2)$是$u_{i-1}$的父亲

调了好久的题，还是自己码力太差了

首先可以想到从叶子贪心，能不切就不切，这样保证是最优的。然后考虑计算答案，因为限制有两个，不能直接树形dp，于是预处理出每个点能往上爬多少个点，这样一来就可以做到树形dp了

预处理的过程可以用倍增优化

```cpp
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
void file() {
    freopen("std.in", "r", stdin);
    freopen("wa.out", "w", stdout);
}
const int N = 2e5 + 10, inf = 1e9;
inline int read() {
    int sym = 0, res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
inline long long lread() {
    long long sym = 0, res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
struct EDGE {
    int u, v, nxt;
} edge[N];
int n, L, head[N], cnt, fa[N][30], son[N], depth[N], jp[N], f[N];
long long S, val[N], sum[N][30];
void add(int u, int v) {edge[++cnt] = (EDGE){u, v, head[u]}; head[u] = cnt;}
void dfs(int u, int last) {
    fa[u][0] = last; depth[u] = depth[last] + 1; sum[u][0] = val[last];
    for (int i = 1; (1 << i) <= depth[u]; i++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
        sum[u][i] = sum[u][i - 1] + sum[fa[u][i - 1]][i - 1];
    }
    for (int e = head[u]; e; e = edge[e].nxt) {
        int v = edge[e].v; son[u]++; dfs(v, u);
    }
}
void dfs(int u) {
    int mx = 0;
    for (int e = head[u]; e; e = edge[e].nxt) {
        int v = edge[e].v; dfs(v); mx = max(mx, jp[v]); f[u] += f[v];
    }
    if (!mx) f[u]++; else jp[u] = mx - 1;
}
int main() {
    n = read(); L = read(); S = lread();
    for (int i = 1; i <= n; i++) {
        val[i] = lread(); if (val[i] > S) {printf("-1"); return 0;}
    }
    for (int v = 2; v <= n; v++) {
        int u = read(); add(u, v);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        int u = i, s = val[u], l = 1;
        for (int j = 20; j >= 0; j--) {
            if (l + (1 << j) <= L && s + sum[u][j] <= S && fa[u][j]) {
                s += sum[u][j]; l += 1 << j; u = fa[u][j];
            }
        }
        jp[i] = l - 1;
    }
    dfs(1); printf("%d", f[1]);
    return 0;
}
```

