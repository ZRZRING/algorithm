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

int N, T = 1;

void init() {
	Fast_IOS;
	std::cin >> T;
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
	int64 l, r;
	std::cin >> l >> r;
	int64 L = sqrtl(l), R = sqrtl(r);
	if (L * L < l) L++;
	int64 sum = (r - l + 1) % mod * (r - l + 2) % mod;
	if (L > R) {
		std::cout << 0 << '\n';
		return;
	}
	int64 ans = QMOD(
		(L * L - l) * (L * L - l + 1) % mod + 
		(r - R * R) * (r - R * R + 1) % mod
	);
	L = (L + 1) * (L + 1) - L * L;
	R = R * R - (R - 1) * (R - 1);
	L = (L - 1) / 2;
	R = (R - 1) / 2;
	auto cal = [&](int64 n) -> int64 {
		n %= mod;
		return QMOD(
			2ll * n * (n + 1) % mod * (2 * n + 1) % mod * qpow(3) % mod + 
			n * (n + 1) % mod
		);
	};
	QMOD(ans += cal(R) - cal(L - 1));
	std::cout << QMOD(sum - ans) << '\n';
}

int main() {
	init();
	while (T--) {
		solve();
	}
	return 0;
}