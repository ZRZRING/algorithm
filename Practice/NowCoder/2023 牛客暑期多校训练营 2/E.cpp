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
		int64 x = read(), p10 = 1, ans = 0;
		if (x == 0) {printf("0\n"); continue;}
		while (x * p10 <= 1e18) {
			int64 y = std::sqrt(x * p10);
			if (y * y / p10 == x) {ans = y; break;}
			if ((y + 1) * (y + 1) / p10 == x) {ans = y + 1; break;}
			p10 *= 10;
		}
		if (!ans) printf("-1\n"); else printf("%lld\n", ans);
	}
	return 0;
}