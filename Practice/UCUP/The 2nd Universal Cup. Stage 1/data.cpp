#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'
#define PII std::pair<int, int>
#define init_0(x) memset(x, 0, sizeof(x))
#define init_inf(x) memset(x, 0x3f, sizeof(x))

#define rd() (rand() << 15 | rand())
#define rd64() ((1ll * rd()) << 30 | (1ll * rd()))

const int N = 2e5, mod = 998244353, inf = 0x3f3f3f3f;

const long long Linf = 0x3f3f3f3f3f3f3f3f;

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int roll(int x, int y) {
	return rd() % (y - x + 1) + x;
}

int64 roll64(int64 x, int64 y) {
	return rd64() % (y - x + 1) + x;
}

void solve() {
	int n = 10, m = roll(1, n), q = 10;
	printf("%d %d %d\n", n, m, q);
	std::vector<int> a(n + 1);
	std::iota(a.begin(), a.end(), 0);
	std::random_shuffle(a.begin() + 1, a.end());
	for (int i = 1; i <= m; i++) printf("%d ", a[i]);
	puts("");
	for (int i = 2; i <= n; i++) {
		printf("%d %d\n", roll(1, i - 1), i);
	}
	while (q--) {
		int t = roll(1, n); printf("%d ", t);
		std::random_shuffle(a.begin() + 1, a.end());
		for (int i = 1; i <= t; i++) printf("%d ", a[i]);
		puts("");
	}
}

int main() {
	srand(time(0));
	int T = 1; printf("%d\n", T);
	while (T--) solve();
	return 0;
}