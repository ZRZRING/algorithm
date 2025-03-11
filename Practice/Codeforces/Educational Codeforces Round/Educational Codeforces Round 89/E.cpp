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
	int n = read(), m = read();
	std::vector<int> a(n + 1), b(m + 1);
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i <= m; i++) b[i] = read();
	int x = n, ans = 1;
	while (a[x] > b[m]) x--;
	if (a[x] < b[m]) {printf("0\n"); return 0;}
	for (int i = m - 1; i >= 1; i--) {
		int t = x;
		while (a[x] >= b[i + 1]) x--;
		t = t - x;
		while (a[x] > b[i]) x--;
		if (a[x] < b[i]) {printf("0\n"); return 0;}
		ans = 1ll * ans * t % mod;
	}
	while (x && a[x] >= b[1]) x--;
	if (x) {printf("0\n"); return 0;}
	printf("%d\n", ans);
	return 0;
}