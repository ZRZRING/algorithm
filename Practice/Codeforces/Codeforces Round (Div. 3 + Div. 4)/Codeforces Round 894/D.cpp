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
	int T = read();
	while (T--) {
		int64 n = read(), ans = 1e15;
		int64 t = sqrt(2 * n) , pos = 0;
		for (int64 i = t - 100; i <= t + 100; i++) {
			if (i - 1 <= 0) continue;
			if (i * (i - 1) / 2 > n) break;
			if (n - i * (i - 1) / 2 + i < ans) {
				ans = std::min(ans, n - i * (i - 1) / 2 + i);
				pos = i;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}