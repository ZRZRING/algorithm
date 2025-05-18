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

template <class T>
T MOD(T& x, int64 p = mod) {
    return x = (x % p + p) % p;
}
template <class T>
T MOD(T&& x, int64 p = mod) {
    return x = (x % p + p) % p;
}
template <class T>
T QMOD(T& x, int64 p = mod) {
    while (x < 0) x += p;
    while (x >= p) x -= p;
    return x;
}
template <class T>
T QMOD(T&& x, int64 p = mod) {
    while (x < 0) x += p;
    while (x >= p) x -= p;
    return x;
}

int64 qpow(int64 a, int64 x = mod - 2) {
    a %= mod;
    x %= mod - 1;
    int64 res = 1;
    while (x) {
        if (x & 1) res = res * a % mod;
        a = a * a % mod;
        x >>= 1;
    }
    return res;
}

void solve() {
    int n, m;
    std::priority_queue<A2, std::vector<A2>, std::greater<A2>> q;
    for (int i = 1; i <= n; i++) {
        int x, y;
        q.push({y, x});
    }
    int ans = 0;
    while (!q.empty()) {
        auto [x, y] = q.top();
        q.pop();
        while (q.top()[0] == x) {
            y += q.top()[1];
            q.pop();
        }
        if (y > m) {
            q.push({x + 1, (y - m + 1) / 2});
        }
        if (y) {
            MOD(ans += qpow(2, x));
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