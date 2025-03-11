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
	std::string a, b;
	std::cin >> a >> b;
	if (a == std::string(n, '.')) {
		std::cout << "Yes\n";
		std::cout << a << '\n';
		std::string c;
		for (int i = 0; i < n; i++) {
			c.push_back(b[i] == '#' ? '.' : '#');
		}
		for (int i = 1; i < 6; i++) {
			std::cout << c << '\n';
		}
		std::cout << b << '\n';
		return;
	}
	if (b == std::string(n, '.')) {
		std::cout << "Yes\n";
		std::cout << a << '\n';
		std::string c;
		for (int i = 0; i < n; i++) {
			c.push_back(a[i] == '#' ? '.' : '#');
		}
		for (int i = 1; i < 6; i++) {
			std::cout << c << '\n';
		}
		std::cout << b << '\n';
		return;
	}
	if (a == std::string(n, '#') && b == std::string(n, '#')) {
		std::cout << "Yes\n";
		for (int i = 0; i < 7; i++) {
			std::cout << a << '\n';
		}
		return;
	}
	if (a == std::string(n, '#') || b == std::string(n, '#')) {
		std::cout << "No\n";
		return;
	}
	std::cout << "Yes\n";
	std::vector ans(7, std::vector(n, 0));
	for (int i = 0; i < n; i++) {
		ans[0][i] = (a[i] == '#');
		ans[6][i] = (b[i] == '#');
		ans[1][i] = ans[0][i] ^ 1;
		ans[5][i] = ans[6][i] ^ 1;
	}
	int l = 0, r = 0;
	for (int i = 0; i < n; i++) {
		if (!ans[1][i] && (i + 1 < n && ans[1][i + 1] || i - 1 >= 0 && ans[1][i - 1])) {
			l = i;
			ans[2][i] = 1;
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		if (!ans[5][i] && (i + 1 < n && ans[5][i + 1] || i - 1 >= 0 && ans[5][i - 1])) {
			r = i;
			ans[4][i] = 1;
			break;
		}
	}
	int pos = 0;
	if (l > r) std::swap(l, r);
	if (r - l <= 1) {
		ans[3][l] = 1;
	} else {
		for (int i = l + 1; i <= r - 1; i++) {
			ans[3][i] = 1;
		}
	}
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << (ans[i][j] ? '#' : '.');
		}
		std::cout << '\n';
	}
}

int main() {
	init();
	while (T--) {
		solve();
	}
	return 0;
}