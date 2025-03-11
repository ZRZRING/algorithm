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
		std::string A, B;
		std::cin >> A >> B;
		int n = A.length(), m = B.length();
		A = "#" + A;
		B = "#" + B;
		std::vector f(n + 1, std::vector<int>(m + 1));
		for (int i = 0; i <= n; i++) {
			f[i][0] = 1;
		}
		for (int i = 0; i <= m; i++) {
			f[0][i] = 1;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (A[i] == B[j]) {
					f[i][j] = MOD(1ll * f[i - 1][j] + f[i][j - 1]);
				} else {
					f[i][j] = MOD(1ll * f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1]);
				}
			}
		}
		// std::vector g(n + 1, std::vector<int>(m + 1));
		// for (int i = 1; i <= n; i++) {
		// 	for (int j = 1; j <= m; j++) {
		// 		if (A[i] < B[j]) {
		// 			g[i][j] = MOD(1ll * g[i - 1][j] + g[i][j - 1] + f[i - 1][j - 1] + 1);
		// 		} else {
		// 			g[i][j] = MOD(1ll * g[i - 1][j] + g[i][j - 1]);
		// 		}
		// 	}
		// }
		// std::cout << g[n][m] << '\n';
		std::vector<int64> mul(n + m + 1), inv(n + m + 1);
		mul[0] = 1;
		for (int i = 1; i <= n + m; i++) {
			mul[i] = mul[i - 1] * i % mod;
		}
		inv[n + m] = qpow(mul[n + m]);
		for (int i = n + m - 1; i >= 0; i--) {
			inv[i] = inv[i + 1] * (i + 1) % mod;
		}
		auto C = [&](int64 n, int64 m) -> int64 {
			return mul[n] * inv[m] % mod * inv[n - m] % mod;
		};
		int64 ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (A[i] < B[j]) {
					MOD(ans += f[i - 1][j - 1] * C(n - i + m - j, n - i) % mod);
				}
			}
		}
		std::cout << ans << '\n';
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