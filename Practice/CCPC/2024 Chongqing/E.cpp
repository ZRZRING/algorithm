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
	// Fast_IOS;
	// std::cin >> T;
}

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector e(n + 1, std::vector<int>());
	std::vector<int> d(n + 1), a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		int u, v;
		std::cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
		d[u]++;
		d[v]++;
	}
	int max_leaf = 0, max2_leaf = 0, max = 0;
	for (int i = 1; i <= n; i++) {
		if (d[i] == 1) {
			if (a[i] >= max_leaf) {
				max2_leaf = max_leaf;
				max_leaf = a[i];
			} else if (a[i] >= max2_leaf) {
				max2_leaf = a[i];
			}
		} else {
			max = std::max(max, a[i]);
		}
	}
	std::cout << std::max(max, std::min(max_leaf, max2_leaf)) << '\n';
}

int main() {
	init();
	while (T--) {
		solve();
	}
	return 0;
}