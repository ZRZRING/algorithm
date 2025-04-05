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
int n, L, head[N], cnt, fa[N][30], son[N], dep[N], jp[N], f[N];
long long S, val[N], sum[N][30];
void add(int u, int v) {edge[++cnt] = (EDGE){u, v, head[u]}; head[u] = cnt;}
void dfs(int u, int last) {
    fa[u][0] = last; dep[u] = dep[last] + 1; sum[u][0] = val[last];
    for (int i = 1; (1 << i) <= dep[u]; i++) {
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