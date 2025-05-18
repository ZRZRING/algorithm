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
    std::vector a(30, std::vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        std::cin >> a[0][i];
    }
    for (int i = 1; i < 30; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = a[i - 1][a[i - 1][j]];
        }
    }
    int Q;
    std::cin >> Q;
    while (Q--) {
        int x, t;
        std::cin >> x >> t;
        for (int i = 1 << 29, j = 29; i; i >>= 1, j--) {
            if (t >= i) {
                x = a[j][x];
                t -= i;
            }
        }
        std::cout << x << '\n';
    }
}

int main() {
    init();
    while (T--) {
        solve();
    }
    return 0;
}