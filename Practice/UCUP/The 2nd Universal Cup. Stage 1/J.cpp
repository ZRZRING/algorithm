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
	int64 a = read(), b = read(), c = read(), d = read(), v = read(), t = read();
	int64 ans = (t / a + 1) * b + (t / c + 1) * d;
	if (std::min(a, c) <= v) {
		printf("%lld\n", ans - 1); return;
	}
	for (int i = 0; i < c; i++) {
		if (i * a > t) break;
		if ((i * a - 1 + c) % c + 1 > v) ans -= (t - i * a) / (a * c) + 1;
	}
	for (int i = 0; i < a; i++) {
		if (i * c > t) break;
		if (i * c % a > v) ans -= (t - i * c) / (a * c) + 1;
	}
	printf("%lld\n", ans);
}

int main() {
	int T = read();
	while (T--) solve();
	return 0;
}