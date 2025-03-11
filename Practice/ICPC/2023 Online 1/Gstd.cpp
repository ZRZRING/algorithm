#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
typedef pair<int, int> pii;
constexpr int mod = 998244353;
constexpr int N = 1e6 + 10;
#define int long long
vector<int> g[N];
int n;
int p[N];
int sz[N];
int qmi(int m, int k) {
    int res = 1 % mod, t = m;
    while (k) {
        if (k & 1)
            res = (ll)res * t % mod;
        t = (ll)t * t % mod;
        k >>= 1;
    }
    return res;
}

pii c[N];
int d[N];
int f[N];
int find(int x) {
    if (x != p[x])
        p[x] = find(p[x]);
    return p[x];
}

void dfs(int u, int fa) {
    d[u] = d[fa] + 1;
    for (auto v : g[u]) {
        if (v != fa) {
            f[v] = u;
            dfs(v, u);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> c[i].x >> c[i].y;
    }
    for (int i = 1; i <= n; i++)
        p[i] = i, sz[i] = 1;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0);
    ll ans = 1;
    for (int i = 1; i < n; i++) {
        int a = c[i].x, b = c[i].y;
        int pa = find(a), pb = find(b);
        if (d[pa] == d[pb]) {
            cout << 0 << endl;
            return 0;
        }
        if (d[pa] < d[pb]) {
            if (find(f[pb]) == pa) {
                (ans *= (ll)sz[pa] * sz[pb] % mod) %= mod;
                p[pb] = p[pa];
                sz[pa] += sz[pb];
            } else {
                cout << 0 << endl;
                return 0;
            }
        } else {
            if (find(f[pa]) == pb) {
                (ans *= (ll)sz[pa] * sz[pb] % mod) %= mod;
                p[pa] = p[pb];
                sz[pb] += sz[pa];
            } else {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    cout << qmi(ans, mod - 2) << endl;
}