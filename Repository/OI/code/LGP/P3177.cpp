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
const int N = 4e3 + 10;
inline int read() {
    int sym = 0, res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
struct EDGE {
    int u, v, nxt, dis;
} edge[N];
int n, m, cnt, head[N], k, w, siz[N];
long long dp[N][N];
void add(int u, int v, int t) {
    edge[++cnt] = (EDGE){u, v, head[u], t}; head[u] = cnt;
}
void dfs(int u, int last) {
    siz[u] = 1; dp[u][0] = dp[u][1] = 0;
    for (int e = head[u]; e; e = edge[e].nxt) {
        int v = edge[e].v; if (v == last) continue; dfs(v, u); siz[u] += siz[v];
    }
    for (int e = head[u]; e; e = edge[e].nxt) {
        int v = edge[e].v, w = edge[e].dis; if (v == last) continue;
        for (int i = min(k, siz[u]); i >= 0; i--) {
            for (int j = 0; j <= min(i, siz[v]); j++) {
                if (~dp[u][i - j]) {
                    long long val = 1ll * j * (k - j) * w + 1ll * (siz[v] - j) * (n - k + j - siz[v]) * w;
                    dp[u][i] = max(dp[u][i], dp[u][i - j] + dp[v][j] + val);
                }
            }
        }
    }
}
int main() {
    n = read(); k = read(); memset(dp, -1, sizeof(dp));
    for (int i = 1; i < n; i++) {
        int u = read(), v = read(), t = read(); add(u, v, t); add(v, u, t);
    }
    dfs(1, 0); printf("%lld", dp[1][k]);
    return 0;
}