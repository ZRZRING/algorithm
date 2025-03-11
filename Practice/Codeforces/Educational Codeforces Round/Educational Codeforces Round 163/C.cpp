#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS \
	std::ios::sync_with_stdio(false), \
	std::cin.tie(0), \
	std::cout.tie(0)

const int64 mod = 998244353;

const int N = 1e5 + 10;

int T = 1;

void init() {
	Fast_IOS;
	std::cin >> T;
}

void solve() {
	int n;
	std::cin >> n;
	std::vector<std::string> s(2);
	std::vector<std::vector<int>> vis(2, std::vector<int>(n));
	std::cin >> s[0] >> s[1];
	std::queue<A2> q;
	q.push({0, 0});
	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		if (vis[x][y]) continue;
		vis[x][y] = 1;
		if (x > 0 && s[x][y - 1] == '<') q.push({x, y - 2});
		if (x < n && s[x][y + 1] == '>') q.push({x, y + 2});
		q.push({x ^ 1, s[x ^ 1][y] == '<' ? y - 1 : y + 1});
	}
	std::cout << (vis[1][n - 1] ? "YES" : "NO") << "\n";
}

int main() {
	init();
	while (T--) {
		solve();
	}
	return 0;
}