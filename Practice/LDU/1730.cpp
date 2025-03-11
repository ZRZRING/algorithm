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
	int flag = 0;
	std::vector<int> a(n + 1), vis1(n + 1), vis2(2 * n + 1), vis3(2 * n + 1);
	std::function<void(int)> dfs = [&](int x) -> void {
		if (x == n + 1) {
			for (int i = 1; i <= n; i++) {
				std::cout << a[i] << " \n"[i == n];
			}
			flag = 1;
			return;
		}
		for (int y = 1; y <= n; y++) {
			if (!vis1[y] && !vis2[x + y] && !vis3[x - y + n]) {
				a[x] = y;
				vis1[y] = 1;
				vis2[x + y] = 1;
				vis3[x - y + n] = 1;
				dfs(x + 1);
				vis1[y] = 0;
				vis2[x + y] = 0;
				vis3[x - y + n] = 0;
			}
		}
	};
	dfs(1);
	if (!flag) {
		std::cout << "no solute!" << endl;
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