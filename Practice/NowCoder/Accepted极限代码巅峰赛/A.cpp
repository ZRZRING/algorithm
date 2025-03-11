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
	Fast_IOS;
	std::cin >> T;
}

void solve() {
	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;
	std::reverse(s.begin(), s.end());
	s = " " + s;
	std::vector f(n, std::vector(2, int()));
	f[0][0] = 0;
	f[0][1] = 1;
	for (int i = 1; i < n; i++) {
		f[i][0] = std::max(f[i - 1][0], f[i - 1][1]);
		if (s[i] == '1') {
			f[i][1] = f[i - 1][0] + 1;
		} else {
			f[i][1] = f[i - 1][1] + 1;
		}
	}
	std::cout << n - std::max(f[n - 1][0], f[n - 1][1]) << '\n';
}

int main() {
	init();
	while (T--) {
		solve();
	}
	return 0;
}