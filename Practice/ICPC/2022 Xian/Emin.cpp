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
		int64 L, R;
		std::cin >> L >> R;
		int64 ans = 0;
		while (L) {
			if (R - L >= 3) {
				while (R % 3 != 0) R--;
				R /= 3;
				while (L % 3 != 0) L++;
				L /= 3;
				ans++;
			} else {
				if (R % 3 != 0 && L % 3 != 0) ans++;
				R /= 3;
				L /= 3;
				ans++;
			}
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