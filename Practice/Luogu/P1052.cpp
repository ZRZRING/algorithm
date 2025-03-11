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
	int L, S, T, n;
	std::cin >> L >> S >> T >> n;
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin() + 1, a.end());
	if (S == T) {
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] % S == 0) {
				ans++;
			}
		}
		std::cout << ans << '\n';
		return;
	}
	std::vector<int> b(n + 1);
	for (int i = 1; i <= n; i++) {
		b[i] = std::min(100, a[i] - a[i - 1]);
	}
	std::vector<int> stone(2e4);
	for (int i = 1; i <= n; i++) {
		a[i] = a[i - 1] + b[i];
		stone[a[i]] = 1;
	}
	L = a[n] + 100;
	std::vector<int> f(L + 11, 1e9);
	f[0] = 0;
	for (int i = 1; i <= L + 10; i++) {
		for (int j = i - T; j <= i - S; j++) {
			if (j < 0) continue;
			// std::cout << j << '\n';
			f[i] = std::min(f[i], f[j] + stone[i]);
		}
	}
	int ans = 1e9;
	for (int i = L; i <= L + 10; i++) {
		ans = std::min(ans, f[i]);
	}
	std::cout << ans << '\n';
}

int main() {
	init();
	while (T--) {
		solve();
	}
	return 0;
}