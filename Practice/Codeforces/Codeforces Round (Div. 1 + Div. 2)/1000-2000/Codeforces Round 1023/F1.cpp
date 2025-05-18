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
    Fast_IOS;
    std::cin >> T;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    std::vector<int64> f(n + 1, 1e15);
    f[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        int min = 1e9 + 10, p;
        f[i] = f[i + 1] + a[i + 1];
        for (int j = i + 1; j <= n; j++) {
            if (a[j] < min) {
                min = a[j];
                p = j;
            }
            f[i] = std::min(f[i], f[j] + 1ll * min * (j - i) + (j - i) + (j - p - 1));
        }
    }
    std::cout << f[0] << '\n';
}

int main() {
    init();
    while (T--) {
        solve();
    }
    return 0;
}