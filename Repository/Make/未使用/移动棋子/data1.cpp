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

int n, m, cnt, a[N];

void work() {
	n = 1000000; m = roll(300000, 800000); printf("%d %d\n", n, m);
	for (int i = 1; i <= n; i++) a[i] = i;
	random_shuffle(a + 1, a + n + 1);
	for (int i = 1; i <= m; i++) {if (a[i] == 1) {m++; continue;}
	printf("%d ", a[i]);} printf("\n");
	for (int i = 2; i <= n; i++) printf("%d %d\n", roll(1, i - 1), i);
}

int main() {
	srand(time(0)); work(); return 0;
}