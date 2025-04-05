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
    Fast_IOS;
    std::cin >> T;
}

int f(char c) {
    return c == '1' ? 1 : -1;
}

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int L = 0, R = 0;
    for (int i = 0; i < n; i++) {
        R += f(s[i]);
    }
    int64 ans = -1e15;
    for (int i = 0; i < n - 1; i++) {
        L += f(s[i]);
        R -= f(s[i]);
        ans = std::max(ans, 1ll * L * R);
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