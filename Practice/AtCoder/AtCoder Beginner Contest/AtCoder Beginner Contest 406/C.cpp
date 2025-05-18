#include <bits/stdc++.h>

#define Fast_IOS                      \
    std::ios::sync_with_stdio(false), \
        std::cin.tie(0),              \
        std::cout.tie(0)

using uint = unsigned int;
using int64 = long long;
using uint64 = unsigned long long;
using A2 = std::array<int64, 2>;

int64 mod = 998244353;

int N = 1e5 + 10, T = 1;

void init() {
    // Fast_IOS;
    // std::cin >> T;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 2);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    a[0] = n + 1;
    a[n + 1] = 0;
    std::vector<int> p;
    for (int i = 1; i <= n; i++) {
        if (a[i - 1] < a[i] && a[i] > a[i + 1]) {
            p.push_back(i);
        }
        if (a[i - 1] > a[i] && a[i] < a[i + 1]) {
            p.push_back(i);
        }
    }
    int64 ans = 0;
    for (int i = 0; i + 3 < p.size(); i += 2) {
        ans += 1ll * (p[i + 1] - p[i]) * (p[i + 3] - p[i + 2]);
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