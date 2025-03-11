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
		int n = read(), Q = read();
		std::vector<int64> a(n), pre(n + 1), odd(n + 1), even(n + 1);
		for (auto &x : a) x = read();
		pre[0] = 0;
		for (int i = 1; i <= n; i++) {
			pre[i] = pre[i - 1] + a[i - 1];
			odd[i] = odd[i - 1] + (pre[i] % 2 == 1);
			even[i] = even[i - 1] + (pre[i] % 2 == 0);
		}
		while (Q--) {
			int l = read(), r = read(), t = read();
			if (pre[l - 1] % 2 != pre[r] % 2) {
				printf("NO\n"); continue;
			}
			if (pre[r] % 2 == 0) {
				printf(even[r - 1] - even[l - 1] >= t - 1 ? "YES\n" : "NO\n");
			} else {
				printf(odd[r - 1] - odd[l - 1] >= t - 1 ? "YES\n" : "NO\n");
			}
		}
	}
	return 0;
}