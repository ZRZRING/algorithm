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
		int n, m, k;
		std::cin >> n >> m >> k;
		if (n == 1 || m == 1) {
			std::cout << "NO" << '\n';
			return;
		}
		std::cout << (k >= n - (n + m - 1) / m ? "NO" : "YES") << '\n';
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