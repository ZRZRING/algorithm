#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>

#define rd() (rand() << 15 | rand())
#define roll(x, y) (rd() % ((y) - (x) + 1) + (x))

using namespace std;

const int N = 1e6 + 10, M = 2e6 + 10, inf = 0x3f3f3f3f;

const long long Linf = 0x3f3f3f3f3f3f3f3f;

inline int read() {
	bool sym = 0; int res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int n, m, cnt;

void work(int n, int k) {
	printf("%d %d\n", n, k);
	for (int i = 1; i <= k; i++) {
		int x = rand() % 10;
		if (x == 0) {
			x = rand() % 9;
			if (x == 0) printf("P"); else if (x <= 4) printf("E"); else printf("M");
		} else {
			x = rand() % 4;
			if (x == 0) printf("A ");
			if (x == 1) printf("B ");
			if (x == 2) printf("L ");
			if (x == 3) printf("S ");
			printf("%d", roll(1, 6));
		}
		printf("\n");
	}
}

int main() {
	srand(time(0));
	int T1 = 30, T2 = 69, T3 = 1;
	printf("%d\n", T1 + T2 + T3);
	while (T1--) {
		n = roll(2, 20); int k = roll(1, n);
		work(n, k);
	}
	while (T2--) {
		n = roll(10, 30); int k = roll(1, n);
		work(n, k);
	}
	while (T3--) {
		n = roll(50000, 100000); int k = roll(n - 100, n);
		work(n, k);
	}
	return 0;
}