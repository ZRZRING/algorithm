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

const int N = 2e5 + 10, mod = 998244353, inf = 0x3f3f3f3f;

int main() {
	int n = read(), vis[n + 1][n + 1];
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x = read();
			vis[i][j] |= x;
			vis[j][i] |= x;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) ans += vis[i][j];
	}
	printf("%d", std::min(n, ans));
	return 0;
}