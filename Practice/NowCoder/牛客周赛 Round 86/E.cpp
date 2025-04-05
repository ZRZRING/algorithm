#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS \
    std::ios::sync_with_stdio(false), \
    std::cin.tie(0), \
    std::cout.tie(0)

const int64 mod = 998244353;

const int N = 1e5 + 10;

int T = 1;

void init() {
    // Fast_IOS;
    std::cin >> T;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &x : a) {
        std::cin >> x;
    }
    std::sort(a.begin(), a.end());
    std::set<int> s;
    s.insert(0);
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        int t = 1e9;
        auto it = s.upper_bound(a[i]);
        if (it != s.end()) {
            t = *it;
        }
        ans = std::min(ans, t + a[i]);
        std::vector<int> r;
        for (auto x : s) {
            r.push_back(x + a[i]);
        }
        for (auto x : r) {
            s.insert(x);
        }
    }
    if (ans == 1e9) {
        ans = -1;
    }
    std::cout << ans << '\n';
}

int main() {
    init();
    while (T--) {
        solve();
    }
    return 0;
}