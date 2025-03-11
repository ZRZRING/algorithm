#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'

int main() {
	int n, root;
	std::cin >> n;
	std::vector<int> d(n + 1);
	std::vector<std::vector<int>> e(n + 1);
	for (int v = 1; v <= n; v++) {
		int u;
		std::cin >> u;
		e[u].push_back(v);
		d[u]++;
	}
	int flag = 0, D = 0;
	for (int i = 1; i <= n; i++) {
		if (!e[i].empty()) {
			std::sort(e[i].begin(), e[i].end());
		}
		if (!d[i]) continue;
		if (!D) D = d[i];
		else if (d[i] != D) flag = 1;
		D = std::max(D, d[i]);
	}
	std::cout << D << ' ' << (flag ? "no" : "yes") << endl;
	std::vector<int> ans;
	auto dfs = [&](auto self, int u) -> void {
		ans.push_back(u);
		for (auto v : e[u]) {
			self(self, v);
		}
	};
	dfs(dfs, 0);
	for (int i = 1; i <= n; i++) {
		std::cout << ans[i] << " \n"[i == n];
	}
}
