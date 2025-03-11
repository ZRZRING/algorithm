#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS \
	std::ios::sync_with_stdio(false), \
	std::cin.tie(0), \
	std::cout.tie(0)

const int64 mod = 1e9 + 7;

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

int N = 1e7, T = 1;

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

struct BINOM {
	int n;

	std::vector<int> mul, inv;

	BINOM(int n) : n(n) {
		mul.resize(n + 1);
		inv.resize(n + 1);
		mul[0] = 1;
		for (int i = 1; i <= n; i++) {
			mul[i] = 1ll * mul[i - 1] * i % mod;
		}
		inv[n] = qpow(mul[n]);
		for (int i = n - 1; i >= 0; i--) {
			inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
		}
	}

	int C(int n, int m) {
		return 1ll * mul[n] * inv[m] % mod * inv[n - m] % mod;
	}
};

BINOM binom(N);

void init() {
	Fast_IOS;
	std::cin >> T;
}

void solve() {
	int n, k;
	std::cin >> n >> k;
	int res;
	if (n % 2 == 1) {
		res = 0;
	} else if (k > n / 2) {
		res = binom.C(n, k);
	} else {
		res = QMOD(binom.C(n, k) - 1ll * binom.C(n / 2, k) * qpow(2, k) % mod);
	}
	std::cout << res << '\n';
}

int main() {
	init();
	while (T--) {
		solve();
	}
	return 0;
}