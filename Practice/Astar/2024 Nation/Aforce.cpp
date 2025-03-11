#include <bits/stdc++.h>

using int64 = long long;

int main() {
	int n;
	std::cin >> n;
	std::vector<int64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	std::vector b(n + 1, std::vector<int64>(n + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			std::cin >> b[i][j];
		}
	}
	int64 ans = 0;
	std::vector<int> vis(n + 1);
	auto dfs = [&](auto self, int x, int64 score) -> void {
		if (x == n / 3 + 1) {
			ans = std::max(ans, score);
			return;
		}
		for (int i = 1; i <= n; i++) {
			if (vis[i]) continue;
			vis[i] = 1;
			for (int j = 1; j <= n; j++) {
				if (vis[j]) continue;
				vis[j] = 1;
				for (int k = 1; k <= n; k++) {
					if (vis[k]) continue;
					vis[k] = 1;
					int64 t = std::max({a[i], a[j], a[k], b[i][j], b[i][k], b[j][k], b[i][j] * b[i][k] * b[j][k]});
					self(self, x + 1, score + t);
					vis[k] = 0;
				}
				vis[j] = 0;
			}
			vis[i] = 0;
		}
	};
	dfs(dfs, 1, 0);
	std::cout << ans << '\n';
}