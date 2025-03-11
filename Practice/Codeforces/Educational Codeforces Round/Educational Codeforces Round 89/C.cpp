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
	int T = read();
	while (T--) {
		int n = read(), m = read();
		std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				a[i][j] = read();
			}
		}
		int ans = 0;
		for (int s = 2; s <= n + m; s++) {
			if ((n + m) % 2 == 0 && s == (n + m) / 2 + 1) continue;
			int cnt[2] = {0}, i = s;
			for (int j = 1; j <= i - 1; j++) {
				if (i - j > n || j > m) continue;
				printf("%d %d\n", i - j, j);
				cnt[a[i - j][j]]++;
			}
			i = n + m - s + 2;
			for (int j = 1; j <= i - 1; j++) {
				if (i - j > n || j > m) continue;
				printf("%d %d\n", i - j, j);
				cnt[a[i - j][j]]++;
			}
			ans += std::min(cnt[0], cnt[1]);
		}
		printf("%d\n", ans / 2);
	}
	return 0;
}