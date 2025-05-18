#include <bits/stdc++.h>

using A3 = std::array<int, 3>;

int main() {
	int n, m, k;
	std::cin >> n >> m >> k;
	std::vector a(n + 1, std::vector(m + 1, int()));
	std::vector<int> vx(n + 1), vy(m + 1);
	std::priority_queue<A3> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cin >> a[i][j];
			q.push({a[i][j], i, j});
		}
	}
	while (k) {
		auto [p, x, y] = q.top();
		q.pop();
		if (vx[x] == 1 || vy[y] == 1) {
			continue;
		}
		vx[x] = 1;
		vy[y] = 1;
		k--;
	}
	for (int i = 1; i <= n; i++) {
		std::vector<int> ans;
		for (int j = 1; j <= m; j++) {
			if (vx[i] || vy[j]) {
				continue;
			}
			ans.push_back(a[i][j]);
		}
		for (int j = 0; j < ans.size(); j++) {
			std::cout << ans[j] << " \n"[j == ans.size() - 1];
		}
	}
}
