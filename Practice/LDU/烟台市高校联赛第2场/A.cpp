#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

const int64 mod = 1e9 + 7;

#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

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

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int n;
		std::cin >> n;
		std::vector<int> a(10);
		for (int i = 0; i < 10; i++) {
			std::cin >> a[i];
		}
		std::vector f(n + 1, std::vector(10, std::vector(16, int64())));
		for (int i = 0; i < 10; i++) {
			if (a[i] == 0) continue;
			f[1][i][1] = 1;
		}
		for (int i = 2; i <= n; i++) {
			for (int j = 0; j < 10; j++) {
				int64 sum = 0;
				for (int j2 = 0; j2 < 10; j2++) {
					if (j2 == j) continue;
					for (int k2 = 1; k2 <= a[j2]; k2++) {
						QMOD(sum += f[i - 1][j2][k2]);
					}
				}
				f[i][j][1] = sum;
				for (int k = 2; k <= a[j]; k++) {
					f[i][j][k] = f[i - 1][j][k - 1];
				}
			}
		}
		int64 ans = 0;
		for (int i = 0; i < 10; i++) {
			for (int j = 1; j <= a[i]; j++) {
				QMOD(ans += f[n][i][j]);
			}
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