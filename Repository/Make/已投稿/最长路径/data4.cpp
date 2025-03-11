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
	freopen("10.in", "w", stdout);
	int n = 1e5, m = 1e5;
	printf("%d %d\n", n, m);
	bool vis[n + 1] = {0};
	int c1 = 3e4, c2 = 6e4, c3 = 9e4;
	for (int i = 2; i <= c1; i++) {
		printf("%d %d %d\n", i - 1, i, roll(1, 1e9));
	}
	for (int i = c1 + 1; i <= c2; i++) {
		printf("%d %d %d\n", c1, i, roll(1, 1e9));
	}
	for (int i = c2 + 1; i <= c3; i++) {
		printf("%d %d %d\n", c2, i, roll(1, 1e9));
	}
	for (int i = c3 + 1; i <= n; i++) {
		printf("%d %d %d\n", roll(1, i - 1), i, roll(1, 1e9));
	}
	for (int i = 1; i <= m; i++) {
		int x = roll(1, n), y = roll(1, n);
		printf("%d %d\n", x, y);
	}
	return 0;
}