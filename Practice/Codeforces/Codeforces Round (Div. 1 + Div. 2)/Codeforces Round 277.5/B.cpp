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
    int n, m;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    std::sort(a.begin() + 1, a.end());
    std::cin >> m;
    std::vector<int> b(m + 1);
    for (int i = 1; i <= m; i++) {
        std::cin >> b[i];
    }
    std::sort(b.begin() + 1, b.end());
    std::vector f(n + 1, std::vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = std::max(f[i - 1][j], f[i][j - 1]);
            if (abs(a[i] - b[j]) <= 1) {
                f[i][j] = std::max(f[i][j], f[i - 1][j - 1] + 1);
            }
        }
    }
    std::cout << f[n][m] << '\n';
}

int main() {
    init();
    while (T--) {
        solve();
    }
    return 0;
}