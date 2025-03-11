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
	std::vector<int> cnt(n + 1, 1);
	std::vector<bool> vis(n + 1, 0);
	vis[1] = 1;
	for (int i = 1; i <= m; i++) {
		int x = read(), y = read();
		cnt[x]--; cnt[y]++;
		if (vis[x]) vis[y] = 1; if (!cnt[x]) vis[x] = 0;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) ans += vis[i];
	printf("%d", ans);
	return 0;
}