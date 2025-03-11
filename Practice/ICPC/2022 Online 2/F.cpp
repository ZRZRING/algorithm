#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<queue>

#define mp(x, y) make_pair(x, y)

using namespace std;

const int N = 2e6 + 10;

long long read() {
	long long res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int n, m;

double pw[N];

int main() {
	int T = read();
	while (T--) {
		long long k = read(), x = read(), y = read(); if (x < y) swap(x, y); pw[1] = 1;
		for (int i = 2; i <= 100000; i++) {
			pw[i] = pw[i - 1] * (k + 1); if (pw[i] >= x) break;
		}
		// for (int i = 2; pw[i - 1] <= x; i++) printf("%lld ", pw[i]); printf("\n");
		while (x != y) {
			// printf("%lld %lld\n", x, y);
			if (x < y) swap(x, y); int t = 1; while (pw[t] < x) t++;
			// printf("%lld\n", t);
			x = (x - (long long)pw[t - 1] + k - 1ll) / k;
		}
		printf("%lld\n", x);
	}
	return 0;
}