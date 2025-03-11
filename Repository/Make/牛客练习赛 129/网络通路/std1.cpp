#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
const int M = 998244353, P = 16;
const ll inf = 1e17;
const double eps = 1e-10;
ll f[1 << P][P], g[1 << P][P];
int dis[P][P], cnt[1 << P];
struct S {
    int n, m;
    void ini() {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dis[i][j] = M;
            }
        }
        for (int i = 1, u, v, w; i <= m; i++) {
            cin >> u >> v >> w;
            u--, v--;
            dis[u][v] = dis[v][u] = min(dis[u][v], w);
        }
        for (int i = 0; i < (1 << n); i++) {
            for (int j = 0; j < n; j++) {
                f[i][j] = g[i][j] = M;
            }
        }
        for (int i = 1; i < (1 << n); i++) {
            if (i == (i & -i)) {
                for (int j = 0; j < n; j++) {
                    if (i & (1 << j)) {
						f[i][j] = 0;
					}
                }
            } else {
                for (int j = 0; j < n; j++) {
                    if ((i & 1 << j) == 0) continue;
                    for (int d = i & -i, k = i - d; k; k = (k - d) & i) {
                        if (k & (1 << j)) {
                            f[i][j] = min(f[i][j], f[k][j] + g[i ^ k][j]);
                        }
                    }
                }
            }
            for (int j = 0; j < n; j++) {
                if ((i & 1 << j) == 1) continue;
                for (int k = 0; k < n; k++) {
                    if ((i & 1 << k) == 0) continue;
                    g[i][j] = min(g[i][j], f[i][k] + ll(dis[k][j]) * (n - cnt[i]) * cnt[i]);
                }
            }
        }
    }
    void solve() {
        ll x = f[(1 << n) - 1][0];
        if (x == M) {
			x = -1;
		}
        cout << x << '\n';
    }
};
void precal() {
    for (int i = 0; i < (1 << P); i++)
        for (int j = P - 1; j >= 0; j--)
            if (i & (1 << j))
                cnt[i]++;
}
int main() {
    // freopen("1.in","r",stdin);
    // cout<<fixed<<setprecision(12);
    ios::sync_with_stdio(0);
    cin.tie(0);
    precal();
    int t = 1;  // cin>>t;
    // clock_t a=clock();
    while (t--) {
        S SS;
        SS.ini();
        SS.solve();
    }
    // cout<<"Time:"<<double(clock()-a)<<'\n';
}