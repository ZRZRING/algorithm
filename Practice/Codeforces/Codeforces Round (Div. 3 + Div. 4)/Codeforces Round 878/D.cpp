#include <bits/stdc++.h>

#define int64 long long

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int N = 1e6;

int a[N], n;

bool check(int x) {
	// printf("%d\n", x);
	int l = a[1], cnt = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i] - l > 2 * x) cnt++, l = a[i];
	}
	return cnt <= 3;
}

int main() {
	int T = read();
	while (T--) {
		n = read();
		for (int i = 1; i <= n; i++) a[i] = read();
		std::sort(a + 1, a + n + 1);
		int l = 0, r = 1e9;
		while (l < r) {
			int mid = l + r >> 1;
			if (check(mid)) r = mid; else l = mid + 1;
		}
		printf("%d\n", r);
	}
	return 0;
}