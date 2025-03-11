#include <bits/stdc++.h>

#define int64 long long

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int N = 2e5 + 10, mod = 998244353, inf = 0x3f3f3f3f;

int main() {
	int T = read();
	while (T--) {
		int n = read(), a[n + 1];
		for (int i = 1; i <= n; i++) a[i] = read();
		int ans = 1e9;
		for (int i = 2; i <= n; i++) {
			ans = std::min(ans, a[i] - a[i - 1]);
		}
		if (ans < 0) printf("0\n"); else printf("%d\n", ans / 2 + 1);
	}
	return 0;
}