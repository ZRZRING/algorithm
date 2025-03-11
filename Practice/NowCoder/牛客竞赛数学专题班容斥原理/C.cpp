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

class BINOM {
	int n;

	std::vector<int> mul, inv;

	BINOM(int n) : n(n) {
		mul.resize(n + 1);
		inv.resize(n + 1);
		mul[0] = 1;
		for (int i = 1; i <= n; i++) {
			mul[i] = mul[i - 1] * i % mod;
		}
		inv[n] = qpow(mul[n]);
		for (int i = n - 1; i >= 0; i--) {
			inv[i] = inv[i + 1] * (i + 1) % mod;
		}
	}
};

class WORK {
	int N;

public:
	WORK() {}

	void solve() {
		int n;
		std::cin >> n;
		for (int i = 1; i <= n; i++) {

		}
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