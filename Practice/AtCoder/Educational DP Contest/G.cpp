#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int n, m;
		std::cin >> n >> m;
		std::vector e(n + 1, std::vector<int>());
		std::vector<int> d(n + 1);
		for (int i = 1; i <= m; i++) {
			int u, v;
			std::cin >> u >> v;
			e[u].push_back(v);
			d[v]++;
		}
		std::vector<int> f(n + 1);
		std::queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (!d[i]) {
				q.push(i);
			}
		}
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (auto v : e[u]) {
				f[v] = std::max(f[v], f[u] + 1);
				d[v]--;
				if (!d[v]) {
					q.push(v);
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			ans = std::max(ans, f[i]);
		}
		std::cout << ans << '\n';
	}
};

int main() {
	Fast_IOS;
	WORK work;
	int T = 1;
	// std::cin >> T;
	while (T--) {
		work.solve();
	}
	return 0;
}