#include <bits/stdc++.h>

using A3 = std::array<int, 3>;

int main() {
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> a(3);
	for (int i = 1; i <= n; i++) {
		int x, y;
		std::cin >> x >> y;
		a[y].push_back(x);
	}
	std::vector<A3> ans;
	std::sort(a[0].begin(), a[0].end());
	a[0].resize(std::unique(a[0].begin(), a[0].end()) - a[0].begin());
	std::sort(a[1].begin(), a[1].end());
	a[1].resize(std::unique(a[1].begin(), a[1].end()) - a[1].begin());
	std::sort(a[2].begin(), a[2].end());
	a[2].resize(std::unique(a[2].begin(), a[2].end()) - a[2].begin());
	auto solve = [&](int o) -> void {
		int s = 0;
		for (int i = 0; i < a[0].size(); i++) {
			int x = a[0][i], t = 0;
			while (s < a[1].size() && a[1][s] <= x) s++;
			for (int j = s; j < a[1].size(); j++) {
				long long y = a[1][j], z = y + y - x;
				while (t < a[2].size() && a[2][t] < z) t++;
				if (t != a[2].size() && z == a[2][t]) {
//					std::cout << x << ' ' << y << ' ' << z << '\n';
					if (o == 1) ans.push_back({x, y, z});
					if (o == -1) ans.push_back({z, y, x});
				}
			}
		}
	};
	solve(1);
	std::swap(a[0], a[2]);
	solve(-1);
	std::sort(ans.begin(), ans.end(), [](A3 a, A3 b) {
		if (a[1] == b[1]) {
			return a[0] < b[0];
		}
		return a[1] < b[1];
	});
	for (auto x : ans) {
		printf("[%d, 0] [%d, 1] [%d, 2]\n", x[0], x[1], x[2]);
	}
	if (ans.empty()) {
		std::cout << -1 << '\n';
	}
}
