#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'
#define PII std::pair<int, int>
#define init_0(x) memset(x, 0, sizeof(x))
#define init_inf(x) memset(x, 0x3f, sizeof(x))

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int N = 2e5, mod = 998244353, inf = 0x3f3f3f3f;

int main() {
	int T = read();
	while (T--) {
		int n = read(), m = read(), d = read(), ans = m;
		std::vector<int> a(m + 2, 0);
		a[0] = 1 - d; a[m + 1] = n + 1;
		for (int i = 1; i <= m; i++) a[i] = read();
		for (int i = 1; i <= m + 1; i++) ans += (a[i] - a[i - 1] - 1) / d;
		int min = ans, cnt = 0;
		for (int i = 1; i <= m; i++) {
			int x = ans - (a[i] - a[i - 1] - 1) / d - (a[i + 1] - a[i] - 1) / d - 1 + (a[i + 1] - a[i - 1] - 1) / d;
			if (x < min) min = x, cnt = 0;
			if (x == min) cnt++;
		}
		printf("%d %d\n", min, cnt);
	}
	return 0;
}