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
	int n = read(), m = read(), t = read();
	int64 a[n + 1][m + 1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			a[i][j] = read();
		}
	}
	int64 f[n + 1][m + 1], max[n + 1];
	memset(f, 0, sizeof(f));
	memset(max, 0, sizeof(max));
	for (int i = 1; i <= m; i++) {
		f[1][i] = a[1][i];
		max[1] = std::max(max[1], f[1][i]);
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			f[i][j] = f[i - 1][j];
			if (i > t) f[i][j] = std::max(f[i][j], max[i - t] + a[i][j]);
			max[i] = std::max(max[i], f[i][j]);
		}
	}
	int64 ans = 0;
	for (int i = 1; i <= m; i++) ans = std::max(ans, f[n][i]);
	printf("%lld\n", ans);
	return 0;
}