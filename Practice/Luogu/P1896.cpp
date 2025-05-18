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
    int n, K;
    std::cin >> n >> K;
    std::vector<int> ok;
    auto dfs = [&](auto self, int x, int t) -> void {
        // 处理单行所有的合法二进制数
        if (x == n) {
            ok.push_back(t);
            return;
        }
        
        // 这个位置是 0
        self(self, x + 1, t);

        // 这个位置是 1
        self(self, x + 2, t | 1 << x);
    };
    dfs(dfs, 0, 0);
    std::vector f(n + 1, std::vector(1e3, std::vector<int>(K + 1)));
    f[0][0][0] = 1;
    auto count = [](int x) -> int {
        return __builtin_popcount(x);
    };
    auto check = [](int x, int y) -> bool {
        return (x & y) || (x >> 1 & y) || (x << 1 & y);
    };
    for (int i = 1; i <= n; i++) {
        for (auto last : ok) {
            for (auto now : ok) {
                for (int k = 0; k <= K; k++) {
                    if (k - count(now) >= 0 && check(last, now)) {
                        f[i][now][k] += f[i - 1][last][k - count(now)];
                    }
                }
            }
        }
    }
    int ans = 0;
    for (auto now : ok) {
        ans += f[n][now][K];
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