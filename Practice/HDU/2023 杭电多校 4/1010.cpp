#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'
#define PII std::pair<int, int>

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int N = 2e5 + 10, mod = 998244353, inf = 0x3f3f3f3f;

int main() {
	int T = read();
	int ans[3][3] = {
		{1, 2, 1},
		{2, 2, 2},
		{1, 2, 1}
	};
	while (T--) {
		int n = read(), m = read();
		if (n > m) std::swap(n, m);
		if (n == 1) {
			printf("%d\n", (m + 1) / 2); continue;
		}
		while (n >= 5) n -= 3;
		while (m >= 5) m -= 3;
		printf("%d\n", ans[n - 2][m - 2]);
	}
	return 0;
}