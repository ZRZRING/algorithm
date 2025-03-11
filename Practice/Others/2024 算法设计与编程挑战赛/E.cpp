#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int hs[N], xs[N], ht[N], xt[N];
void solve() {
    string s, t;
    cin >> s >> t;
    int sl = s.size(), tl = t.size();
    s = '?' + s;
    t = '?' + t;
    for (int i = 1; i <= sl; i++) {
        hs[i] = hs[i - 1], xs[i] = xs[i - 1];
        if (s[i] == 'H') {
            hs[i]++;
        } else {
            xs[i]++;
        }
    }
    for (int i = 1; i <= tl; i++) {
        ht[i] = ht[i - 1], xt[i] = xt[i - 1];
        if (t[i] == 'H') {
            ht[i]++;
        }
        if (t[i] == 'X') {
            xt[i]++;
        }
    }
    int a, b, c, d;
    int q;
    cin >> q;
    while (q--) {
        cin >> a >> b >> c >> d;
        int sh = hs[b] - hs[a - 1];
        int sx = xs[b] - xs[a - 1];
        int th = ht[d] - ht[c - 1];
        int tx = xt[d] - xt[c - 1];
        int p1 = abs(sx - sh) % 3;
        int p2 = abs(th - tx) % 3;
        // cout << "??" << sh << ' ' << sx << "   " << th << ' ' << tx << '\n';
        // cout << "**" << p1 << ' ' << p2 << '\n';
        if ((p1 == 0) ^ (p2 == 0)) {
			std::cout << "NO" << endl;
			continue;
		}
		if (p1 == 0 && p2 == 0) {
			std::cout << "YES" << endl;
			continue;
		}
		char c1 = ((sx > sh) ^ (p1 == 2) ? 'X' : 'H'), c2 = ((tx > th) ^ (p2 == 2) ? 'X' : 'H');
		std::cout << (c1 == c2 ? "YES" : "NO") << endl;
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}