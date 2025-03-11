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

int main() {
	srand(time(0)); n = 200000; m = 200000; printf("%d %d\n", n, m);
	for (int i = 1; i <= n; i++) printf("%d", rand() % 2); printf("\n");
	for (int i = 1; i <= m / 2; i++) {
		int l = roll(1, 200000), r = roll(1, 200000);
		if (l > r) swap(l, r); printf("%d %d\n", l, r);
	}
	for (int i = m / 2 + 1; i <= m; i++) {
		int l = roll(1, 20000), r = n - roll(0, 20000);
		if (l > r) swap(l, r); printf("%d %d\n", l, r);
	}
	return 0;
}