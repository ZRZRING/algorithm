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
    // std::cin >> T;
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> ans;
    for (int i = 1; i <= n; i += m * 2 + 1) {
        ans.push_back(i);
    }
    int delta = std::max(0, n - ans.back() - m);
    std::cout << ans.size() << '\n';
    for (auto x : ans) {
        std::cout << x + delta << ' ';
    }
    std::cout << '\n';
}

int main() {
    init();
    while (T--) {
        solve();
    }
    return 0;
}