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
		int n, W;
		std::cin >> n >> W;
		std::vector<int> a(13);
		for (int i = 1; i <= n; i++) {
			int x;
			std::cin >> x;
			a[x - 1]++;
		}
		std::vector<int> f(1 << 13, 1e9);
		f[0] = 0;
		for (int S = 1; S < 1 << 13; S++) {
			for (int T = S; T; T = S & T - 1) {
				// std::cout << S << ' ' << T << '\n';
				int cnt = 0;
				for (int i = 0; i < 13; i++) {
					if ((T >> i & 1) == 1) cnt += a[i];
				}
				if (cnt > W) continue;
				f[S] = std::min(f[S], f[S ^ T] + 1);
			}
		}
		std::cout << f[(1 << 13) - 1] << '\n';
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