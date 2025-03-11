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

void solve() {
	int n = read();
	std::vector<int> a(n + 1), min(n + 1);
	for (int i = 1; i <= n; i++) a[i] = read();
	min[n] = a[n];
	for (int i = n - 1; i >= 1; i--) min[i] = std::min(min[i + 1], a[i]);
	std::vector<int> ans(n + 1);
	int m = read(), last = 0;
	for (int i = 1; i <= n; i++) {
		int t = m / (min[i] - last);
		m -= t * (min[i] - last);
		last = min[i];
		ans[i] = t;
		while (i + 1 <= n && min[i] == min[i + 1]) {
			i++; ans[i] = t;
		}
	}
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]); puts("");
}

int main() {
	int T = read();
	while (T--) solve();
	return 0;
}