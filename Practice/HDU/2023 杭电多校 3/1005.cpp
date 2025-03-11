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
	int T = read();
	while (T--) {
		int n = read(), a[n + 1];
		for (int i = 1; i <= n; i++) a[i] = read();
		std::sort(a + 1, a + n + 1);
		int pre[n + 1], cnt[n + 1], k = 0;
		memset(pre, 0, sizeof(pre));
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; i++) {
			if (a[i] != a[i - 1]) k++; cnt[k]++;
		}
		for (int i = 1; i <= k; i++) pre[i] = 1;
		printf("%d\n", k);
		int s = 1;
		for (int i = 2; i <= n; i++) {
			int ans = 0;
			for (int j = s; j <= k; j++) pre[j] = (pre[j] + pre[j - 1]) % mod;
			if (a[i] != a[i - 1]) pre[s++] = 0;
			for (int j = s; j <= k; j++) ans = (ans + pre[j]) % mod;
			printf("%d\n", ans);
		}
	}
	return 0;
}