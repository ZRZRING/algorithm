#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'
#define PII std::pair<int, int>
#define l first
#define r second
#define init_0(x) memset(x, 0, sizeof(x))
#define init_inf(x) memset(x, 0x3f, sizeof(x))

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int64 mod = 998244353;

void solve() {
	int n = read(), m = read();
	std::vector<PII> seg(m + 1);
	for (int i = 1; i <= m; i++) {
		seg[i] = {read(), read()};
	}
	std::sort(seg.begin() + 1, seg.end(), [](PII a, PII b) {return a.r < b.r;});
	std::vector<int64> f(n + 1);
	int max = 0;
	for (int i = 1, j = 0; i <= n; i++) {
		if (!max) f[i] = (f[i - 1] + f[i - 1] + 1) % mod;
		else f[i] = (f[i - 1] + f[i - 1] - f[max - 1] + mod) % mod;
		while (j + 1 <= m && seg[j + 1].r <= i) {
			max = std::max(max, seg[j + 1].l); j++;
		}
	}
	// for (int i = 1; i <= n; i++) printf("%d ", f[i]); puts("");
	printf("%lld\n", (f[n] - f[max - 1] + mod) % mod);
}

int main() {
	freopen("3.in", "r", stdin);
	freopen("3.out", "w", stdout);
	int T = read();
	while (T--) solve();
	return 0;
}