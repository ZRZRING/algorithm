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

ll q_pow(ll a, ll b, ll m)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = ((res % m) * (a % m)) % m;
        b >>= 1;
        a = ((a % m) * (a % m)) % m;
    }
    return res;
}

class MOD_C
{
private:
    vector<ll> fac, infac;

    ll q_pow(ll a, ll b, ll m)
    {
        ll res = 1;
        while (b)
        {
            if (b & 1)
                res = ((res % m) * (a % m)) % m;
            b >>= 1;
            a = ((a % m) * (a % m)) % m;
        }
        return res;
    }
    ll inv(ll a, ll m)
    {
        return q_pow(a, m - 2, m);
    }

public:
    MOD_C() {}
    MOD_C(int n, ll m = mod)
    {
        fac.resize(n + 1);
        infac.resize(n + 1);
        fac[0] = infac[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            fac[i] = fac[i - 1] * i % m;
            infac[i] = infac[i - 1] * inv(i, m) % m;
        }
    }

    ll get_C(int a, int b, int m = mod)
    {
        return fac[a] % m * infac[b] % m * infac[a - b] % m;
    }
} mc(1e5 + 10);

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    string s;
    array<int, 4> cnt({0, 0, 0, 0});
    map<char, int> ta({{'L', 0}, {'R', 1}, {'D', 2}, {'U', 3}});
    cin >> s;
    for (auto ch : s)
        cnt[ta[ch]]++;
    if (-cnt[2] <= x && x <= cnt[3] && -cnt[0] <= y && y <= cnt[1])
    {
        cout << "YES ";
        array<int, 4> p({max(0, -y), max(0, y), max(0, -x), max(0, x)});
        for (auto ch : s)
        {
            if (p[ta[ch]])
            {
                p[ta[ch]]--;
                cout << ch;
            }
        }
        cout << " ";
        array<int, 4> tp({max(0, -y), max(0, y), max(0, -x), max(0, x)});
        int p1 = min(cnt[0] - tp[0], cnt[1] - tp[1]), p2 = min(cnt[2] - tp[2], cnt[3] - tp[3]);
        ll ans = 0;
        // cout << p1 << " " << p2 << "\n";
        // for (int i = 0; i < 4; i++)
        //     cout << cnt[i] - tp[i] << " \n"[i == 4];
        ll tcp = 0;
        for (int i = 0; i <= p1; i++)
            tcp = (tcp + mc.get_C(cnt[0] - tp[0], i) * mc.get_C(cnt[1] - tp[1], i) % mod) % mod;
        for (int i = 0; i <= p2; i++)
            ans = (ans + tcp * mc.get_C(cnt[2] - tp[2], i) * mc.get_C(cnt[3] - tp[3], i) % mod) % mod;
        for (int i = 0; i < 4; i++)
            ans = ans * mc.get_C(cnt[i], tp[i]) % mod;
        cout << ans << "\n";
    }
    else
        cout << "NO\n";
}

int main()
{
    IOS int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}