#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'
#define PII std::pair<int64, int64>
#define init_0(x) memset(x, 0, sizeof(x))
#define init_inf(x) memset(x, 0x3f, sizeof(x))

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int64 N = 2e5 + 10, mod = 998244353, inf = 0x3f3f3f3f;

int main() {
	int T = read();
	while (T--) {
		int64 n = read();
		int ans = 0;
		for (int64 i = 1; i <= 1e4; i++) {
			int cnt = 0;
			while (n % i == 0) cnt++, i++; ans = std::max(cnt, ans);
		}
		for (int j = 2; j <= 4; j++) {
			int64 c = pow(n, 1.0 / j);
			for (int i = c; i <= c + 1e3; i++) {
				int cnt = 0;
				while (n % i == 0) cnt++, i++; ans = std::max(cnt, ans);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}