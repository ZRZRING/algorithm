#include <bits/stdc++.h>

#define int64 long long

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int mod = 998244353;

int qpow(int a, int x = mod - 2) {
	int res = 1;
	while (x) {
		if (x & 1) res = 1ll * res * a % mod; a = 1ll * a * a % mod; x >>= 1;
	}
	return res;
}

int main() {
	int n = read(), m = read(), l = n, x = std::__lg(l + 1), ans = 1;
	while (l <= n + m - 1) {
		int r = std::min(n + m - 1, (1 << x + 1) - 2);
		// printf("%d %d %d\n", l, r, x);
		ans = 1ll * ans * qpow(mod + 1 - qpow(2, mod - x - 1), r - l + 1) % mod;
		l = r + 1; x = std::__lg(l + 1);
	}
	printf("%d", ans);
	return 0;
}