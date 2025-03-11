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
	std::string s;
	std::cin >> n >> s;
	std::vector<int> vis(300);
	for (auto x : s) {
		vis[x]++;
	}
	int idx = 'a';
	for (int i = 'a'; i <= 'z'; i++) {
		if (vis[i] > vis[idx]) idx = i;
	}
	std::cout << (char)(idx) << '\n';
}

int main() {
	init();
	while (T--) {
		solve();
	}
	return 0;
}