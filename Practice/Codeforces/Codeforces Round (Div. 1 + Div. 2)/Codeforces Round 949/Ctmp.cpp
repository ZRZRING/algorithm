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
const ll inf = 1e18;
const ll P = 131;
const ll dir[8][2] = {1, 0, 0, 1, -1, 0, 0, -1, 1, 1, 1, -1, -1, 1, -1, -1};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<PII> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (~a[i])
            b.push_back({i, a[i]});
    }
    if (b.empty())
    {
        for (int i = 1; i <= n; i++)
        {
            if (i & 1)
                cout << 1 << " ";
            else
                cout << 2 << " ";
        }
        cout << "\n";
        return;
    }
    int p = b[0].second;
    for (int i = b[0].first - 1; i >= 1; i--)
    {
        if (p == 1)
            p *= 4;
        p /= 2;
        a[i] = p;
    }
    p = b.back().second;
    for (int i = b.back().first + 1; i <= n; i++)
    {
        if (p == 1)
            p *= 4;
        p /= 2;
        a[i] = p;
    }

    for (int i = 0; i < b.size() - 1; i++)
    {
        auto [u, v] = b[i];
        auto [pu, pv] = b[i + 1];
		u++;
		pu--;
        while (u <= pu)
        {
            int d = abs(pv - v);
            if (d == 0)
                break;
            if (d == 1)
            {
                if (v > pv)
                {
                    a[u++] = v / 2;
                    v /= 2;
                }
                else
                {
                    a[pu--] = pv / 2;
                    pv /= 2;
                }
            }
            else
            {
                if (pv > v)
                {
                    pv /= 2;
                    a[pu--] = pv;
                }
                else
                {
                    v /= 2;
                    a[u++] = v;
                }
            }
        }
        bool flag = 0;
        for (int i = u + 1; i < pu; i++)
        {
            if (!flag)
                a[i] = a[i - 1] * 2;
            else
                a[i] = a[i - 1] / 2;
            flag = !flag;
        }
    }

    for (int i = 1; i < n; i++)
        if (a[i] != a[i + 1] / 2 && a[i] / 2 != a[i + 1])
            return void(cout << "-1\n");

    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << "\n";
}

int main()
{
    IOS int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}