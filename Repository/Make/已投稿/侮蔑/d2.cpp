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

const int N = 2e6 + 10, M = 1e9;

inline int read() {
	bool sym = 0; int res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int n, m, cnt, a[N], x[N], y[N];

void work() {
	n = 1000; printf("%d\n", n);
	for (int i = 1; i <= n; i++) printf("%d ", roll(1, M)); printf("\n");
	for (int i = 1; i <= n; i++) printf("%d ", roll(1, M)); printf("\n");
}

int main() {
	srand(time(0)); work(); return 0;
}