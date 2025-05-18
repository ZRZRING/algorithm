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
		int max = 0, min = 1e9;
		for (int i = 1; i <= n; i++) {
			int x;
			std::cin >> x;
			max = std::max(max, x);
			min = std::min(min, x);
		}
		std::cout << (n - 1) * (max - min) << '\n';
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