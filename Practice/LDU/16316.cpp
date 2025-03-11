#include <bits/stdc++.h>

using int64 = long long;

#define NO 2
#define YES 1
#define endl '\n'
#define PII std::pair<int64, int64>
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0)
#define debug(x) std::cerr << "In Line " << __LINE__ << " the " << #x << " = " << x << '\n';

const int64 mod = 998244353;

template <class T> void MOD(T &x) {x = x % mod;}
template <class T> int64 abs(T x) {return x < 0 ? -x : x;}
template <class T> int64 lg(T x) {return (int)log10(x);}
template <class T> int64 log(T x) {return (int)log2(x);}

int solve() {
	int k, X, Y, cnt = 0;
	std::cin >> k >> X >> Y;
	std::vector<std::vector<int>> ans(1 << k | 1, std::vector<int>(1 << k | 1));
	ans[X][Y] = -1;
	auto dfs = [&](auto self, int x1, int y1, int x2, int y2, int x, int y) -> void {
		if (x1 == x2 && y1 == y2) return;
		int t = ++cnt;
		int x3 = (x1 + x2) / 2, y3 = (y1 + y2) / 2;
		if (x <= x3 && y <= y3) self(self, x1, y1, x3, y3, x, y);
		else ans[x3][y3] = t, self(self, x1, y1, x3, y3, x3, y3);
		if (x > x3 && y <= y3) self(self, x3 + 1, y1, x2, y3, x, y);
		else ans[x3 + 1][y3] = t, self(self, x3 + 1, y1, x2, y3, x3 + 1, y3);
		if (x <= x3 && y > y3) self(self, x1, y3 + 1, x3, y2, x, y);
		else ans[x3][y3 + 1] = t, self(self, x1, y3 + 1, x3, y2, x3, y3 + 1);
		if (x > x3 && y > y3) self(self, x3 + 1, y3 + 1, x2, y2, x, y);
		else ans[x3 + 1][y3 + 1] = t, self(self, x3 + 1, y3 + 1, x2, y2, x3 + 1, y3 + 1);
	};
	dfs(dfs, 1, 1, 1 << k, 1 << k, X, Y);
	for (int i = 1; i <= 1 << k; i++) {
		for (int j = 1; j <= 1 << k; j++) {
			std::cout << ans[i][j] << " \n"[j == 1 << k];
		}
	}
	return 0;
}

int main() {
	Fast_IOS;
	int T = 1;
	// std::cin >> T;
	while (T--) {
		int t = solve();
		if (t == 0) continue;
		if (t == YES) std::cout << "YES" << endl;
		if (t == NO) std::cout << "NO" << endl;
	}
	return 0;
}