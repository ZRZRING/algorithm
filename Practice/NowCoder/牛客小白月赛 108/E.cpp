#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS \
	std::ios::sync_with_stdio(false), \
	std::cin.tie(0), \
	std::cout.tie(0)

const int64 mod = 998244353;

int N, T = 1;

void init() {
	Fast_IOS;
	std::cin >> T;
}

void solve() {
	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;
	s = " " + s;
	std::vector e(n + 1, std::vector(0, int()));
	for (int i = 2; i <= n; i++) {
		int u, v;
		std::cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	std::vector<int> size(n + 1);
	auto dfs = [&](auto self, int u, int last) -> void {
		size[u] += (s[u] == 'R' ? 1 : -1);
		for (auto v : e[u]) {
			if (v == last) continue;
			self(self, v, u);
			size[u] += size[v];
		}
	};
	dfs(dfs, 1, 1);
	std::vector<int> ans(n + 1);
	auto dfs1 = [&](auto self, int u, int last, int R, int B, int dep) -> void {
		if (size[u] == 0) {
			R--;
			B--;
		}
		if (size[u] > 0) {
			if (size[u] >= 2) R++;
			B--;
		}
		if (size[u] < 0) {
			R--;
			if (size[u] <= -2) B++;
		}
		// std::cout << u << ' ' << size[u] << ' ' << R << ' ' << B << '\n';
		if (s[u] == 'R') {
			ans[u] = (R > 0);
		} else {
			ans[u] = (B > 0);
		}
		for (auto v : e[u]) {
			if (v == last) continue;
			self(self, v, u, R, B, dep + 1);
		}
	};
	dfs1(dfs1, 1, 1, 0, 0, 1);
	for (int i = 1; i <= n; i++) {
		std::cout << ans[i];
	}
	std::cout << '\n';
}

int main() {
	init();
	while (T--) {
		solve();
	}
	return 0;
}