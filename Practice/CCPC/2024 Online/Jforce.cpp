#include <bits/stdc++.h>

using int64 = long long;

const int64 mod = 998244353;

void solve() {
	int n;
	std::cin >> n;
	int A = 0, B = 0;
	std::vector<int> a(n + 1), b(n + 1), c(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		A ^= a[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
		B ^= b[i];
	}
	int ans = 2147483647;
	auto dfs = [&](auto self, int x) -> void {
		if (x == n + 1) {
			int A = 0, B = 0;
			for (int i = 1; i <= n; i++) {
				// std::cout << a[i] << ' ' << b[i] << '\n';
				A ^= a[i];
				B ^= b[i];
			}
			// std::cout << '\n';
			ans = std::min(ans, std::max(A, B));
			return;
		}
		self(self, x + 1);
		std::swap(a[x], b[x]);
		self(self, x + 1);
		std::swap(a[x], b[x]);
	};
	dfs(dfs, 1);
	std::cout << ans << '\n';
}

int main() {
	int T = 1;
	std::cin >> T;
	while (T--) {
		solve();
	}
}