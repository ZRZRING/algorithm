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
		int n = read(), k = read(), ans = 0;
		for (int i = 1; i <= n; i++) {
			int x = i, y = n - x, cnt = 2;
			while (x >= y) {
				int t = y; y = x - y; x = t; cnt++;
				if (cnt == k) {ans++; break;}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}