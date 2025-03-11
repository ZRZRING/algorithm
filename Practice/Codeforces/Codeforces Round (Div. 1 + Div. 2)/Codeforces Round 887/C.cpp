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
		int n = read(), K = read(), a[n + 1];
		int64 ans = 1, cnt = 1;
		for (int i = 1; i <= n; i++) a[i] = read();
		if (a[1] != 1) {printf("1\n"); continue;}
		while (K--) {
			while (cnt <= n && a[cnt] <= ans + cnt - 1) cnt++;
			ans += cnt - 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}