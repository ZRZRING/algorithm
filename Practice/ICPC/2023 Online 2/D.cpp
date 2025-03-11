#include <bits/stdc++.h>

#define int64 long long

int64 read() {
	int64 res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int main() {
	int T = read();
	while (T--) {
		int n = read();
		int64 min_h[n + 1], min_v[n + 1];
		memset(min_h, 0x3f, sizeof(min_h));
		memset(min_v, 0x3f, sizeof(min_v));
		int64 ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int64 x = read();
				if (x <= 0) ans += x;
				min_h[i] = std::max(0ll, std::min(min_h[i], x));
				min_v[j] = std::max(0ll, std::min(min_v[j], x));
			}
		}
		int64 res1 = 0, res2 = 0;
		for (int i = 1; i <= n; i++) res1 += min_h[i];
		for (int i = 1; i <= n; i++) res2 += min_v[i];
		// for (int i = 1; i <= n; i++) printf("%lld ", min_h[i]); puts("");
		// for (int i = 1; i <= n; i++) printf("%lld ", min_v[i]); puts("");
		printf("%lld\n", ans + std::min(res1, res2));
		// printf("%lld %lld\n", ans, std::min(res1, res2));
	}
}