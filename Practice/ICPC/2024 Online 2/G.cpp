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
	#define A3 std::array<int64, 3>
    std::vector<A3> f;
    f.push_back({X, Y, 1});
    while (X && Y) {
        if (X >= Y) {
            if (X % Y == 0) {

			} else {
            	f.push_back({X % Y, Y, f.back().at(2) * qpow(p1, X / Y) % mod});
			}
            X %= Y;

        } else {
            if (Y % X == 0) {

			} else {
            	f.push_back({X, Y % X, f.back().at(2) * qpow(p0, Y / X) % mod});
			}
            Y %= X;
        }
    }
    int64 ans = 0;
    // for (auto [x, y, t] : f) {
    //     std::cout << x << ' ' << y << ' ' << t << '\n';
    // }
    for (auto [x, y, t] : f) {
        if (x >= y) {
            int64 a0 = t * p0 % mod;
			// for (int i = 0; i < x / y; i++) {
			// 	ans += a0;
			// 	ans %= mod;
			// 	a0 = a0 * p1 % mod;
			// }
            ans += (a0 * qpow(p1, x / y) % mod - a0 + mod) % mod * qpow(p1 - 1 + mod) % mod;
            ans %= mod;
        }
        if (x < y && y % x == 0) {
            ans += t * qpow(p0, y / x) % mod;
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