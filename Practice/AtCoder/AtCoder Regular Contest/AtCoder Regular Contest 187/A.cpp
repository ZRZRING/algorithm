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
	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	if (n == 1) {
		std::cout << "Yes\n" << 0 << "\n\n";
		return;
	}
	if (n == 2) {
		if (a[1] <= a[2]) {
			std::cout << "Yes\n" << 0 << "\n\n";
		} else {
			a[2] += k;
			std::swap(a[1], a[2]);
			if (a[1] <= a[2]) {
				std::cout << "Yes\n" << 1 << '\n' << 1 << '\n';
			} else {
				std::cout << "No\n";
			}
		}
		return;
	}
	std::vector<int> ans;
	auto move = [&](int x) -> void {
		ans.push_back(x);
		a[x + 1] += k;
		std::swap(a[x], a[x + 1]);
	};
	for (int i = 3; i <= n - 1; i += 2) {
		while (a[i] < a[i - 1]) {
			move(i);
			move(i);
		}
	}
	for (int i = n - 1; i >= 2; i--) {
		move(i);
	}
	if (n % 2 == 1) {
		while (a[2] < a[1]) {
			move(2);
			move(2);
		}
		move(2);
		move(1);
	} else {
		while (a[2] < a[1]) {
			move(2);
			move(3);
			move(2);
			move(3);
		}
	}
	for (int i = 2 + !(n % 2); i <= n - 1; i += 2) {
		while (a[i] < a[i - 1]) {
			move(i);
			move(i);
		}
	}
	assert(ans.size() <= 500000);
	std::cout << "Yes\n";
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