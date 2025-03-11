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

int lowbit(int x) {
	return x & -x;
}

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin() + 1, a.end());
	std::map<int, int> pos, next;
	for (int i = 1; i <= n; i++) {
		pos[a[i]] = i;
		int x = a[i], t = lowbit(x);
		x ^= t;
		t <<= 1;
		while ((x ^ t) < x) t <<= 1;
		x ^= t;
		next[a[i]] = x;
	}
	// for (auto [x, y] : next) {
	// 	std::cout << x << ' ' << y << '\n';
	// }
	std::vector<int> step(n + 1);
	for (int i = n; i >= 1; i--) {
		step[i] = step[pos[next[a[i]]]] + 1;
	}
	int idx = 1;
	for (int i = 1; i <= n; i++) {
		if (step[i] > step[idx]) {
			idx = i;
		}
	}
	std::vector<int> ans;
	int x = idx;
	while (x) {
		ans.push_back(x);
		x = pos[next[a[x]]];
	}
	std::cout << ans.size() << '\n';
	for (auto x : ans) {
		std::cout << x << ' ';
	}
	std::cout << '\n';
}

int main() {
	init();
	while (T--) {
		solve();
	}
	return 0;
}