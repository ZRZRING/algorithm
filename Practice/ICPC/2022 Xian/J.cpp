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
		std::vector<int> a(2 * n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		int max = 0, ans = 0;
		for (int i = 1; i <= n; i++) {
			max = std::max(max, a[i / 2]);
			ans = std::max(ans, max + a[i]);
		}
		std::cout << ans << '\n';
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