#include<iostream>
#include<cstdio>
#include<cstring>
#include<windows.h>
#include<random>
#include<algorithm>

#define rd() (rand() << 15 | rand())
#define roll(x, y) (rd() % ((y) - (x) + 1) + (x))

std::mt19937 rnd(GetTickCount());

const int N = 1e6 + 10, M = 2e6 + 10, inf = 0x3f3f3f3f;

const long long Linf = 0x3f3f3f3f3f3f3f3f;

int main() {
    srand(GetTickCount());
	int n = roll(900, 1000), a[n + 1]; printf("%d\n", n);
	for (int i = 1; i <= n; i++) a[i] = roll(-1000, 1000);
	std::sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) printf("%d ", a[i]);
	puts("");
	return 0;
}
