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
	int n, m, k;
	std::cin >> n >> m >> k;
	std::priority_queue<int> q;
	for (int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		q.push(x);
	}
	int64 ans = 0;
	while (!q.empty()) {
		int x = q.top(), y = x;
		q.pop();
		if (x % 2 == 1 && k) {
			k--;
			x--;
		}
		if (x % 2 == 0 && m) {
			m--;
			x /= 2;
		}
		if (y == x) {
			ans += y;
		} else {
			q.push(x);
		}
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