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
		int n = read(), m = read();
		for (int i = 1; i <= n - (n & 1); i++) {
			for (int j = 0; j < m; j++) {
				putchar(i & 1 ? j % 8 < 4 ? 'o' : 'x' : j % 8 < 4 ? 'x' : 'o');
			}
			puts("");
		}
		if (n & 1) {
			for (int i = 0; i < m; i++) putchar(i & 1 ? 'o' : 'x'); puts("");
		}
	}
	return 0;
}