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
	int T = read();
	std::vector<int64> mul(1e6 + 10);
	mul[0] = 1;
	for (int i = 1; i <= 1e6; i++) mul[i] = mul[i - 1] * i % mod;
	while (T--) {
		int n = read(), k = read();
		printf("%lld\n", mul[std::min(n - 1, k)] * qpow(k, std::max(0, n - 1 - k)) % mod * mul[n] % mod);
	}
	return 0;
}