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
		int n = read(), x = read(), a[n + 1], b[n + 1], c[n + 1];
		a[0] = 0; b[0] = 0; c[0] = 0;
		for (int i = 1; i <= n; i++) a[i] = a[i - 1] | read();
		for (int i = 1; i <= n; i++) b[i] = b[i - 1] | read();
		for (int i = 1; i <= n; i++) c[i] = c[i - 1] | read();
		a[0] = n; b[0] = n; c[0] = n;
		for (int i = 1; i <= n; i++) {
			bool flag = 1;
			for (int j = 0; j <= 30; j++) {
				if ((a[i] >> j & 1) == 1 && (x >> j & 1) == 0) {
					a[0] = i - 1; flag = 0;
				}
			}
			if (!flag) break;
		}
		for (int i = 1; i <= n; i++) {
			bool flag = 1;
			for (int j = 0; j <= 30; j++) {
				if ((b[i] >> j & 1) == 1 && (x >> j & 1) == 0) {
					b[0] = i - 1; flag = 0;
				}
			}
			if (!flag) break;
		}
		for (int i = 1; i <= n; i++) {
			bool flag = 1;
			for (int j = 0; j <= 30; j++) {
				if ((c[i] >> j & 1) == 1 && (x >> j & 1) == 0) {
					c[0] = i - 1; flag = 0;
				}
			}
			if (!flag) break;
		}
		if ((a[a[0]] | b[b[0]] | c[c[0]]) == x) printf("Yes\n"); else printf("No\n");
	}
	return 0;
}