#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS \
    std::ios::sync_with_stdio(false), \
    std::cin.tie(0), \
    std::cout.tie(0)

const int64 mod = 998244353;

const int N = 11 * 111;

int T = 1, f[N];

void init() {
    Fast_IOS;
    std::cin >> T;
    f[0] = 1;
    for (int i = 1; i < N; i++) {
        if (i >= 11) f[i] |= f[i - 11];
        if (i >= 111) f[i] |= f[i - 111];
    }
}

void solve() {
    int n;
    std::cin >> n;
    if (n >= 11 * 111) {
        std::cout << "YES" << '\n';
        return;
    }
    std::cout << (f[n] ? "YES" : "NO") << '\n';
}

int main() {
    init();
    while (T--) {
        solve();
    }
    return 0;
}