#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

template <class T>
T MOD(T& x, int64 p = mod) {
	return x = (x % p + p) % p;
}
template <class T>
T MOD(T&& x, int64 p = mod) {
	return x = (x % p + p) % p;
}
template <class T>
T QMOD(T& x, int64 p = mod) {
	while (x < 0) x += p;
	while (x >= p) x -= p;
	return x;
}
template <class T>
T QMOD(T&& x, int64 p = mod) {
	while (x < 0) x += p;
	while (x >= p) x -= p;
	return x;
}

// f[i] 表示 Alice 全赢 Bob 后剩 i 张牌

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int n, m;
		std::cin >> n >> m;
		std::vector<int64> f(m + 1);
		f[0] = 1;
		for (int i = 1; i <= m; i++) {
			std::vector<int64> _f(m + 1);
			for (int j = 0; j <= i; j++) {
				if (j + 1 <= m) QMOD(_f[j] += f[j + 1]);
				if (j - 1 >= 0) QMOD(_f[j] += f[j - 1]);
			}
			f.swap(_f);
		}
		std::vector<int64> g(m + 1);
		g[0] = 1;
		for (int i = 2; i <= n; i++) {
			std::vector<int64> _g(m + 1);
			for (int j = 0; j <= m; j++) {
				for (int k = 0; j + k <= m; k++) {
					QMOD(_g[j + k] += g[j] * f[k] % mod);
				}
			}
			g.swap(_g);
		}
		int64 ans = 0;
		for (int i = 0; i <= m; i++) {
			QMOD(ans += f[i] * g[i] % mod);
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