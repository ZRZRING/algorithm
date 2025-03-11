#include <bits/stdc++.h>
#define debug(a) cerr << #a << "=" << a << '\n';
#define pque priority_queue
#define ef emplace_front
#define eb emplace_back
#define pf push_front
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define all(x) x.begin(), x.end()
#define arr(x) x.begin() + 1, x.end()
#define lb0(x, y) lower_bound(x.begin(), x.end(), y) - x.begin();
#define lb1(x, y) lower_bound(x.begin() + 1, x.end(), y) - x.begin();
#define rev(x) reverse(all(x))
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define rep(i, a, b) for(int i = a; i <= b; i++) 
#define per(i, a, b) for(int i = a; i >= b; i--) 
#define repp(i, a, b) for(int i = a; i < b; i++) 
#define perr(i, a, b) for(int i = a - 1; i >= b; i--) 
using namespace std;
using ll = long long;
using tpi = tuple<int, int, int>;
using tpl = tuple<ll, ll, ll>;
using tpd = tuple<double, double, double>;
using pii = pair<int, int>;
using pdd = pair<double, double>;
using pll = pair<ll, ll>;
const int N = 2e5 + 10;
const int mod = 998244353;

void solve() {
    //全找相等的
    int n, k;
    cin >> n >> k;
    k *= 2;
    vector<pii> a(n + 1);
    rep (i, 1, n * 2) {
        int x;
        cin >> x;
        if (a[x].fi == 0) a[x].fi = i;
        else a[x].se = i;
    }
    vector<int> c1, c2;
    rep (i, 1, n) {
        int p = a[i].fi;
        int q = a[i].se;
        if (p <= n && q <= n) {
            if (c1.size() + 2 <= k) {
                c1.pb(i);
                c1.pb(i);
            }
        }
        else if (p <= n && q > n || p > n && q <= n) {
            if (c1.size() + 1 <= k && c2.size() + 1 <= k) {
                c1.pb(i);
                c2.pb(i);
            }
        }
        else {
            if (c2.size() + 2 <= k) {
                c2.pb(i);
                c2.pb(i);
            }
        }
        if (c1.size() == k && c2.size() == k) break;
    }
    for (auto x : c1) cout << x << ' ';
    cout << '\n';
    for (auto x : c2) cout << x << ' ';
    cout << '\n';
}  
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}