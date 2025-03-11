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
		for (int i = 1; i + 1 <= n; i += 2) {
			std::cout << "? " << i << ' ' << i + 1 << std::endl;
			int t;
			std::cin >> t;
			if (t == 1) {
				int x = 1, y = 2;
				if (i == 1) x = 3, y = 4;
				std::cout << "? " << x << ' ' << i << std::endl;
				std::cin >> t;
				if (t == 0) {
					std::cout << "? " << x << ' ' << i + 1 << std::endl;
					std::cin >> t;
					if (t == 0) {
						std::cout << "! 1" << std::endl;
					} else {
						std::cout << "? " << y << ' ' << i + 1 << std::endl;
						std::cin >> t;
						if (t == 0) {
							std::cout << "! 1" << std::endl;
						} else {
							std::cout << "! 2" << std::endl;
						}
					}
				} else {
					std::cout << "? " << y << ' ' << i << std::endl;
					std::cin >> t;
					if (t == 1) {
						std::cout << "! 2" << std::endl;
					} else {
						std::cout << "! 1" << std::endl;
					}
				}
				return;
			}
		}
		if (n % 2 == 1) {
			std::cout << "? " << n << ' ' << 1 << std::endl;
			int t;
			std::cin >> t;
			if (t == 1) {
				int x = 2, y = 3;
				std::cout << "? " << x << ' ' << 1 << std::endl;
				std::cin >> t;
				if (t == 0) {
					std::cout << "? " << x << ' ' << n << std::endl;
					std::cin >> t;
					if (t == 0) {
						std::cout << "! 1" << std::endl;
					} else {
						std::cout << "? " << y << ' ' << n << std::endl;
						std::cin >> t;
						if (t == 0) {
							std::cout << "! 1" << std::endl;
						} else {
							std::cout << "! 2" << std::endl;
						}
					}
				} else {
					std::cout << "? " << y << ' ' << 1 << std::endl;
					std::cin >> t;
					if (t == 1) {
						std::cout << "! 2" << std::endl;
					} else {
						std::cout << "! 1" << std::endl;
					}
				}
				return;
			}
		}
		std::cout << "! 1" << std::endl;
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