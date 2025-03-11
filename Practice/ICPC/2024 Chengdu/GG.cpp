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
    int n;
    cin >> n;
    set<int> st;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        st.insert(a[i]);
    }
    for (int i = 1; i < n; i++) {
        set<int> s;

        s.insert(a[i] & a[i + 1]);
        s.insert(a[i] | a[i + 1]);
        s.insert(a[i] ^ a[i + 1]);

		std::vector<int> p;

        for (auto j : s) {
			p.push_back(j & a[i]);
			p.push_back(j | a[i]);
			p.push_back(j ^ a[i]);
			p.push_back(j & a[i + 1]);
			p.push_back(j | a[i + 1]);
			p.push_back(j ^ a[i + 1]);
        }

		for (auto x : p) {
			s.insert(x);
		}

		p.clear();

        for (auto j : s) {
			p.push_back(j & a[i]);
			p.push_back(j | a[i]);
			p.push_back(j ^ a[i]);
			p.push_back(j & a[i + 1]);
			p.push_back(j | a[i + 1]);
			p.push_back(j ^ a[i + 1]);
        }

		for (auto x : p) {
			s.insert(x);
		}

		for (auto x : s) {
			st.insert(x);
		}
    }
    cout << st.size();
}

int main() {
    IOS int T = 1;
    // cin>>T;
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