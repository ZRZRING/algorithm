#include <bits/stdc++.h>

#define int64 long long
#define PII std::pair<int, int>
#define val first
#define id second

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
		int n = read(), ans[n + 1] = {0};
		PII a[n + 1];
		for (int i = 1; i <= n; i++) a[i] = {read(), i};
		std::sort(a + 1, a + n + 1);
		int l = 1, r = n, num = n;
		bool flag = 0;
		while (l <= r) {
			if ((a[l].first == n - r) ^ (a[r].first == n - l + 1)) {
				if (a[l].first == n - r) {
					ans[a[l++].second] = -(num--);
				} else {
					ans[a[r--].second] = num--;
				}
			} else {
				flag = 1; break;
			}
		}
		// printf("%d %d\n", l, r);
		if (flag) {printf("NO\n"); continue;}
		printf("YES\n");
		for (int i = 1; i <= n; i++) printf("%d ", ans[i]); puts("");
	}
	return 0;
}