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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    ll tot = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i], tot += a[i];
    vector<ll> x(m + 1), t(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> x[i] >> t[i];
    for (int i = m; i > 1; i--)
        x[i] = x[i] - x[i - 1];

    ll sum = 0, pos = 0;

    for (int i = 1; i <= m; i++) {
        if (sum + x[i] <= tot) {
            sum = max(0ll, sum + x[i] - a[t[i]]);
        } else {
            cout << pos + tot - sum << "\n";
            return;
        }
        // cout << sum << " ";
        pos += x[i];
    }
    cout << pos + tot - sum << "\n";
}

/*
2
3 1
3 3 3
8 1
2 2
5 2
1 2
2 1
*/

int main() {
    IOS int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
