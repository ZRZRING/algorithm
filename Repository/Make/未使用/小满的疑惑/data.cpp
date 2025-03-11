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

void data1() {
	freopen("1.in", "w", stdout);
	int T = 3 * 3 * 3; printf("%d\n", T);
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			for (int k = 1; k <= 3; k++) {
				printf("3\n%d %d %d\n", i, j, k);
			}
		}
	}
}

void data2() {
	freopen("2.in", "w", stdout);
	int T = 4 * 4 * 4 * 4; printf("%d\n", T);
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int k = 1; k <= 4; k++) {
				for (int l = 1; l <= 4; l++) {
					printf("4\n%d %d %d %d\n", i, j, k, l);
				}
			}
		}
	}
}

void data3() {
	freopen("3.in", "w", stdout);
	int T = 5 * 5 * 5 * 5 * 5; printf("%d\n", T);
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			for (int k = 1; k <= 5; k++) {
				for (int l = 1; l <= 5; l++) {
					for (int m = 1; m <= 5; m++) {
						printf("5\n%d %d %d %d %d\n", i, j, k, l, m);
					}
				}
			}
		}
	}
}

void data4() {
	freopen("4.in", "w", stdout);
	srand(time(0));
	int T = 2; printf("%d\n", T);
	while (T--) {
		int n = 1e5; printf("%d\n", n);
		for (int i = 1; i <= n; i++) printf("%d ", roll(1, 1e9));
		puts("");
	}
}

void data5() {
	freopen("5.in", "w", stdout);
	srand(time(0));
	int T = 2; printf("%d\n", T);
	while (T--) {
		int n = 1e5; printf("%d\n", n);
		for (int i = 1; i <= n; i++) printf("%d ", roll(1, 10));
		puts("");
	}
}

int main() {
	data1();
	data2();
	data3();
	data4();
	data5();
	return 0;
}