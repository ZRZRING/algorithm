#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int n;
		std::cin >> n;
		std::vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		std::vector<int> ls(n + 1), rs(n + 1);
		std::stack<int> stk;
		stk.push(0);
		for (int i = 1; i <= n; i++) {
			int j = 0;
			while (a[i] < a[stk.top()]) {
				j = stk.top();
				stk.pop();
			}
			ls[i] = j;
			rs[stk.top()] = i;
			stk.push(i);
		}
		// for (int i = 1; i <= n; i++) {
		// 	std::cout << ls[i] << ' ' << rs[i] << '\n';
		// }
		int root = 0;
		while (stk.size() >= 2) {
			root = stk.top();
			stk.pop();
		}
		int64 sum = 0;
		std::vector<int> size(n + 1);
		auto dfs1 = [&](auto self, int u) -> void {
			if (!u) return;
			self(self, ls[u]);
			self(self, rs[u]);
			size[u] = size[ls[u]] + size[rs[u]] + 1;
			sum += 1ll * a[u] * (size[ls[u]] + 1) * (size[rs[u]] + 1);
		};
		dfs1(dfs1, root);
		// std::cout << sum << '\n';
		std::vector<int64> ans(n + 1, sum);
		auto dfs2 = [&](auto self, int u, int64 delta) -> void {
			if (!u) return;
			self(self, ls[u], delta + 1ll * a[u] * (size[rs[u]] + 1));
			self(self, rs[u], delta + 1ll * a[u] * (size[ls[u]] + 1));
			int lt = ls[u], rt = rs[u];
			ans[u] -= 1ll * a[u] * (size[ls[u]] + 1) * (size[rs[u]] + 1) + delta;
			auto golt = [&]() -> void {
				ans[u] += 1ll * a[lt] * (size[ls[lt]] + 1) * size[rt];
				lt = rs[lt];
			};
			auto gort = [&]() -> void {
				ans[u] += 1ll * a[rt] * (size[rs[rt]] + 1) * size[lt];
				rt = ls[rt];
			};
			while (lt || rt) {
				if (!rt) {
					golt();
					continue;
				}
				if (!lt) {
					gort();
					continue;
				}
				if (a[lt] < a[rt]) {
					golt();
				} else {
					gort();
				}
			}
		};
		dfs2(dfs2, root, 0);
		for (int i = 1; i <= n; i++) {
			std::cout << ans[i] << " \n"[i == n];
		}
	}
};

int main() {
	// Fast_IOS;
	WORK work;
	int T = 1;
	std::cin >> T;
	while (T--) {
		work.solve();
	}
	return 0;
}