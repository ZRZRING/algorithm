#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'
#define PII std::pair<int, int>
#define init_0(x) memset(x, 0, sizeof(x))
#define init_inf(x) memset(x, 0x3f, sizeof(x))
#define lowbit(x) ((x) & -(x))

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
		int n = read();
		std::vector<int> cnt(n + 1, 0), a(n + 1, 0);
		for (int i = 1; i <= n; i++) a[i] = read();
		if (n == 1) {printf("0 1\n"); continue;}
		auto query = [&](int x) -> bool {
			int res = 0;
			for (int i = x; i; i -= lowbit(i)) res ^= cnt[i];
			return res;
		};
		auto add = [&](int x) {
			for (int i = x; i <= n; i += lowbit(i)) cnt[i] ^= 1;
		};
		bool ans = 0;
		for (int i = 1; i <= n; i++) {
			ans ^= query(a[i]); add(a[i]);
		}
		ans = 1ll * n * (n - 1) / 2 & 1 ^ ans;
		auto get = [&](int x) -> int {
			return (1 << std::__lg(x) + 1) - 1;
		};
		printf("%d %d\n", ans * 2, get(n) ^ (2 * (ans ^ 1)));
	}
	return 0;
}