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
		int n, m, Q;
		std::cin >> n >> m >> Q;
		std::vector<int> a(m);
		for (int i = 0; i < m; i++) {
			std::cin >> a[i];
		}
		std::sort(a.begin(), a.end());
		while (Q--) {
			int x;
			std::cin >> x;
			if (m == 1) {
				if (x == a[0]) {
					std::cout << 0 << '\n';
				} else if (x < a[0]) {
					std::cout << a[0] - 1 << '\n';
				} else {
					std::cout << n - a[0] << '\n';
				}
			} else {
				int pos = std::lower_bound(a.begin(), a.end(), x) - a.begin();
				if (pos == 0) {
					std::cout << a[0] - 1 << '\n';
				} else if (pos == m) {
					std::cout << n - a[m - 1] << '\n';
				} else {
					std::cout << (a[pos] - a[pos - 1]) / 2 << '\n';
				}
			}
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