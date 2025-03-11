#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

int main() {
	int n;
	while (std::cin >> n) {
		if (n == 0) break;
		std::vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		int root = 0;
		std::vector<int> ls(n + 1), rs(n + 1);
		std::stack<int> stk;
		stk.push(0);
		for (int i = 1; i <= n; i++) {
			int j = 0;
			while (a[i] < a[stk.top()]) {
				j = stk.top();
				stk.pop();
			}
			rs[stk.top()] = i;
			ls[i] = j;
			stk.push(i);
		}
		while (stk.size() > 2) {
			stk.pop();
		}
		root = stk.top();
		// std::cout << root << '\n';
		// for (int i = 1; i <= n; i++) {
		// 	std::cout << ls[i] << ' ' << rs[i] << '\n';
		// }
		std::vector<int> size(n + 1);
		int64 ans = 0;
		auto dfs = [&](auto self, int u) -> void {
			// std::cout << u << '\n';
			if (ls[u]) self(self, ls[u]);
			if (rs[u]) self(self, rs[u]);
			size[u] = size[ls[u]] + size[rs[u]] + 1;
			ans = std::max(ans, 1ll * a[u] * size[u]);
		};
		dfs(dfs, root);
		std::cout << ans << '\n';
	}
	return 0;
}