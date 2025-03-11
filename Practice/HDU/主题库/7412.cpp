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

const int64 mod = 1e9 + 7;

int solve() {
	int n;
	std::cin >> n;
	std::vector<int> to(n + 1), d(n + 1);
	std::vector<int64> p(n + 1), P(n + 1, 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> to[i];
		d[to[i]]++;
	}
	int64 ans = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> p[i];
		ans = (ans + mod + 1 - p[i]) % mod;
	}
	std::queue<int> q;
	std::vector<int> vis(n + 1);
	for (int i = 1; i <= n; i++) {
		if (!d[i]) q.push(i);
	}
	while (!q.empty()) {
		int u = q.front();
		vis[u] = 1;
		q.pop();
		if (!--d[to[u]]) q.push(to[u]);
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		int u = i, cnt = 0;
		int64 res = 1;
		while (!vis[u]) {
			vis[u] = 1;
			res = res * (1ll - p[u] + mod) % mod;
			u = to[u];
			cnt++;
		}
		ans = (ans - res * (cnt - 1) % mod + mod) % mod;
		// std::cout << endl;
	}
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