#include <bits/stdc++.h>

#define int64 long long

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int main() {
	int n = read(), a[n + 1];
	for (int i = 1; i <= n; i++) a[i] = read();
	int min = 1, c[31] = {0};
	int64 ans = 0;
	for (int i = 1; i <= n; i++) {
		int l = n, r = i;
		for (int j = 0; j <= 30; j++) {
			if ((a[i] >> j & 1) == 0) c[j] = i;
			l = std::min(c[j], l);
		}
		ans += l;
	}
	printf("%lld\n", ans);
	return 0;
}