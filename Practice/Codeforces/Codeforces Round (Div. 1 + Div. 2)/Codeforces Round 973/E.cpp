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
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		std::sort(a.begin() + 1, a.end(), std::greater<int>());
		int x = a[n];
		a.pop_back();
		int64 ans = x;
		for (int i = n - 1; i >= 1; i--) {
			std::sort(a.begin() + 1, a.end(), [x](int a, int b) {
				return std::__gcd(a, x) > std::__gcd(b, x);
			});
			// for (int j = 1; j <= i; j++) {
			// 	std::cout << a[j] << " \n"[j == i];
			// }
			if (std::__gcd(x, a[i]) == x) {
				x = std::__gcd(x, a[i]);
				ans += 1ll * x * i;
				break;
			} else {
				x = std::__gcd(x, a[i]);
				ans += x;
			}
			a.pop_back();
		}
		std::cout << ans << '\n';
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