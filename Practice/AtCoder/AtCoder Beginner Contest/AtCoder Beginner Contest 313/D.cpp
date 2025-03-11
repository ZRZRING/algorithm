#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'
#define PII std::pair<int, int>
#define init_0(x) memset(x, 0, sizeof(x))
#define init_inf(x) memset(x, 0x3f, sizeof(x))

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int N = 2e5, mod = 998244353, inf = 0x3f3f3f3f;

int main() {
	int n = read(), k = read();
	std::vector<int> a(n + 1, 0);
	printf("? ");
	for (int i = 1; i <= k; i++) printf("%d ", i);
	puts(""); fflush(stdout);
	a[1] = read();
	for (int i = k + 1; i <= n; i++) {
		printf("? ");
		for (int j = 2; j <= k; j++) printf("%d ", j);
		printf("%d ", i);
		puts(""); fflush(stdout);
		a[i] = read();
	}
	for (int i = 2; i <= k; i++) {
		printf("? ");
		for (int j = 1; j <= k + 1; j++) if (j != i) printf("%d ", j);
		puts(""); fflush(stdout);
		a[i] = read();
	}
	int t = 0;
	for (int i = 2; i <= k; i++) t ^= a[i];
	for (int i = 2; i <= k; i++) a[i] ^= t ^ a[1] ^ a[k + 1];
	for (int i = k + 1; i <= n; i++) a[i] ^= t; a[1] ^= t;
	printf("! ");
	for (int i = 1; i <= n; i++) printf("%d ", a[i]);
	puts("");
	return 0;
}