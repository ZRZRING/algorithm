#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 1e9 + 7;

template <class T>
T MOD(T& x, int64 p = mod) {
    return x = (x % p + p) % p;
}
template <class T>
T MOD(T&& x, int64 p = mod) {
    return x = (x % p + p) % p;
}

class WORK {
   public:
    int N;

    WORK() {}

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
        std::cin >> n >> m;
        std::vector<int64> a(n + 1);
        int64 sum1 = 0, sum2 = 0, sum = 0;
        for (int i = 1; i <= n; i++) {
            std::cin >> a[i];
            MOD(sum1 += a[i] * (n - i + 1) % mod);
            MOD(sum2 += a[i] * i % mod);
            MOD(sum += a[i] * n % mod);
        }
		int64 ans1 = 0;
		MOD(ans1 += sum * (qpow(2, m) - 1) % mod * qpow(2, m - 1) % mod);
		MOD(ans1 += sum1 * qpow(2, m) % mod);
		int64 ans2 = 0;
		MOD(ans2 += sum * (qpow(2, m) - 1) % mod * qpow(2, m - 1) % mod);
		MOD(ans2 += sum1 * qpow(2, m - 1) % mod);
		MOD(ans2 += sum2 * qpow(2, m - 1) % mod);
        std::cout << std::max(ans1, ans2) % mod << '\n';
    }
};

int main() {
    Fast_IOS;
    WORK work;
    int T = 1;
    // std::cin >> T;
    while (T--) {
        work.solve();
    }
    return 0;
}