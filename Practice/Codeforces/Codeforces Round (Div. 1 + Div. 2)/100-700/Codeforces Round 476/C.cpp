#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'
#define PII std::pair<int, int>
#define init_0(x) memset(x, 0, sizeof(x))
#define init_inf(x) memset(x, 0x3f, sizeof(x))

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int N = 2e5, mod = 1e9 + 7, inf = 0x3f3f3f3f;

int64 qpow(int64 a, int64 x = mod - 2) {
	int64 res = 1ll;
	while (x) {
		if (x & 1) res = res * a % mod; a = a * a % mod; x >>= 1;
	}
	return res;
}

int main() {
	int a = read(), b = read(), ans = 0, inv_2 = qpow(2);
	// for (int i = 1; i < b; i++) {
	// 	for (int k = 1; k <= a; k++) {
	// 		ans += (1ll * k * i * b + i);
	// 	}
	// }
	for (int i = 1; i < b; i++) {
		ans = (ans + (1ll * (a + 1ll) * inv_2 % mod * b % mod + 1ll) * i % mod * a % mod) % mod;
	}
	printf("%d\n", ans);
	return 0;
}