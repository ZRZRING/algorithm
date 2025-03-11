#include <bits/stdc++.h>

using int64 = long long;

int main() {
	int n;
	std::cin >> n;
	std::vector<int64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	std::vector b(n + 1, std::vector<int64>(n + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			std::cin >> b[i][j];
		}
	}
	int64 ans = 0;
	std::vector<int64> f(1 << n);
	int cnt = 0;
	for (int S = 0; S < 1 << n; S++) {
		if (__builtin_popcount(S) % 3 != 0) continue;
		for (int i = 1; i <= n; i++) {
			if ((S >> i & 1) == 0) continue;
			for (int j = i + 1; j <= n; j++) {
				if ((S >> j & 1) == 0) continue;
				for (int k = j + 1; k <= n; k++) {
					if ((S >> k & 1) == 0) continue;
					// cnt++;
					int T = S ^ 1 << i ^ 1 << j ^ 1 << k;
					// std::cout << T << '\n';
					f[S] = std::max(f[S], f[T] + std::max({
						a[i], a[j], a[k], b[i][j], b[i][k], b[j][k], b[i][j] * b[i][k] * b[j][k]
					}));
				}
			}
		}
	}
	// std::cout << cnt << '\n';
	std::cout << f[(1 << n) - 1] << '\n';
}