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
		int n, m;
		std::cin >> n >> m;
		std::vector<int64> vis(m + 1);
		for (int i = 1; i <= n; i++) {
			int x;
			std::cin >> x;
			vis[x] += 1ll * i;
		}
		for (int i = 1; i <= m; i++) {
			std::cout << vis[i] << " \n"[i == m];
		}
	}
};

int main() {
	Fast_IOS;
	WORK work;
	int T = 1;
	std::cin >> T;
	while (T--) {
		work.solve();
	}
	return 0;
}