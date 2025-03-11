#include <bits/stdc++.h>

#define int64 long long

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int N = 2e5 + 10, mod = 1e9 + 7, inf = 0x3f3f3f3f;

int main() {
	int n = read(), m = read(), a[n + 1];
	for (int i = 1; i <= n; i++) a[i] = read();
	int64 sum = 0, sub = 0;
	for (int i = 1; i <= m; i++) {
		int opt = read();
		if (opt == 1) sum += read();
		if (opt == 2) {
			sum -= read();
			if (sum < 0) sub += sum, sum = 0;
		}
	}
	int64 ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += sum + std::max(a[i] + sub, 0ll);
		ans %= mod;
	}
	printf("%lld\n", ans);
	return 0;
}