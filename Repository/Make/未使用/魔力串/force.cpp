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

void solve() {
	int n = read(), a[n + 1] = {0}, ans = 0;
	std::function<void(int)> dfs = [&](int x) -> void {
		if (x == n + 1) {
			x = 1;
			for (int i = 1; i <= n; i++) {
				if (a[i] == x) x++;
			}
			if (x != 6) return;
			
			for (int i = 1; i <= n; i++) {
				if (a[i] == 1) {
					x = i;
					while (x + 1 <= n && a[x + 1] - a[x] == 1) x++;
					if (x - i + 1 == 5) {
						// for (int i = 1; i <= n; i++) printf("%d ", a[i]); puts("");
						return;
					}
				}
			}
			ans++; return;
		}
		for (int i = 1; i <= 5; i++) a[x] = i, dfs(x + 1);
	};
	dfs(1);
	printf("%d\n", ans);
}

int main() {
	int T = read();
	while (T--) solve();
	return 0;
}