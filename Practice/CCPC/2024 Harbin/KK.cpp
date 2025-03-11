#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define all1(x) x.begin() + 1, x.end()
#define bit1(x) __builtin_popcountll(x)
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
const ll inf = 1e18;
const ll P = 131;
const ll dir[8][2] = {1, 0, 0, 1, -1, 0, 0, -1, 1, 1, 1, -1, -1, 1, -1, -1};

struct node
{
    ll l, r, w;
};

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<node> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i].w >> a[i].l >> a[i].r;

    sort(all1(a), [&](node a, node b)
         { return a.w > b.w; });

    ll sum = 0, tot = 0;
    vector<ll> f(n + 1), g(n + 1);
    for (int i = 1; i <= n; i++)
    {
        auto [l, r, w] = a[i];
        sum += l;
        tot += l * w;
        f[i] = (r - l) * w + f[i - 1];
        g[i] = r - l + g[i - 1];
    }

    ll ans = tot + a[1].w * (m - sum);
    // cout<<ans<<"\n";
    for (int i = 2; i <= n; i++)
    {
        auto [l, r, w] = a[i];
        ll p = tot - l * w, t = m - (sum - l);
        ll pos = max(1ll * i, (ll)(upper_bound(g.begin() + 1, g.begin() + i + 1, t) - g.begin() - 1));
        // cout << f[pos] + w * (m - sum + l - g[pos]) << " ";
        ans = max(ans, p + f[pos] + w * (m - sum + l - g[pos]));
    }
    cout << ans << "\n";
}

int main()
{
    IOS int T = 1;
    // cin>>T;
    while (T--)
        solve();
    return 0;
}