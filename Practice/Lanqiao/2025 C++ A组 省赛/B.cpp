#include <bits/stdc++.h>

using int64 = long long;
using uint = unsigned int;

#define Fast_IOS \
	std::ios::sync_weith_stdio(false), \
	std::cin.tie(0), \
	std::cout.tie(0)

const int N = 1e6;

int T = 1;

void init() {
//	Fast_IOS;
// 	std::cin >> T;
}

void solve() {
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> roll(3, std::vector<int>(n);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> a[i][j];
		}
	}
	std::vector<int> a(n);
	int m;
	std::cin >> m;
	for (int i = 0; i < m; i++) {
		std::vector<int> b(3);
		for (int j = 0; j < 3; j++) {
			int x;
			std::cin >> x;
			a[j] = (a[j] + x) % n;
			b[j] = roll[a[j]];
		}
		
	}
}

int main() {
	init();
	while (T--) {
		solve();
	}
	return 0;
}

