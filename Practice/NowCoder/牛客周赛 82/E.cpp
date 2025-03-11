#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS \
    std::ios::sync_with_stdio(false), \
    std::cin.tie(0), \
    std::cout.tie(0)

const int64 mod = 998244353;

int N, T = 1;

void init() {
    // Fast_IOS;
    // std::cin >> T;
}

void solve() {
    int n;
    std::cin >> n;
    int64 maxNum, p, ans = 0;
    std::cin >> maxNum >> p;
    std::vector<int64> a(n);
    for (auto &x : a) {
        std::cin >> x;
    }
    a.push_back(1e9);
    int l = -1, r1 = 0, r2 = 0, mul1 = 1, mul2 = 1;
    while (l + 1 < n) {
        if (l >= 0) {
            mul1 /= a[l];
            mul2 /= a[l];
        }
        l++;
        while (mul1 < p && r1 - l + 1 <= maxNum && r1 < n || r1 <= l) {
            mul1 *= a[r1];
            r1++;
        }
        while (mul2 <= p && r2 - l <= maxNum && r2 <= n || r2 < r1) {
            mul2 *= a[r2];
            r2++;
        }
        if (mul1 == p) {
            ans += r2 - r1;
        }
        // std::cout << l << ' ' << r1 << ' ' << r2 << '\n';
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