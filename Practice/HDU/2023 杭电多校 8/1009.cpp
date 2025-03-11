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
		std::vector<std::vector<int> > a(n + 1, std::vector<int>(n + 1, 0));
		std::vector<std::vector<int> > ans(n + 1, std::vector<int>(n + 1, 1));
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) a[i][j] = read();
		for (int x = 1; x <= n; x++) {
			for (int y = 1; y <= n; y++) {
				int s = std::min(ans[x - 1][y], ans[x][y - 1]) - 1;
				while (x + s - 1 < n && y + s - 1 < n) {
					
				}
			}
		}
	}
	return 0;
}