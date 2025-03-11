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
	int64 n, m;
	std::cin >> n >> m;
	std::vector<int64> a(n + 1);
	int64 sum = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		sum += a[i];
	}
	std::vector chg(n + 1, std::deque(0, int()));
	for (int i = 1; i <= m; i++) {
		int64 x, y;
		std::cin >> x >> y;
		chg[y].push_back(x);
	}
	std::priority_queue<A2> q;
	for (int i = 1; i <= n; i++) {
		q.push({chg[i].front()});
	}
	while (1) {
		
	}
}

int main() {
	init();
	while (T--) {
		solve();
	}
	return 0;
}