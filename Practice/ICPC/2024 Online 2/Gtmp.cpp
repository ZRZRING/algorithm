#include <bits/stdc++.h>

using int64 = long long;

const int64 mod = 998244353;

#define A3 std::array<int64, 3>

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

void solve() {
    int64 X, Y, A, B, C;
    std::cin >> X >> Y >> A >> B >> C;
    int64 p0 = A * qpow(A + B) % mod;
    int64 p1 = B * qpow(A + B) % mod;
#define A4 std::array<int64, 4>
    std::vector<A4> f;
    int cnt = 1;
    if (X >= Y) {
        f.push_back({0, X, Y, 1});
        cnt = 1;
    } else {
        f.push_back({1, Y, X, 1});
        cnt = 0;
    }
    while (std::max(X, Y) % std::min(X, Y) != 0) {
        if (cnt == 1) {
            f.push_back({1, Y, X % Y, f.back().at(3) * qpow(p0, X / Y) % mod});
            X %= Y;
        } else {
            f.push_back({0, X, Y % X, f.back().at(3) * qpow(p1, Y / X) % mod});
            Y %= X;
        }
        cnt ^= 1;
    }
    if (cnt == 1) {
        f.push_back({1, Y, Y, f.back().at(3) * qpow(p0, X / Y - 1) % mod});
    } else {
        f.push_back({0, X, X, f.back().at(3) * qpow(p1, Y / X - 1) % mod});
    }
    int64 ans = 0;
    for (auto [p, x, y, t] : f) {
        std::cout << p << ' ' << x << ' ' << y << ' ' << t << '\n';
        if (p == 0) {
            int64 a0 = t * p0 % mod;
            ans += (a0 * qpow(p1, x / y ) % mod - a0 + mod) % mod * qpow(p1 - 1 + mod) % mod;
            ans %= mod;
        }
    }
    std::cout << ans << '\n';
}

int main() {
    // std::ios::sync_with_stdio(0);
    // std::cin.tie(0);
    // std::cout.tie(0);
    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}