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
	std::vector<int64> a(n + 1), b(m + 1);
	std::vector<std::vector<int64> > c(n + 1);
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i <= m; i++) b[i] = read();
	for (int i = 0; i <= n; i++) {
		c[i].resize(m + 1); fill(c[i].begin(), c[i].end(), 0);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			c[i][j] = a[i] * b[j];
			c[i][j] = c[i][j] + c[i - 1][j] + c[i][j - 1] - c[i - 1][j - 1];
		}
	}
	int64 k = read(), ans = 0;
	for (int x1 = 1; x1 <= n; x1++) {
		for (int y1 = 1; y1 <= m; y1++) {
			for (int x2 = x1; x2 <= n; x2++) {
				for (int y2 = y1; y2 <= m; y2++) {
					int64 x = c[x2][y2] - c[x1 - 1][y2] - c[x2][y1 - 1] + c[x1 - 1][y1 - 1];
					if (x <= k) {
						ans = std::max(ans, 1ll * (x2 - x1 + 1) * (y2 - y1 + 1));
					}
				}
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}