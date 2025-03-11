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

int n, m, cnt, a[N], b[N];

int main() {
	srand(time(0));
	n = 100000; m = 100000;
	for (int i = 1; i <= n; i++) printf("%d ", roll(0, 1000)); printf("\n");
	for (int i = 1; i <= m >> 1; i++) {
		int l = roll(1, n), r = roll(1, n); printf("%d %d\n", min(l, r), max(l, r));
	}
	for (int i = 1; i <= m >> 1; i++) {
		int l = roll(1, 10000), r = roll(90000, 100000); printf("%d %d\n", l, r);
	}
	return 0;
}