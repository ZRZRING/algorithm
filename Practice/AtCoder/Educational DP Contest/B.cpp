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
		int n, k;
		std::cin >> n >> k;
		std::vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		std::vector<int64> f(n + 1, 1e15);
		f[1] = 0;
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= k && i - j >= 1; j++) {
				f[i] = std::min(f[i], f[i - j] + abs(a[i] - a[i - j]));
			}
		}
		std::cout << f[n] << '\n';
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