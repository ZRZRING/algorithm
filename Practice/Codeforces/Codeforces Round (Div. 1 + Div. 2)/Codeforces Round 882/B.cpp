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
		int n = read(), t = read(), a[n + 1], ans = 0;
		a[1] = t;
		for (int i = 2; i <= n; i++) a[i] = read(), t &= a[i];
		if (t) {printf("1\n"); continue;}
		t = 0;
		for (int i = 1; i <= n; i++) {
			if (!t) t = a[i]; else t &= a[i];
			if (!t) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}