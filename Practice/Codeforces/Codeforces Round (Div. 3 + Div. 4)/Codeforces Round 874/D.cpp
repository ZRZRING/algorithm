#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>
#include <functional>

#define int64 long long

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int main() {
	int T = read();
	while (T--) {
		int n = read(), a[n + 1];
		for (int i = 1; i <= n; i++) a[i] = read();
		if (n == 1) {printf("1\n"); continue;}
		int x = 0;
		for (int i = 1; i <= n; i++) if (a[i] == n) x = i;
		if (x == 1) {
			for (int i = 2; i <= n; i++) if (a[i] == n - 1) x = i;
			if (x == n) {
				printf("%d ", n - 1);
				for (int i = 1; i <= n - 1; i++) printf("%d ", a[i]);
				puts("");
			} else {
				for (int i = x; i <= n; i++) printf("%d ", a[i]);
				printf("%d ", a[x - 1]);
				for (int i = 1; i <= x - 2; i++) printf("%d ", a[i]);
				puts("");
			}
			continue;
		}
		if (x == n) {
			x = n;
			while (a[x - 1] > a[1]) x--;
			for (int i = n; i >= x; i--) printf("%d ", a[i]);
			for (int i = 1; i <= x - 1; i++) printf("%d ", a[i]);
			puts(""); continue;
		}
		int t = x - 1;
		while (t > 1 && a[t - 1] > a[1]) t--;
		for (int i = x; i <= n; i++) printf("%d ", a[i]);
		for (int i = x - 1; i >= t; i--) printf("%d ",a[i]);
		for (int i = 1; i <= t - 1; i++) printf("%d ", a[i]);
		printf("\n");
	}
	return 0;
}