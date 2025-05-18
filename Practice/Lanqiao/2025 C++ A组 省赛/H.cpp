#include <bits/stdc++.h>

using int64 = long long;
using uint = unsigned int;
using A2 = std::array<int, 2>;

#define Fast_IOS \
	std::ios::sync_weith_stdio(false), \
	std::cin.tie(0), \
	std::cout.tie(0)

const int N = 1e6;

int T = 1;

void init() {
//	Fast_IOS;
// 	std::cin >> T;
}

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> tidy(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> tidy[i];
	}
	std::vector<std::vector<A2>> e(n + 1);
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		int u, v;
		std::cin >> u >> v;
		e[u].push_back({v, cnt++});
		e[v].push_back({u, cnt++});
	}
	std::vector<int> vis(n + 1), ring(n + 1), R;
	auto dfs = [&](auto self, int u, int last) -> int {
//		std::cout << u << '\n';
		if (vis[u]) {
			ring[u] = 1;
			R.push_back(u);
			return u;
		}
		vis[u] = 1;
		for (auto pair : e[u]) {
			int v = pair[0], num = pair[1];
			if (num == (last ^ 1)) {
				continue;
			}
			int t = self(self, v, num);
			if (t == u) return 0;
			if (t) {
				ring[u] = 1;
				R.push_back(u);
				return t;
			}
		}
		return 0;
	};
	dfs(dfs, 1, -1);
//	for (auto x : R) {
//		std::cout << x << '\n';
//	}
	std::vector<A2> f(n + 1);
	int ans = 0, m = R.size();
	auto dfs2 = [&](auto self, int u, int last) -> void {
		for (auto pair : e[u]) {
			int v = pair[0], num = pair[1];
			if (ring[v] || num == (last ^ 1)) {
				continue;
			}
			self(self, v, num);
			if (f[v][0] + tidy[v] > f[u][0]) {
				f[u][1] = f[u][0];
				f[u][0] = f[v][0] + tidy[v];
			} else if (f[v][0] + tidy[v] > f[u][1]) {
				f[u][1] = f[v][0] + tidy[v];
			}
		}
		ans = std::max(ans, f[u][0] + f[u][1] + tidy[u]);
	};
	std::vector<int> maxRoad(m);
	for (int i = 0; i < m; i++) {
		dfs2(dfs2, R[i], -1);
		maxRoad[i] = f[R[i]][0];
	}
//	std::vector<int> pre(m);
//	pre[0] = tidy[R[0]];
//	for (int i = 1; i < m; i++) {
//		pre[i] = pre[i - 1] + tidy[R[i]];
//	}
//	for (int i = 0; i < m; i++) {
//		for (int j = i + 1; j < m; j++) {
//			int t;
//			if (i == 0) {
//				t = std::max(pre[j], pre[i] + pre[m] - pre[j - 1]);	
//			} else {
//				t = std::max(pre[j] - pre[i - 1], pre[i] + pre[m] - pre[j - 1]);
//			}
//			ans = std::max(ans, maxRoad[i] + maxRoad[j] + t);
//		}
//	}
//	std::cout << ans << '\n';
	if (1) {
		std::vector<int> a(2 * m), b(2 * m), c(2 * m);
		for (int i = 0; i < m; i++) {
			a[i] = a[i + m] = maxRoad[i];
			b[i] = b[i + m] = tidy[R[i]];
		}
		for (int i = 0; i < m; i++) {
			c[0] += b[i];
		}
		for (int i = 1; i < 2 * m; i++) {
			c[i] = c[i - 1] - b[i - 1];
		}
//		for (int i = 0; i < 2 * m; i++) std::cout << a[i] << ' '; std::cout << '\n';
//		for (int i = 0; i < 2 * m; i++) std::cout << b[i] << ' '; std::cout << '\n';
//		for (int i = 0; i < 2 * m; i++) std::cout << c[i] << ' '; std::cout << '\n';
		int d = 0;
		std::priority_queue<A2> q;
		for (int i = 0; i < m; i++) {
			q.push({a[i] + c[i], i});
		}
		std::vector<int> del(2 * m);
		del[0] = 1;
		for (int i = 0; i < m; i++) {
			while (del[q.top()[1]]) {
				q.pop();
			}
//			std::cout << i << ' ' << a[i] << ' ' << b[i] << ' ' << q.top()[0] << ' ' << q.top()[1] << ' ' << d << '\n';
			ans = std::max(ans, a[i] + b[i] + q.top()[0] + d);
			del[i + 1] = 1;
			d += b[i];
			q.push({a[i + m] + c[i + m], i + m});
		}
		std::cout << ans << '\n';
	}
}

int main() {
	init();
	while (T--) {
		solve();
	}
	return 0;
}


