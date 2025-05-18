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

std::vector<int64> mul(100), inv(100);

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

int64 C(int n, int m) {
    if (m < 0 || n < 0) return 0;
    if (m > n) return 0;
    return mul[n] * inv[m] % mod * inv[n - m] % mod;
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

void init() {
    Fast_IOS;
    std::cin >> T;
    mul[0] = 1;
    for (int i = 1; i <= 60; i++) {
        mul[i] = mul[i - 1] * i % mod;
    }
    inv[60] = qpow(mul[60]);
    for (int i = 59; i >= 0; i--) {
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
}

void solve() {
    int64 n;
    int k;
    std::cin >> n >> k;
    int64 ans = 0, t = 0;
    for (int i = 60; i >= 0; i--) {
        if ((n >> i & 1) == 0) {
            continue;
        }
        k--;
        if (k < 0 || i < k) {
            break;
        }
        MOD(ans += 1ll * C(i, k) % mod * t % mod);
        MOD(ans += 1ll * C(i - 1, k - 1) % mod * ((1ll << i + 1) - 1ll) % mod);
        t |= 1ll << i;
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