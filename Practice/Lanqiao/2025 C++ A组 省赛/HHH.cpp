#include <bits/stdc++.h>

using int64 = long long;
using uint = unsigned int;
using A2 = std::array<int, 2>;

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
	int m, ans = 0;
	std::cin >> m;
	std::vector<int> a(2 * m), b(2 * m), c(2 * m);
	for (int i = 0; i < m; i++) {
		std::cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		std::cin >> b[i];
	}
	for (int i = 0; i < m; i++) {
		a[i + m] = a[i];
		b[i + m] = b[i];
	}
	for (int i = 0; i < m; i++) {
		c[0] += b[i];
	}
	for (int i = 1; i < 2 * m; i++) {
		c[i] = c[i - 1] - b[(i - 1) % m];
	}
//	for (int i = 0; i < 2 * m; i++) std::cout << a[i] << ' '; std::cout << '\n';
//	for (int i = 0; i < 2 * m; i++) std::cout << b[i] << ' '; std::cout << '\n';
//	for (int i = 0; i < 2 * m; i++) std::cout << c[i] << ' '; std::cout << '\n';
	int d = 0;
	std::priority_queue<A2> q;
	for (int i = 0; i < m; i++) {
		q.push({a[i] + c[i], i});
	}
	std::vector<int> del(2 * m);
	del[0] = 1;
	for (int i = 0; i < m; i++) {
		while (del[q.top()[1]]) {
			q.pop();
		}
//		std::cout << i << ' ' << a[i] << ' ' << b[i] << ' ' << q.top()[0] << ' ' << q.top()[1] << ' ' << d << '\n';
		ans = std::max(ans, a[i] + b[i] + q.top()[0] + d);
		del[i + 1] = 1;
		d += b[i];
		q.push({a[i + m] + c[i + m], i + m});
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


