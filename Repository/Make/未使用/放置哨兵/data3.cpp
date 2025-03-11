#include <bits/stdc++.h>

#define endl '\n'
#define int64 long long
#define lg(x) ((int)log10(x))
#define log(x) ((int)log2(x))
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

int main() {
	srand(time(0));
	freopen("4.in", "w", stdout);
	printf("2\n");
	int n = roll(9e4, 1e5), m = roll(9e4, 1e5);
	printf("%d %d\n", n, m);
	for (int i = 1; i <= m; i++) {
		int l = roll(1, n), len = roll(1, n - l);
		printf("%d %d\n", l, l + len);
	}
	n = roll(9e4, 1e5), m = roll(9e4, 1e5);
	printf("%d %d\n", n, m);
	for (int i = 1; i <= m; i++) {
		int l = roll(1, n), r = roll(1, n);
		if (l > r) std::swap(l, r);
		printf("%d %d\n", l, r);
	}
	return 0;
}