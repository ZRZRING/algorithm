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
    std::vector<int> a(n), b(m);
    for (auto &x : a) {
        std::cin >> x;
    }
    for (auto &x : b) {
        std::cin >> x;
    }
    std::vector<int> L, R;
    int p = 0;
    for (auto x : b) {
        while (p < n && a[p] != x) {
            p++;
        }
        if (p >= n) {
            std::cout << "No\n";
            return;
        }
        L.push_back(p);
        p++;
    }
    p = n - 1;
    std::reverse(b.begin(), b.end());
    for (auto x : b) {
        while (p > -1 && a[p] != x) {
            p--;
        }
        if (p <= -1) {
            std::cout << "No\n";
            return;
        }
        R.push_back(p);
        p--;
    }
    std::reverse(R.begin(), R.end());
    for (int i = 0; i < m; i++) {
        if (L[i] != R[i]) {
            std::cout << "Yes\n";
            return;
        }
    }
    std::cout << "No\n";
}

int main() {
    init();
    while (T--) {
        solve();
    }
    return 0;
}