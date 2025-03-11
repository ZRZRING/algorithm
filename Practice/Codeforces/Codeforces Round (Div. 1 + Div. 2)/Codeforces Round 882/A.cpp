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
		int n = read(), k = read(), a[n + 1], b[n], ans = 0;
		for (int i = 1; i <= n; i++) a[i] = read();
		for (int i = 1; i < n; i++) b[i] = abs(a[i] - a[i + 1]);
		std::sort(b + 1, b + n);
		for (int i = 1; i <= n - k; i++) ans += b[i];
		printf("%d\n", ans);
	}
	return 0;
}