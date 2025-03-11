#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS \
	std::ios::sync_with_stdio(false), \
	std::cin.tie(0), \
	std::cout.tie(0)

const int64 mod = 998244353;

int N, T = 1;

void init() {
	// Fast_IOS;
	// std::cin >> T;
}

void solve() {
	int n, sum = 0;
	std::cin >> n;
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		sum += a[i];
	}
	std::vector f(n + 1, std::vector(sum + 1, int(0)));
	f[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = sum; j >= a[i]; j--) {
			for (int k = n; k >= 1; k--) {
				f[k][j] = (f[k][j] | f[k - 1][j - a[i]]);
			}
		}
	}
	int ans = sum;
	for (int i = 0; i <= sum; i++) {
		int t = abs(i - (sum - i));
		if (f[n / 2][i]) ans = std::min(ans, t);
		if (n % 2 == 1 && f[(n + 1) / 2][i]) ans = std::min(ans, t);
	}
	std::cout << (sum - ans) / 2 << ' ' << (sum + ans) / 2 << '\n';
}

int main() {
	init();
	while (T--) {
		solve();
	}
	return 0;
}