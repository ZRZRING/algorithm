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

int main() {
	int n = read(), m = read();
	int64 a[n + 1][2 * n + 1], f[2][2 * n + 1][2 * n + 1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i * 2 - 1; j++) {
			a[i][j] = read();
		}
	}
	memset(f, 0xcf, sizeof(f));
    int64 sup = f[0][0][0]; f[1][1][n] = a[1][1];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i * 2 - 1; j++) {
			for (int k = 0; k <= 2 * n; k++) {
                f[i & 1][j][k] = sup;
				if (k + 1 <= 2 * n && j <= i * 2 - 3) {
					f[i & 1][j][k] = std::max(f[i & 1][j][k], f[i & 1 ^ 1][j][k + 1]);
				}
				if (j - 1 >= 1 && j - 1 <= i * 2 - 3) {
					f[i & 1][j][k] = std::max(f[i & 1][j][k], f[i & 1 ^ 1][j - 1][k]);
				}
				if (k - 1 >= 0 && j - 2 >= 1) {
					f[i & 1][j][k] = std::max(f[i & 1][j][k], f[i & 1 ^ 1][j - 2][k - 1]);
				}
				f[i & 1][j][k] += a[i][j];
			}
		}
	}
	int64 ans = -1e15;
	for (int i = 1; i <= n * 2 - 1; i++) {
		for (int j = n - m; j <= n + m; j++) {
			ans = std::max(ans, f[n & 1][i][j]);
		}
	}
	printf("%lld\n", ans);
	return 0;
}