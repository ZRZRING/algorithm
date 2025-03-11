#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define all1(x) x.begin() + 1, x.end()
#define bit1(x) __builtin_popcount(x)
#define Pqueue priority_queue
#define lc p << 1
#define rc p << 1 | 1
#define IOS ios::sync_with_stdio(false), cin.tie(0);
#define fi first
#define se second
#define lowbit(x) (x & -x)

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll, ll> PII;

const ll mod = 1000000007;
const ll N = 1e6 + 10;
const ld eps = 1e-9;
const ll inf = 1e12;
const ll P = 131;
const ll dir[8][2] = {1, 0, 0, 1, -1, 0, 0, -1, 1, 1, 1, -1, -1, 1, -1, -1};

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int u, v;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<vector<ll>> f(n + 10, vector<ll>(31));
    auto Dfs = [&](auto self, int u, int fa) -> void
    {
        for (int i = 1; i <= 20; i++)
            f[u][i] = a[i] * i;
        for (auto v : g[u])
        {
            if (v == fa)
                continue;
            self(self, v, u);
            for (int i = 1; i <= 20; i++)
            {
                ll mi = inf;
                for (int j = 1; j <= 20; j++)
                {
                    if (i != j)
                        mi = min(mi, f[v][j]);
                }
                f[u][i] += mi;
            }
        }
    };
    Dfs(Dfs, 1, 0);
    ll ans = inf;
    for (int i = 1; i <= 20; i++)
        ans = min(ans, f[1][i]);
    cout << ans << "\n";
}

int main()
{
    IOS int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}

/*
oxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxox
x                                                                                      o
o       _/_/_/_/                                                              _/       x
x      _/                                                                              o
o     _/_/_/_/ _/  _/_/   _/_/   _/_/_/ _/_/   _/_/_/     _/_/    _/_/_/    _/ _/   _/ x
x    _/       _/_/     _/    _/ _/   _/   _/  _/    _/ _/    _/  _/    _/  _/   _/ _/  o
o   _/       _/       _/    _/ _/   _/   _/  _/    _/ _/    _/  _/    _/  _/    _/_/   x
x  _/       _/         _/_/   _/   _/   _/  _/_/_/     _/_/ _/ _/    _/  _/      _/    o
o                                          _/                           _/      _/     x
x                                         _/                        _/_/       _/      o
o                                                                                      x
xoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxo
*/