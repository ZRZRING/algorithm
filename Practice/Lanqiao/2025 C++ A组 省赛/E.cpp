#include <bits/stdc++.h>

using int64 = long long;
using uint = unsigned int;
using A2 = std::array<int, 2>;

#define Fast_IOS \
	std::ios::sync_weith_stdio(false), \
	std::cin.tie(0), \
	std::cout.tie(0)

const int N = 5e5, mod = 1e9 + 7;

int T = 1;

int64 qpow(int64 a, int64 p = mod - 2) {
	a %= mod;
	p %= mod - 1;
	int64 res = 1;
	while (p) {
		if (p & 1) {
			res = res * a % mod;
		}
		a = a * a % mod;
		p >>= 1;
	}
	return res;
}

void init() {
//	Fast_IOS;
// 	std::cin >> T;	
}

void solve() {
	int n;
	std::cin >> n;
	std::vector<int64> mul(n), inv(n);
	mul[0] = 1;
	for (int i = 1; i <= n; i++) {
		mul[i] = mul[i - 1] * i % mod;
	}
	inv[n] = qpow(mul[n]);
	for (int i = n - 1; i >= 0; i--) {
		inv[i] = inv[i + 1] * (i + 1) % mod;
	}
	int m = 0;
	std::vector<int> a(n);
	int64 ans = mul[n - 2];
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		m = std::max(m, a[i]);
	}
	std::vector<int> cnt(m + 1);
	for (int i = 0; i < n; i++) {
		cnt[a[i]]++;
	}
	for (int i = 1; i <= m; i++) {
		ans = ans * inv[cnt[i]] % mod;
	}
//	std::cout << ans << '\n';
	std::set<A2> s;
	for (int i = 0; i < n; i++) {
		if ((n - 2) % a[i] != 0) {
			continue;
		}
		int x = a[i], y = (n - 2) / a[i];
		s.insert({x, y});
	}
	int64 res = 0;
	for (auto pair : s) {
		int x = pair[0], y = pair[1];
//		std::cout << x << ' ' << y << '\n';
		int64 t = ans;
		// if (x == y) {
		// 	t = t * qpow(2) % mod;
		// }
		t = t * mul[cnt[x]] % mod * inv[cnt[x] - 1] % mod;
		t = t * mul[cnt[y]] % mod * inv[cnt[y] - 1] % mod;
		res = (res + t) % mod;
//		std::cout << x << ' ' << y << ' ' << t << '\n';
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


