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

int n = 1000000, a[N];

int main() {
    srand(GetTickCount());
	printf("%d\n", n);
	a[0] = roll(-1000, 1000);
	for (int i = 1; i <= n; i++) {
		a[i] = a[i - 1] + roll(-1, 1);
		a[i] = std::min(1000, a[i]);
		a[i] = std::max(-1000, a[i]);
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", a[i]);
	}
	puts("");
	return 0;
}
