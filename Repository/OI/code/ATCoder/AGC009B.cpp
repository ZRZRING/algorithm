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

const int N = 1e6 + 10, M = 2e6 + 10, inf = 1e9;

inline int read() {
    bool sym = 0; int res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}

struct EDGE {
    int u, v, nxt;
} edge[N];

int n, m, head[N], cnt, f[N], t[N];

bool cmp(int a, int b) {return f[a] < f[b];}

void add(int u, int v) {edge[++cnt] = (EDGE){u, v, head[u]}; head[u] = cnt;}

void dfs(int u) {
    for (int e = head[u]; e; e = edge[e].nxt) dfs(edge[e].v);
    cnt = 0;
    for (int e = head[u]; e; e = edge[e].nxt) t[++cnt] = edge[e].v;
    sort(t + 1, t + cnt + 1, cmp);
    for (int i = 1; i <= cnt; i++) {int v = t[i]; f[u] = max(f[u], f[v]) + 1;}
}

int main() {
    n = read();
    for (int v = 2; v <= n; v++) {int u = read(); add(u, v);}
    dfs(1); printf("%d", f[1]);
    return 0;
}