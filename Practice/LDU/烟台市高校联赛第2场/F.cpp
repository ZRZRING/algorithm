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
		int64 n, a, b, c;
		std::cin >> n >> a >> b >> c;
		if (n % 4 == 0) {
			std::cout << 0 << '\n';
		}
		if (n % 4 == 1) {
			std::cout << std::min({c, a + b, 3 * a}) << '\n';
		}
		if (n % 4 == 2) {
			std::cout << std::min({b, 2 * a, 2 * c}) << '\n';
		}
		if (n % 4 == 3) {
			std::cout << std::min({a, b + c, 3 * c}) << '\n';
		}
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