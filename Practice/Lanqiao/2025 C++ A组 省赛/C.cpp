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
	std::vector<std::vector<int>> r(3, std::vector<int>(n));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> r[i][j];
		}
	}
	std::vector<int> a(n);
	int m, ans = 0;
	std::cin >> m;
	for (int i = 0; i < m; i++) {
		std::vector<int> b(3);
		for (int j = 0; j < 3; j++) {
			int x;
			std::cin >> x;
			a[j] = (a[j] + x) % n;
			b[j] = r[j][a[j]];
		}
		int score = 0;
		if (b[0] == b[1] && b[0] == b[2]) {
			score = std::max(score, 200);
		}
		if (b[1] == b[0] + 1 && b[2] == b[0] + 2) {
			score = std::max(score, 200);
		}
		std::sort(b.begin(), b.end());
		if (b[0] == b[1] || b[1] == b[2]) {
			score = std::max(score, 100);
		}
		if (b[1] == b[0] + 1 && b[2] == b[0] + 2) {
			score = std::max(score, 100);
		}
		ans += score;
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

