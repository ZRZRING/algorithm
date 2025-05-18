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
	std::vector<int> vis(n + 1);
	for (int i = 1; i <= n; i++) {
		int x;
		std::cin >> x;
		vis[x]++;
	}
	int cnt = 0;
	for (int i = 0; i <= n; i++) {
		if (vis[i] == 0) {
			std::cout << i << endl;
			return 0;
		}
		if (vis[i] == 1) {
			cnt++;
			if (cnt == 2) {
				std::cout << i << endl;
				return 0;
			}
		}
	}
	return 0;
}

int main() {
	Fast_IOS;
	int T = 1;
	std::cin >> T;
	while (T--) {
		int t = solve();
		if (t == 0) continue;
		if (t == YES) std::cout << "YES" << endl;
		if (t == NO) std::cout << "NO" << endl;
	}
	return 0;
}