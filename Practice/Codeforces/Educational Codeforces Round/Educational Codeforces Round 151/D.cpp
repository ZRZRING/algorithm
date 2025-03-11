#include <bits/stdc++.h>

#define int64 long long

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int main() {
	int T = read();
	while (T--) {
		int64 n = read(), a[n + 1], pre[n + 1] = {0}, suf[n + 2] = {0};
		for (int i = 1; i <= n; i++) a[i] = read(), pre[i] = pre[i - 1] + a[i];
		for (int i = n; i >= 1; i--) suf[i] = suf[i + 1] + a[i];
		int64 ans = 0, max = 0, k = 0;
		for (int i = 1; i <= n; i++) {
			int64 t = max + std::max(0ll, suf[i]);
			if (t > ans) ans = t, k = max;
			max = std::max(max, pre[i]);
		}
		if (pre[n] > ans) ans = pre[n], k = pre[n];
		printf("%lld\n", k);
	}
	return 0;
}