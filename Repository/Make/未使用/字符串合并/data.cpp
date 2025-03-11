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
	freopen("1.in", "w", stdout);
	{
		int T = 10000; printf("%d\n", T);
		while (T--) {
			int n = roll(2, 4) * 2, m = roll(4, 10);
			printf("%d\n", n / 2);
			for (int i = 1; i <= n; i++) std::cout << (char)(roll(0, m) + 'a'); puts("");
			for (int i = 1; i <= n; i++) std::cout << (char)(roll(0, m) + 'a'); puts("");
			for (int i = 1; i <= n; i++) std::cout << (char)(roll(0, m) + 'a'); puts("");
		}
	}
	freopen("2.in", "w", stdout);
	{
		int T = 2; printf("%d\n", T);
		while (T--) {
			int n = roll(9e4, 1e5) * 2, m = 25;
			printf("%d\n", n / 2);
			for (int i = 1; i <= n; i++) std::cout << (char)(roll(0, m) + 'a'); puts("");
			for (int i = 1; i <= n; i++) std::cout << (char)(roll(0, m) + 'a'); puts("");
			for (int i = 1; i <= n; i++) std::cout << (char)(roll(0, m) + 'a'); puts("");
		}
	}
	freopen("3.in", "w", stdout);
	{
		int T = 100; printf("%d\n", T);
		while (T--) {
			int n = roll(900, 1000) * 2, m = 2;
			printf("%d\n", n / 2);
			for (int i = 1; i <= n; i++) std::cout << (char)(roll(0, m) + 'a'); puts("");
			for (int i = 1; i <= n; i++) std::cout << (char)(roll(0, m) + 'a'); puts("");
			for (int i = 1; i <= n; i++) std::cout << (char)(roll(0, m) + 'a'); puts("");
		}
	}
	return 0;
}