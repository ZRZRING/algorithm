#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
const int M = 998244353, P = 16;
const ll inf = 1e17;
const double eps = 1e-10;
ll poww(ll bs, ll x) {
    ll res = 1;
    for (bs = (bs % M + M) % M; x; x >>= 1, (bs *= bs) %= M)
        if (x & 1)
            (res *= bs) %= M;
    return res;
}
ll invv(ll bs) {
    return poww(bs, M - 2);
}
ll cost[1 << P][P], c2[1 << P][P];
int dis[P][P], ppc[1 << P], opc1, opc2, opc3, opc4;
struct S {
    int n, m;
    void ini() {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dis[i][j] = M;
        for (int i = 1, u, v, w; i <= m; i++)
            cin >> u >> v >> w, u--, v--, dis[u][v] = dis[v][u] = min(dis[u][v], w);
        for (int i = 0; i < (1 << n); i++)
            for (int j = 0; j < n; j++)
                cost[i][j] = c2[i][j] = M;
        for (int i = 1; i < (1 << n); i++) {
            if (i == (i & -i)) {
                for (int j = 0; j < n; j++)
                    if (i & (1 << j))
                        cost[i][j] = 0;
            } else
                for (int j = 0; j < n; j++)
                    if (i & (1 << j))
                        for (int d = i & -i, k = i - d; k; k = (k - d) & i) {
                            opc1++;
                            if (k & (1 << j))
                                cost[i][j] = min(cost[i][j], cost[k][j] + c2[i ^ k][j]), opc2++;
                        }
            for (int j = 0; j < n; j++)
                if (!(i & (1 << j)))
                    for (int k = 0; k < n; k++) {
                        opc3++;
                        if (i & (1 << k))
                            c2[i][j] = min(c2[i][j], cost[i][k] + ll(dis[k][j]) * (n - ppc[i]) * ppc[i]), opc4++;
                    }
        }
    }
    void solve() {
        ll x = cost[(1 << n) - 1][0];
        if (x == M)
            x = -1;
        cout << x << '\n';
    }
};
void precal() {
    for (int i = 0; i < (1 << P); i++)
        for (int j = P - 1; j >= 0; j--)
            if (i & (1 << j))
                ppc[i]++;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    precal();
    int t = 1;
    while (t--) {
        S SS;
        SS.ini();
        SS.solve();
    }
}