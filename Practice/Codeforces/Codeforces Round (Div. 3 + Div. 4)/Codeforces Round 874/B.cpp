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

struct DATA {
	int val, id;
	friend bool operator < (const DATA a, const DATA b) {
		return a.val < b.val;
	}
};

int main() {
	int T = read();
	while (T--) {
		int n = read(), k = read();
		DATA a[n + 1], b[n + 1];
		for (int i = 1; i <= n; i++) {
			a[i].val = read(); a[i].id = i;
		}
		for (int i = 1; i <= n; i++) {
			b[i].val = read(); b[i].id = i;
		}
		std::sort(a + 1, a + n + 1);
		std::sort(b + 1, b + n + 1);
		int to[n + 1];
		for (int i = 1; i <= n; i++) {
			to[a[i].id] = i;
		}
		for (int i = 1; i <= n; i++) {
			printf("%d ", b[to[i]].val);
		}
		printf("\n");
	}
	return 0;
}