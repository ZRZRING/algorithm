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
		std::vector cnt(4, int(0));
		for (int i = 1; i <= n; i++) {
			int x;
			std::cin >> x;
			cnt[x]++;
		}
		std::vector f(n + 1, std::vector(n + 1, std::vector(n + 1, double(0))));
		auto dfs = [&](auto self, int x, int y, int z) -> double {
			// std::cout << x << ' ' << y << ' ' << z << '\n';
			if (x == 0 && y == 0 && z == 0) {
				return 0;
			}
			if (f[x][y][z]) return f[x][y][z];
			int tot = x + y + z;
			f[x][y][z] = 1.0 * n / tot;
			double &res = f[x][y][z];
			if (x) res += self(self, x - 1, y, z) * x / tot;
			if (y) res += self(self, x + 1, y - 1, z) * y / tot;
			if (z) res += self(self, x, y + 1, z - 1) * z / tot;
			return res;
		};
		std::cout << std::fixed << std::setprecision(10);
		std::cout << dfs(dfs, cnt[1], cnt[2], cnt[3]) << '\n';
	}
};

int main() {
	// Fast_IOS;
	WORK work;
	int T = 1;
	// std::cin >> T;
	while (T--) {
		work.solve();
	}
	return 0;
}