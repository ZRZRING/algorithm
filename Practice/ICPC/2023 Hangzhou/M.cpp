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
		std::vector<int> a(n + 1);
		int min = 1;
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
			if (a[i] < a[min]) min = i;
		}
		double ans1 = 0, ans2 = 0, ans3 = 0;
		for (int i = 1; i <= n; i++) {
			ans1 += a[i];
		}
		for (int i = 1; i <= min + 1; i++) {
			ans2 += a[i];
		}
		for (int i = min - 1; i <= n; i++) {
			ans3 += a[i];
		}
		std::cout << std::fixed << std::setprecision(15);
		std::cout << std::max({ans1 / n, ans2 / (min + 1), ans3 / (n - min + 2)}) << '\n';
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