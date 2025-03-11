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
		std::vector<double> a(n + 1);
		double sum = 0;
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
			sum += a[i];
		}
		std::cout << std::fixed << std::setprecision(10);
		std::cout << sum / (n + 1) * 2.0 << ' ';
		for (int i = 2; i <= n; i++) {
			std::cout << sum / (n + 1) << " \n"[i == n];
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