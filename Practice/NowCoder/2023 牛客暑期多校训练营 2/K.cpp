#include <bits/stdc++.h>

#define int64 long long

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int N = 2e5 + 10, mod = 998244353;

int main() {
	int n = read(), a[n + 1], b[n + 1];
	a[0] = 0; b[0] = 0;
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i <= n; i++) b[i] = read();
	int64 f[n + 1][3][2];
	memset(f, -0x3f, sizeof(f));
	f[0][0][0] = 0;
	for (int i = 1; i <= n; i++) {
		if (b[i] == 0) {
			f[i][0][0] = std::max({f[i - 1][0][0], f[i - 1][0][1], f[i - 1][1][0], f[i - 1][1][1]});
			f[i][0][1] = std::max({f[i - 1][2][0], f[i - 1][2][1]}) + a[i];
		} else {
			f[i][0][1] = std::max({f[i - 1][0][0], f[i - 1][0][1], f[i - 1][1][0], f[i - 1][1][1]}) + a[i];
			f[i][1][0] = std::max({f[i - 1][0][0], f[i - 1][1][0]}) + a[i - 1];
			f[i][2][0] = std::max({f[i - 1][0][0], f[i - 1][0][1], f[i - 1][1][0], f[i - 1][1][1]});
			f[i][2][1] = std::max({f[i - 1][2][0], f[i - 1][2][1]}) + a[i];
		}
	}
	printf("%lld", std::max({f[n][0][0], f[n][0][1], f[n][1][0]}));
	return 0;
}