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
	int N = 1e6;

	WORK() {}

	void solve() {
		int n;
		std::cin >> n;
		std::vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		std::vector<int> f(N * 2);
		int L = N + a[2], R = N + a[2];
		f[L] = 1;
		int64 ans = qpow(2, n - 2) - (a[2] == 0) * qpow(2, n - 3);
		for (int i = 3; i <= n - 1; i++) {
			std::vector<int> _f(N * 2);
			for (int j = L; j <= R; j++) {
				if (!f[j]) continue;
				QMOD(_f[a[i] + (j - N) + N] += f[j]);
				if (j != N) QMOD(_f[a[i] - (j - N) + N] += f[j]);
			}
			f.swap(_f);
			int _L = std::min(L, a[i] - (R - N) + N);
			int _R = std::max(R, a[i] + (R - N) + N);
			L = _L;
			R = _R;
			// std::cout << i << ":\n";
			// for (int j = L; j <= R; j++) {
			// 	std::cout << j - N << ' ' << f[j] << '\n';
			// }
			// std::cout << '\n';
			QMOD(ans -= f[N] * qpow(2, n - i - 1) % mod);
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