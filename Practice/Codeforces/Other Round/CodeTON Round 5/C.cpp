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
		int n = read(), a[n + 1];
		for (int i = 1; i <= n; i++) a[i] = read();
		int ans = 0, f[n + 1][2], min[n + 1] = {0};
		memset(f, 0x3f, sizeof(f));
		memset(min, 0x3f, sizeof(min));
		f[1][0] = 1; min[a[1]] = 1;
		for (int i = 2; i <= n; i++) {
			f[i][0] = std::min(f[i - 1][0], f[i - 1][1]) + 1;
			if (min[a[i]]) f[i][1] = min[a[i]] - 1;
			min[a[i]] = std::min(min[a[i]], f[i][0]);
		}
		printf("%d\n", n - std::min(f[n][0], f[n][1]));
	}
	return 0;
}