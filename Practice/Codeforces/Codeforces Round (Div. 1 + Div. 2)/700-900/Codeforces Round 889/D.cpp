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
	int n = read();
	std::vector<int> a(n);
	for (auto &x : a) x = read();
	const int N = 2e5 + 10;
	std::bitset<N> f;
	f.reset(); f[0] = 1;
	for (int i = 0; i < n; i++) f |= (f >> i) << i + a[i];
	int64 sum = 0, ans = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (i < n) sum += a[i];
		if (f[i]) ans = std::max(ans, sum - i);
	}
	printf("%lld", ans);
	return 0;
}