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
		int q, n, m;
		std::cin >> q >> n >> m;
		std::vector<int> a(q + 1);
		for (int i = 1; i <= q; i++) {
			std::cin >> a[i];
		}
		std::vector b(n + 1, std::vector<int>(m + 1));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				std::cin >> b[i][j];
			}
		}
		std::vector f(n + 1, std::vector(m + 1, std::vector<int>(10)));
	}
};

int main() {
	Fast_IOS;
	WORK work;
	int T = 1;
	// std::cin >> T;
	while (T--) {
		work.solve();
	}
	return 0;
}