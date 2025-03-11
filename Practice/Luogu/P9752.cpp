#include <bits/stdc++.h>

using int64 = long long;

#define NO 2
#define YES 1
#define endl '\n'
#define lg(x) ((int)log10(x))
#define log(x) ((int)log2(x))
#define PII std::pair<int64, int64>
#define abs(x) ((x) < 0 ? -(x) : (x))
#define MOD(x) ((x) = ((x) % mod + mod) % mod)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0)
#define debug(x) std::cerr << "In Line " << __LINE__ << " the " << #x << " = " << x << '\n';

const int64 mod = 998244353;

int solve() {
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> s(n, std::vector<int>(5));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			std::cin >> s[i][j];
		}
	}
	std::vector<int> a(5);
	int ans = 0;
	auto dfs = [&](auto self, int x) {
		if (x == 5) {
			for (int i = 0; i < n; i++) {
				std::vector<int> t;
				for (int j = 0; j < 5; j++) {
					if (a[j] != s[i][j]) {
						t.push_back(j);
					}
				}
				if (t.size() == 1) continue;
				if (t.size() == 2) {
					if (t[0] + 1 == t[1]) {
						if ((a[t[0]] - s[i][t[0]] + 10) % 10 == (a[t[1]] - s[i][t[1]] + 10) % 10) {
							continue;
						}
					}
				}
				return;
			}
			ans++;
			return;
		}
		for (int i = 0; i <= 9; i++) {
			a[x] = i;
			self(self, x + 1);
		}
	};
	dfs(dfs, 0);
	std::cout << ans << endl;
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