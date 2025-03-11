#include <bits/stdc++.h>

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
		int n = read(), a[n + 1], neg = 0, pos = 0, ans = 0;
		for (int i = 1; i <= n; i++) {
			a[i] = read(); if (a[i] == -1) neg++; else pos++;
		}
		while (neg > pos) neg--, pos++, ans++;
		printf("%d\n", ans + (neg & 1));
	}
	return 0;
}