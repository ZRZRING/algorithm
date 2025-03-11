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
	// std::cin >> T;
}

void solve() {
	int Q;
	std::cin >> Q;
	std::vector<A2> q(Q);
	std::vector<int> ans(Q);
	for (int i = 0; i < Q; i++) {
		q[i][1] = i;
		std::cin >> q[i][0];
	}
	std::sort(q.begin(), q.end());
	int64 n = 1e7, sum = 0, x = 0;
	for (int i = 1, j = 0; i <= n && j < Q; i++) {
		x += i;
		sum += x;
		while (j < Q && sum > q[j][0]) {
			ans[q[j][1]] = i;
			j++;
		}
	}
	for (auto x : ans) {
		std::cout << x << '\n';
	}
}

int main() {
	init();
	while (T--) {
		solve();
	}
	return 0;
}