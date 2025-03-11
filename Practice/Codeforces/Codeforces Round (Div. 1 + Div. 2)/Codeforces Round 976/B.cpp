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
		int64 n;
		std::cin >> n;
		int64 l = 0, r = 2e18;
		while (l < r) {
			int64 x = l + r >> 1;
			// std::cout << x << ' ' << (int)sqrtl(x) << '\n';
			if (x - (int64)sqrtl(x) >= n) {
				r = x;
			} else {
				l = x + 1;
			}
		}
		std::cout << r << '\n';
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