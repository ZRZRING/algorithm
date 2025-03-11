#include <bits/stdc++.h>

#define int64 long long

inline int64 read() {
	int64 res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int N = 1e5;

int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}

int main() {
	int n = read(), x[n + 1], c[n + 1];
	for (int i = 1; i <= n; i++) x[i] = read();
	for (int i = 1; i <= n; i++) c[i] = read();
	int ans = 1e9;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (gcd(x[i], x[j]) == 1) ans = std::min(ans, c[i] + c[j]);
		}
	}
	if (ans == 1e9) printf("-1"); else printf("%d\n", ans);
}