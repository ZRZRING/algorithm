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
		int n = read(), a[n + 1], s[1 << 10][2] = {0}, cnt = 0, max = 0;
		a[0] = 0;
		for (int i = 1; i <= n; i++) a[i] = read() ^ a[i - 1], max = std::max(max, a[i]);
		for (int i = 1; i <= n; i++) {
			int u = 0;
			for (int j = 8; j >= 0; j--) {
				int t = a[i] >> j & 1;
				if (!s[u][t]) s[u][t] = ++cnt;
				u = s[u][t];
			}
			int ans = 0; u = 0;
			for (int j = 8; j >= 0; j--) {
				int t = a[i] >> j & 1;
				if (s[u][t ^ 1]) u = s[u][t ^ 1], ans += 1 << j;
				else u = s[u][t];
			}
			max = std::max(max, ans);
		}
		printf("%d\n", max);
	}
	return 0;
}