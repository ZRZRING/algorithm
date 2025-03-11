#include <bits/stdc++.h>

using int64 = long long;

#define NO 2
#define YES 1
#define endl '\n'
#define PII std::pair<int64, int64>
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0)
#define debug(x) std::cerr << "In Line " << __LINE__ << " the " << #x << " = " << x << '\n';

const int64 mod = 998244353;

template <class T> int64 abs(T x) {return x < 0 ? -x : x;}
template <class T> void MOD(T &x) {x = x % mod;}
template <class T> int64 lg(T x) {return (int)log10(x);}
template <class T> int64 log(T x) {return (int)log2(x);}

int64 qpow(int64 a, int64 x = mod - 2) {
    int64 res = 1;
    while (x) {
        if (x & 1) res = res * a % mod;
        a = a * a % mod;
        x >>= 1;
    }
    return res;
}

int solve() {
    int n, m;
    std::cin >> n >> m;
    int64 ans = 0;
	std::vector<int64> mul(n + 1), inv(n + 1);
	mul[0] = 1;
	for (int i = 1; i <= n; i++) {
		mul[i] = mul[i - 1] * i % mod;
	}
    inv[n] = qpow(mul[n]);
    for (int i = n - 1; i >= 0; i--) {
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
    auto C = [&](int64 n, int64 m) -> int64 {
        if (n < 0) return 0;
        if (m > n) return 0;
		return mul[n] * inv[m] % mod * inv[n - m] % mod;
    };
    auto R = [&](int64 n, int64 m) -> int64 {
		return C(n + m - 1, m - 1);
    };
    for (int i = 0; i <= (n - 2 * m) / 2; i++) {
        MOD(ans += R(n - 2 * m - 2 * i, m + 1) * R(i, m) % mod);
    }
    int64 cnt = C(n, 2 * m);
    std::cout << (cnt - ans + mod) * 2 % mod << endl;
    return 0;
}

int main() {
    Fast_IOS;
    int T = 1;
    std::cin >> T;
    while (T--) {
        int t = solve();
        if (t == 0)
            continue;
        if (t == YES)
            std::cout << "YES" << endl;
        if (t == NO)
            std::cout << "NO" << endl;
    }
    return 0;
}