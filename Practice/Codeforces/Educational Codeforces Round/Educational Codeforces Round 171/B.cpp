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
		if (n % 2 == 0) {
			int64 ans = 0;
			for (int i = 2; i <= n; i += 2) {
				ans = std::max(ans, a[i] - a[i - 1]);
			}
			std::cout << ans << '\n';
		} else {
			std::vector<int64> pre(n + 2), suf(n + 2);
			for (int i = 2; i <= n; i += 2) {
				pre[i] = std::max(pre[i - 2], a[i] - a[i - 1]);
			}
			for (int i = n - 1; i >= 1; i -= 2) {
				suf[i] = std::max(suf[i + 2], a[i + 1] - a[i]);
			}
			int64 ans = 1e9;
			for (int i = 1; i <= n; i += 2) {
				ans = std::min(ans, std::max({1ll, pre[i - 1], suf[i + 1]}));
			}
			std::cout << ans << '\n';
		}
	}
};

int main() {
	ICPC icpc;
	while (icpc.T--) {
		icpc.solve();
	}
	return 0;
}