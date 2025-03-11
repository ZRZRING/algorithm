#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS \
	std::ios::sync_with_stdio(false), \
	std::cin.tie(0), \
	std::cout.tie(0)

const int64 mod = 998244353;

class ICPC {
public:
	int N, T = 1;

	ICPC() {
		Fast_IOS;
		// std::cin >> T;
	}

	void solve() {
		int n;
		std::cin >> n;
		std::vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		std::set<int> s;
		for (int i = 2; i <= n; i++) {
			int x = a[i - 1], y = a[i];
			std::vector a(3, std::vector<int>());
			for (int j = 0; j < 30; j++) {
				if ((x >> j & 1) == 0 && (y >> j & 1) == 1) {
					a[0].push_back(j);
				}
				if ((x >> j & 1) == 1 && (y >> j & 1) == 0) {
					a[1].push_back(j);
				}
				if ((x >> j & 1) == 1 && (y >> j & 1) == 1) {
					a[2].push_back(j);
				}
			}
			// for (auto x : a[0]) std::cout << x << ' '; std::cout << '\n';
			// for (auto x : a[1]) std::cout << x << ' '; std::cout << '\n';
			// for (auto x : a[2]) std::cout << x << ' '; std::cout << '\n';
			for (int p0 = 0; p0 < 2; p0++) {
				int t = 0;
				for (auto z : a[0]) {
					t |= (p0 << z);
				}
				for (int p1 = 0; p1 < 2; p1++) {
					for (auto z : a[1]) {
						t |= (p1 << z);
					}
					for (int p2 = 0; p2 < 2; p2++) {
						for (auto z : a[2]) {
							t |= (p2 << z);
						}
						// std::cout << p0 << ' ' << p1 << ' ' << p2 << '\n';
						s.insert(t);
					}
				}
			}
		}
		// for (auto x : s) {
		// 	std::cout << x << '\n';
		// }
		std::cout << s.size() << '\n';
	}
};

int main() {
	ICPC icpc;
	while (icpc.T--) {
		icpc.solve();
	}
	return 0;
}