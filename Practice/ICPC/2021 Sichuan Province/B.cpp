#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>
#include <functional>

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
		int n = read(), k = read(), m = read(), a[2 * n + 1];
		int64 ans[n + 1] = {0};
		bool vis[k + 1] = {0};
		for (int i = 1; i <= n; i++) {
			a[i] = read(); a[i + n] = a[i];
		}
		for (int i = 1; i <= n && i <= m; i++) {
			if (vis[a[i]]) ans[i]++, vis[a[i]] = 0; else vis[a[i]] = 1;
		}
		for (int i = n + 1; i <= 2 * n && i <= m; i++) {
			if (vis[a[i]]) ans[i - n]++, vis[a[i]] = 0; else vis[a[i]] = 1;
		}
		if (m <= 2 * n) {
			for (int i = 1; i < n; i++) printf("%d ", ans[i]);
			printf("%d\n", ans[n]); continue;
		}
		for (int i = 1; i <= n; i++) ans[i] *= m / (n * 2); m -= m / (n * 2) * (n * 2);
		for (int i = 1; i <= n && i <= m; i++) {
			if (vis[a[i]]) ans[i]++, vis[a[i]] = 0; else vis[a[i]] = 1;
		}
		for (int i = n + 1; i <= 2 * n && i <= m; i++) {
			if (vis[a[i]]) ans[i - n]++, vis[a[i]] = 0; else vis[a[i]] = 1;
		}
		for (int i = 1; i < n; i++) printf("%d ", ans[i]);
		printf("%d\n", ans[n]);
	}
	return 0;
}