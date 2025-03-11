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
		std::cin >> T;
	}

	void solve() {
		int n;
		std::cin >> n;
		std::vector<int64> a(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		if (n == 1) {
			std::cout << 1 << '\n';
			return;
		}
		auto check = [a, n](int64 x) -> bool {
			int l = n, r = 1;
			for (int i = 2; i <= n; i += 2) {
				if (a[i] - a[i - 1] > x) {
					l = i - 1;
					break;
				}
			}
			for (int i = n - 1; i >= 1; i -= 2) {
				if (a[i + 1] - a[i] > x) {
					r = i + 1;
					break;
				}
			}
			return r - l <= 0;
		};
		int64 l = 0, r = 1e18;
		while (l < r) {
			int64 mid = l + r >> 1;
			if (check(mid)) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		std::cout << r << '\n';
	}
};

int main() {
	ICPC icpc;
	while (icpc.T--) {
		icpc.solve();
	}
	return 0;
}