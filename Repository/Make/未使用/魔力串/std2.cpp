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

void solve() {
	int64 n = read(), f[n + 1][6] = {0};
	f[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 5; j++) {
			for (int k = 0; k <= 4; k++) {
				int x = j + (j == k);
				f[i][x] = (f[i][x] + f[i - 1][j]) % mod;
			}
		}
	}
	int64 g[n + 1][6] = {0};
	g[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 4; j++) {
			g[i][0] = (g[i][0] + g[i - 1][j] * 3) % mod;
			g[i][1] = (g[i][1] + g[i - 1][j]) % mod;
		}
		g[i][0] = (g[i][0] + g[i - 1][0]) % mod;
		for (int j = 2; j <= 5; j++) {
			g[i][j] = g[i - 1][j - 1];
		}
		g[i][5] = (g[i][5] + g[i - 1][5] * 5) % mod;
	}
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 0; j <= 5; j++) printf("%d ", f[i][j]); puts("");
	// }
	printf("%lld\n", (f[n][5] - g[n][5] + mod) % mod);
}

int main() {
	int T = read();
	while (T--) solve();
	return 0;
}