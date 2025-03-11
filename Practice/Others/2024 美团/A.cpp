#include <bits/stdc++.h>

using int64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;
	std::vector e(n + 1, std::vector<int>());
	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	std::vector<int> size(n + 1);
	std::vector f(n + 1, std::vector<int>());
	auto dfs = [&](auto self, int x, int u, int last) -> void {
		size[u] = 1;
		for (auto v : e[u]) {
			if (v == last) continue;
			self(self, x, v, u);
			size[u] += size[v];
			for (int i = std::min(x, size[u]); i >= 0; i--) {
				for (int j = 0; j <= i; j++) {
					f[u][i] = std::max(f[u][i], f[u][i - j] + f[v][j]);
				}
			}
		}
	};
	auto check = [&](int x) -> int {
		f.clear();
		f.resize(n + 1);
		for (auto ff : f) {
			ff.resize(n + 1);
		}
		dfs(dfs, x, 1, 1);
		if (f[1][n] < k) return 0;
	};
	if (check(n) == 0) {
		std::cout << "impossible\n";
		return;
	}
	int l = 0, r = n;
	while (l < r) {
		int mid = l + r >> 1;
		std::cout << mid << '\n';
		if (check(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	std::cout << r << '\n';
}

int main() {
	int T = 1;
	std::cin >> T;
	while (T--) solve();
	return 0;
}