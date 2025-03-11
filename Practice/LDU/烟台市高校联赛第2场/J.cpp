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
		std::vector<int> a(n + 1), b(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			std::cin >> b[i];
		}
		std::sort(a.begin() + 1, a.end());
		std::sort(b.begin() + 1, b.end());
		for (int i = 1; n - k + i <= n; i++) {
			if (a[n - k + i] <= b[i]) {
				std::cout << "NO\n";
				return;
			}
		}
		for (int i = 1; k + i <= n; i++) {
			if (a[i] > b[k + i]) {
				std::cout << "NO\n";
				return;
			}
		}
		std::cout << "YES\n";
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