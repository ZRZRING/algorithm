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
		for (int i = 1; i <= n; i++) {
			a[i] = read();
		}
		std::sort(a + 1, a + n + 1);
		if (a[1] % 2 == 1) {printf("Yes\n"); continue;}
		bool flag = 1;
		for (int i = 1; i <= n; i++) {
			if (a[i] % 2 == 1) flag = 0;
		}
		printf(flag ? "Yes\n" : "No\n");
	}
	return 0;
}