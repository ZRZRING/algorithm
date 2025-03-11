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

const int N = 2e5, mod = 998244353, inf = 0x3f3f3f3f;

int64 qpow(int64 a, int64 x = mod - 2) {
    int64 res = 1ll;
    while (x) {
        if (x & 1) res = res * a % mod; a = a * a % mod; x >>= 1;
    }
    return res;
}

void solve() {
	int64 n = read(), f[n + 1][6] = {0};
	f[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 5; j++) {
			for (int k = 0; k <= 4; k++) {
				f[i][j + (j == k)] += f[i - 1][j];
				f[i][j + (j == k)] %= mod;
			}
		}
	}
	int64 mul[n + 1]; mul[0] = 1;
    for (int i = 1; i <= n; i++) {
        mul[i] = mul[i - 1] * i % mod;
    }
	auto C = [&](int64 n, int64 m) -> int64 {
    	return mul[n] * qpow(mul[m]) % mod * qpow(mul[n - m]) % mod;
	};
    int64 c = -1, ans = f[n][5];
    for (int i = 1; i <= n / 5; i++) {
        ans = (ans + c * C(n - 4 * i, i) % mod * qpow(5, n - 5 * i) % mod + mod) % mod;
		c = -c;
    }
	printf("%lld\n", ans);
}

int main() {
    int T = read();
    while (T--) solve();
    return 0;
}