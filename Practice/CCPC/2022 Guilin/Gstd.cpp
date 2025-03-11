#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
#define int long long
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define pr pair<int, int>
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define dep(i, l, r) for (int i = r; i >= l; --i)
const int N = 2e5 + 5, inf = 1e12;
int n, u, v, ans, a[N], b[N], d[N], mxd[N], g[N][2];
pr md[N][2], f[N][4];
vector<int> G[N];
void add(int u, int v) {
    G[u].push_back(v);
	G[v].push_back(u);
}
void dfs1(int u, int fa) {
    rep(i, 0, 3) f[u][i] = mp(0, 0);
    rep(i, 0, 1) md[u][i] = mp(0, 0);
    for (auto v : G[u])
        if (v != fa) {
            dfs1(v, u);
            d[u] = max(d[u], d[v]);
            pr res = mp(mxd[v], v);
            pr cur = mp(d[v], v);
            rep(i, 0, 1)
                // md 表示子树内不含 u 的第 i 大链
				if (cur >= md[u][i]) {
					dep(j, i + 1, 1) md[u][j] = md[u][j - 1];
					md[u][i] = cur;
					break;
				}
            rep(i, 0, 3)
                // f 表示子树内以 u 为端点的第 i 大链
				if (res >= f[u][i]) {
					dep(j, i + 1, 3) f[u][j] = f[u][j - 1];
					f[u][i] = res;
					break;
				}
        }
    // mxd 表示 u 子树内以 u 点为端点的最长链
    mxd[u] = f[u][0].fi + a[u];
    // d 表示 u 子树内的最长链
    d[u] = max(d[u], mxd[u] + f[u][1].fi);
}
void dfs2(int u, int fa) {
    int res = 0;
    rep(i, 0, 3) b[i + 1] = f[u][i].fi;
    // g[0] 表示除去 u 子树，u 的父节点为端点的最长链
    b[5] = g[u][0];
    sort(b + 1, b + 5 + 1, [](int x, int y) { return x > y; });
    rep(i, 1, 4) res += b[i];
    ans = max(ans, res);
    // g[1] 表示除去 u 子树的最长链
    ans = max(ans, g[u][1] + d[u]);
    for (auto v : G[u])
        if (v != fa) {
            g[v][0] = g[u][0] + a[u];
            if (f[u][0].se == v)
                g[v][0] = max(g[v][0], f[u][1].fi + a[u]);
            else
                g[v][0] = max(g[v][0], f[u][0].fi + a[u]);
            g[v][1] = g[u][0];
            if (md[u][0].se == v)
                g[v][1] = max(g[v][1], md[u][1].fi);
            else
                g[v][1] = max(g[v][1], md[u][0].fi);
            int cnt = 0;
            rep(i, 0, 3)
				if (f[u][i].se != v)
                	b[++cnt] = f[u][i].fi;
            b[++cnt] = g[u][0];
            sort(b + 1, b + cnt + 1, [](int x, int y) { return x > y; });
            if (cnt >= 2)
                g[v][1] = max(g[v][1], b[1] + b[2] + a[u]);
            dfs2(v, u);
        }
}

signed main() {
    ios ::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    if (n == 1)
        return puts("0"), 0;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n - 1) cin >> u >> v, add(u, v);
    dfs1(1, 0);
    dfs2(1, 0);
    cout << ans << '\n';
    return 0;
}