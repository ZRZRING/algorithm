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

const int N = 1e6, mod = 1e9 + 7, inf = 0x3f3f3f3f;

int mul[N + 1], inv[N + 1], d[N + 1], ans[N + 1], cnt[N + 1];

int64 qpow(int64 a, int64 x = mod - 2) {
	int64 res = 1ll;
	while (x) {
		if (x & 1) res = res * a % mod; a = a * a % mod; x >>= 1;
	}
	return res;
}

int64 C(int n, int m) {
	return 1ll * mul[n] * inv[m] % mod * inv[n - m] % mod;
}

int main() {
	int T = read(); 
	mul[0] = 1;
	for (int i = 1; i <= 1e6; i++) mul[i] = 1ll * mul[i - 1] * i % mod;
	inv[N] = qpow(mul[N]);
	for (int i = N - 1; i >= 1; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
	inv[0] = 1;
	while (T--) {
		int n = read(), m = read();
		memset(d, 0, sizeof(d));
		for (int i = 1; i <= m; i++) {
			int u = read(), v = read(); d[u]++; d[v]++;
		}
		std::sort(d + 1, d + n + 1);
		int t = 0;
		for (int i = 1; i <= n; i++) {
			int x = i;
			while (x < n && d[x] == d[x + 1]) x++;
			cnt[++t] = x - i + 1; d[t] = d[i]; i = x;
		}
		int res = 0; m = t; t = 1;
		// for (int i = 1; i <= m; i++) printf("%d %d\n", cnt[i], d[i]);
		memset(ans, 0, sizeof(ans));
		for (int i = 2; i <= n - 1; i++) {
			while (d[t] < i) t++;
			for (int j = t; j <= m; j++) {
				ans[i] += 1ll * C(d[j], i) % mod * cnt[j] % mod;
				ans[i] %= mod;
			}
			// printf("%d\n", ans[i]);
			res ^= ans[i];
		}
		printf("%d\n", res);
	}
	return 0;
}