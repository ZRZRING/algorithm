#include <bits/stdc++.h>

#define Fast_IOS                      \
    std::ios::sync_with_stdio(false), \
        std::cin.tie(0),              \
        std::cout.tie(0)

using uint = unsigned int;
using int64 = long long;
using uint64 = unsigned long long;
using A2 = std::array<int64, 2>;

int64 mod = 1e9 + 7;

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

struct ICPC {
    int N = 1e6 + 10, T = 1;

    std::vector<int64> mul, inv;

    int64 qpow(int64 a, int64 x = mod - 2) {
        a %= mod;
        x %= mod - 1;
        int64 res = 1;
        while (x) {
            if (x & 1) {
                res = res * a % mod;
            }
            a = a * a % mod;
            x >>= 1;
        }
        return res;
    }

    void init() {
        Fast_IOS;
        std::cin >> T;
        mul.resize(N + 1);
        inv.resize(N + 1);
        mul[0] = 1;
        for (int i = 1; i <= N; i++) {
            mul[i] = mul[i - 1] * i % mod;
        }
        inv[N] = qpow(mul[N]);
        for (int i = N - 1; i >= 0; i--) {
            inv[i] = inv[i + 1] * (i + 1) % mod;
        }
    }

    int64 C(int n, int m) {
        return mul[n] * inv[m] % mod * inv[n - m] % mod;
    }

    void solve() {
        int n, m, k;
        std::cin >> n >> m >> k;
        if (m == 1) {
            if (n - k - k + 1 < 0) {
                std::cout << 0 << '\n';
                return;
            }
            std::cout << C(n - k + 1, k) << '\n';
            return;
        }
        int64 ans = 0;
        for (int i = 1; i <= std::min(k, n - k + 1); i++) {
            int64 now = C(k - 1, i - 1) * C(n - k + 1, i) % mod * qpow(m, i) % mod * qpow(m - 1, k - i) % mod;
            ans = (ans + now) % mod;
        }
        std::cout << ans << '\n';
    }
};

int main() {
    ICPC icpc;
    icpc.init();
    while (icpc.T--) {
        icpc.solve();
    }
    return 0;
}