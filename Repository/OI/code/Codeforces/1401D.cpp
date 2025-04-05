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
const int N = 1e6 + 10, inf = 1e9, dsq = 1e9 + 7;
inline int read() {
    bool sym = 0; int res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
struct EDGE {
    int u, v, nxt;
} edge[N];
int n, m, head[N], cnt, fa[N], siz[N];
long long pr[N], t[N];
void add(int u, int v) {
    edge[++cnt] = (EDGE){u, v, head[u]}; head[u] = cnt;
}
void dfs(int u, int last) {
    fa[u] = last; siz[u] = 1;
    for (int e = head[u]; e; e = edge[e].nxt) {
        int v = edge[e].v; if (v == last) continue; dfs(v, u); siz[u] += siz[v];
    }
}
int main() {
    int T = read();
    while (T--) {
        n = read(); long long ans = 0; int p = n - 1; memset(head, 0, sizeof(head)); cnt = 0;
        for (int i = 1; i < n; i++) {
            int u = read(), v = read(); add(u, v); add(v, u);
        }
        dfs(1, 0); for (int v = 2; v <= n; v++) t[v - 1] = 1ll * siz[v] * (n - siz[v]);
        m = read(); for (int i = 1; i <= m; i++) pr[i] = read();
        while (m < n - 1) pr[++m] = 1;
        sort(pr + 1, pr + m + 1); sort(t + 1, t + n);
        while (m > n - 1) pr[m - 1] = pr[m - 1] * pr[m] % dsq, m--;
        for (int i = m; i >= 1; i--) ans = (ans + 1ll * pr[i] * t[p--] % dsq) % dsq;
        cout << ans << endl;
    }
    return 0;
}