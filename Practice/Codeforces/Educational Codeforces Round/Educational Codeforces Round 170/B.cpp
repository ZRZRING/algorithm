#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 1e9 + 7;

class WORK {
public:
	int N;

	WORK() {}

	int64 qpow(int64 a, int64 x = mod - 2) {
		a %= mod;
		x %= mod - 1;
		int64 res = 1;
		while (x) {
			if (x & 1) res = res * a % mod;
			a = a * a % mod;
			x >>= 1;
		}
		return res;
	}

	void solve() {
		int n;
		std::cin >> n;
		for (int i = 1; i <= n; i++) {
			int x;
			std::cin >> x;
		}
		for (int i = 1; i <= n; i++) {
			int x;
			std::cin >> x;
			std::cout << qpow(2, x) << '\n';
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