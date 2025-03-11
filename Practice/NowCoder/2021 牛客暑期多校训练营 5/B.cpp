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
		double c;
		std::cin >> c;
		std::vector<double> a(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		std::sort(a.begin() + 1, a.end());
		for (int i = 1; i <= n; i++) {
			a[i] += a[i - 1];
		}
		double ans = c;
		for (int i = 1; i <= n - 1; i++) {
			ans += std::pow(0.5, n - i) * a[i];
		}
		std::cout << std::fixed << std::setprecision(6);
		std::cout << std::min(a[n], ans) << '\n';
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