#include <bits/stdc++.h>

using int64 = long long;

#define A2 std::array<int, 2>

int main() {
	int64 n = 4;
	int64 sum = 0;
	std::vector<int64> a, id(n + 1);
	std::iota(id.begin() + 1, id.end(), 1);
	do {
		int64 x = 0;
		for (int i = 1; i <= n; i++) {
			std::cout << id[i] << ' ';
			x *= 10;
			x += id[i];
		}
		std::cout << x * x << '\n';
		a.push_back(x * x);
		sum += x * x;
	} while (std::next_permutation(id.begin() + 1, id.end()));
	std::vector<int64> vis(a.size());
	auto dfs = [&](auto self, int64 x, int64 t) -> void {
//		std::cout << t << '\n';
		if (t * 2 > sum) return;
		if (t * 2 == sum) {
			int64 cnt = 0;
			for (int i = 0; i < a.size(); i++) {
				cnt += vis[i];
			}
			if (cnt == 12) {
				for (int i = 0; i < a.size(); i++) {
					std::cout << vis[i] << ", ";
				}
				std::cout << '\n';
			}
			return;
		}
		if (x == a.size()) {
			return;
		}
		self(self, x + 1, t);
		vis[x] = 1;
		self(self, x + 1, t + a[x]);
		vis[x] = 0;
	};
	dfs(dfs, 0, 0);
}
