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
	int n;
	std::cin >> n;
	std::vector s(6, std::string());
	for (int i = 0; i < 6; i++) {
		std::cin >> s[i];
	}
	std::vector stack(3, std::stack<int>());
	for (int i = n; i >= 1; i--) {
		stack[0].push(i);
	}
	int round = 0;
	while (stack[1].size() < n && stack[2].size() < n) {
		round++;
		for (int i = 0; i < 6; i++) {
			int x = s[i][0] - 'A', y = s[i][1] - 'A';
			std::cout << i << ' ' << x << ' ' << y << '\n';
			if (stack[x].empty()) continue;
			if (stack[y].empty() || stack[x].top() < stack[y].top()) {
				stack[y].push(stack[x].top());
				stack[x].pop();
				break;
			}
			assert(i == 5);
		}
	}
	std::cout << round << '\n';
}

int main() {
	init();
	while (T--) {
		solve();
	}
	return 0;
}