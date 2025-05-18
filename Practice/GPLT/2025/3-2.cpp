#include <bits/stdc++.h>

using int64 = long long;

int main() {
	int n, m;
	std::cin >> n >> m;
	std::vector a(n + 1, std::vector(m + 1, int64()));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cin >> a[i][j];
		}
	}
	std::vector ans(n + 1, std::vector(m + 1, int64()));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int x = 1; x <= n; x++) {
				for (int y = 1; y <= m; y++) {
					ans[i][j] += 1ll * std::max(abs(i - x), abs(j - y)) * a[i][j];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cout << ans[i][j] << " \n"[j == m];
		}
	}
}
