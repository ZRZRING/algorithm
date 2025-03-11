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
	int n, X, Y;
	std::cin >> n >> X >> Y;
	std::string s;
	std::cin >> s;
	std::map<char, A2> go = {
		{'N', {0, 1}},
		{'E', {1, 0}},
		{'S', {0, -1}},
		{'W', {-1, 0}},
	};
	int x = 0, y = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < n; j++) {
			x += go[s[j]][0];
			y += go[s[j]][1];
			if (x == X && y == Y) {
				std::cout << "YES\n";
				return;
			}
		}
	}
	std::cout << "NO\n";
}

int main() {
	init();
	while (T--) {
		solve();
	}
	return 0;
}