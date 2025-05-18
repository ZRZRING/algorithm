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

const int64 mod = 998244353;

void solve() {
	int m = read(), n = read(); m %= n;
	if (__builtin_popcount(n / std::__gcd(n, m)) != 1) {
		printf("-1\n"); return;
	}
	printf("%lld\n", 1ll * __builtin_popcount(m / std::__gcd(n, m)) * n - m);
}

int main() {
	int T = read();
	while (T--) solve();
	return 0;
}