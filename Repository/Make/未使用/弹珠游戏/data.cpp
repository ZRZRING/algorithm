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

int main() {
	freopen("1.in", "w", stdout);
	srand(time(0));
	int T = 100; printf("%d\n", T);
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			printf("%d %d\n", i, j);
		}
	}
	freopen("2.in", "w", stdout);
	srand(time(0));
	T = 100; printf("%d\n", T);
	while (T--) {
		printf("%d %d\n", roll(1, 100), roll(1, 100));
	}
	return 0;
}