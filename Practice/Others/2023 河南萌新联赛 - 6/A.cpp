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
	int n = read();
	std::vector<std::vector<int> > a(n + 1, std::vector<int>(40));
	for (int i = 1; i <= n; i++) {
		int64 x = read();
		for (int j = 0; j <= 30; j++) {
			a[i][j] = x & 1; x >>= 1;
		}
		for (int j = 0; j <= 30; j++) {
			a[i][j] += a[i - 1][j];
		}
	}
	int m = read();
	for (int i = 1; i <= m; i++) {
		int64 l = read(), r = read(), ans = 0;
		for (int j = 0; j <= 30; j++) {
			if (a[r][j] - a[l - 1][j] <= (r - l) / 2) ans |= 1 << j;
		}
		printf("%lld\n", ans);
	}
	return 0;
}