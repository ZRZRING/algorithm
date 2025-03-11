#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'
#define PII std::pair<int, int>
#define init_0(x) memset(x, 0, sizeof(x))
#define init_inf(x) memset(x, 0x3f, sizeof(x))

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int N = 2e5, mod = 998244353, inf = 0x3f3f3f3f;

void solve() {
	int n = read(), m = read(), k = read();
	std::vector<int64> h(n + 1, 0);
	for (int i = 1; i <= n; i++) h[i] = read();
	std::vector<int> edge[n + 1], d(n + 1, 0);
	for (int i = 1; i <= m; i++) {
		int u = read(), v = read();
		edge[u].push_back(v); d[v]++;
	}
	std::vector<int> q; q.push_back(0);
	for (int i = 1; i <= n; i++) if (!d[i]) q.push_back(i);
	for (int i = 1; i <= n; i++) {
		int u = q[i];
		for (auto v : edge[u]) if (--d[v] == 0) q.push_back(i);
	}
	std::vector<int64> dp(n + 1, 0);
	for (int i = n; i >= 1; i--) {
		int u = q[i];
		for (auto v : edge[u]) {
			dp[]
		}
	}
	int64 max = *std::max_element(dp.begin() + 1, dp.end());
	std::vector<int> p(n + 1);
	std::iota(p.begin(), p.end(), 0);
	std::sort(p.begin() + 1, p.end(), [&](int a, int b) {return h[a] < h[b];});
	int64 ans = 1e18;
	for (int i = 1; i <= n; i++) {
		ans = std::min(ans, max - h[i]);
		max = std::max(max, dp[i] + k);
	}
	printf("%lld\n", ans);
}

int main() {
	int T = read();
	while (T--) solve();
	return 0;
}