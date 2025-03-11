#include <bits/stdc++.h>

using int64 = long long;

const int64 mod = 998244353;

template<class T>
T MOD(T &x) {
	return (x = (x % mod + mod) % mod);
}

template<class T>
T MOD(T &&x) {
	return (x = (x % mod + mod) % mod);
}

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
	int64 n, m;
	std::cin >> n >> m;
	int64 ans1 = 1, ans2 = 1, mul26 = 1, inv26 = 1, t1 = 1, t2 = 0;
	for (int i = 1; i <= m; i++) {
		mul26 = mul26 * 26ll % mod;
		inv26 = inv26 * 729486258ll % mod;
		t1 = std::min(t1 * 26ll, n);
		t2 = mul26 * (mod + 1ll - qpow(mod + 1ll - inv26, n)) % mod;
		MOD(ans1 += t1);
		MOD(ans2 += t2);
	}
	std::cout << ans1 << ' ' << ans2 << '\n';
}

int main() {
	int T = 1;
	while (T--) {
		solve();
	}
}