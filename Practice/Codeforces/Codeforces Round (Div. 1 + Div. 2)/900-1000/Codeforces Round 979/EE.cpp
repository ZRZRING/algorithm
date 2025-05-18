#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

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

class WORK {
public:
	int N = 2e5;

	std::vector<int64> mul, inv;

	WORK() {
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
		int n;
		std::cin >> n;
		std::vector<int> vis(n + 1);
		for (int i = 1; i <= n; i++) {
			int x;
			std::cin >> x;
			vis[x]++;
		}
		if (vis[0] == 0) {
			std::cout << 0 << '\n';
			return;
		}
		int64 pow2 = qpow(2, n - vis[0]), ans = 0;
		for (int i = 1; i <= vis[0]; i++) {
			// std::cout << C(vis[0], i) << '\n';
			QMOD(ans += C(vis[0], i) * i % mod * pow2 % mod);
		}
		// std::cout << ans << '\n';
		QMOD(ans = ans - qpow(2, n) + mod + qpow(2, n - vis[0]));
		// std::cout << ans << '\n';
		int64 rest = n - vis[0], t = 1;
		for (int i = 1; i <= n; i++) {
			if (vis[i - 1] == 0) break;
			rest -= vis[i];
			MOD(t *= qpow(2, vis[i - 1]) - 1 + mod);
			QMOD(ans += qpow(2, rest) * t % mod * i % mod);
		}
		std::cout << ans << '\n';
	}
};

int main() {
	Fast_IOS;
	WORK work;
	int T = 1;
	std::cin >> T;
	while (T--) {
		work.solve();
	}
	return 0;
}