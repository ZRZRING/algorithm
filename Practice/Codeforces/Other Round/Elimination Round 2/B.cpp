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
    std::vector<std::vector<int>> a(n + 2, std::vector<int>(m + 2));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            std::cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int flag = 0;
        for (int j = 1; j <= m; j++) {
            if (a[i][j]) {
                flag = 1;
                continue;
            }
            ans += flag;
        }
        flag = 0;
        for (int j = m; j >= 1; j--) {
            if (a[i][j]) {
                flag = 1;
                continue;
            }
            ans += flag;
        }
    }
    for (int j = 1; j <= m; j++) {
        int flag = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i][j]) {
                flag = 1;
                continue;
            }
            ans += flag;
        }
        flag = 0;
        for (int i = n; i >= 1; i--) {
            if (a[i][j]) {
                flag = 1;
                continue;
            }
            ans += flag;
        }
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