#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>
#include <functional>

#define int long long

inline int read() {
	bool sym = 0; int res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int mod = 998244353;

void MOD(int &x) {
	while (x < 0) x += mod; x %= mod;
}

int qpow(int a, int x) {
	int res = 1;
	while (x) {
		if (x & 1) res = 1ll * res * a % mod;
		a = 1ll * a * a % mod; x >>= 1;
	}
	return res;
}

signed main() {
	int n = read(), m = read(), Q = read(), mul[n + 1], inv[n + 1];
	if (n < m) std::swap(n, m);
	mul[0] = 1;
	for (int i = 1; i <= n; i++) {
		mul[i] = mul[i - 1] * i % mod; inv[i] = qpow(mul[i], mod - 2);
	}
	auto C = [&](int n, int m) -> int {
		return mul[n] * inv[m] % mod * inv[n - m] % mod;
	};
	auto A = [&](int n, int m) -> int {
		return mul[n] * inv[n - m] % mod;
	};
	int ans0 = 1ll * qpow(m, n - 1) * qpow(n, m - 1) % mod;
	int ans1 = qpow(m, n - 1), c = -1;
	for (int i = 1; i < m; i++) {
		MOD(ans1 += C(m, i) * qpow(m - i, n - 1) % mod * c); c = -c;
	}
	int ans2 = qpow(m - 1, n - 1); c = -1;
	for (int i = 1; i < m - 1; i++) {
		MOD(ans1 += C(m - 1, i) * qpow(m - 1 - i, n - 1) % mod * c); c = -c;
	}
	ans1 = n * (ans1 + m * ans2 % mod) % mod;
	while (Q--) {
		int q = read();
		if (q == 0) {printf("%lld\n", ans0); continue;}
		if (q == 1) {printf("%lld\n", ans1); continue;}
		if (q >= 2) {printf("1\n"); continue;}
	}
	return 0;
}