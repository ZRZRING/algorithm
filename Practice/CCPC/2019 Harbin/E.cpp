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
		int n;
		std::cin >> n;
		std::vector<int> d(n + 1);
		std::vector<int64> cnt(n + 1);
		std::map<int, int64> vis;
		std::vector a(n + 1, std::vector<int>());
		std::vector e(n + 1, std::vector<int>());
		for (int i = 1; i <= n; i++) {
			int o;
			std::cin >> o;
			if (o == 1) {
				int m;
				std::cin >> m;
				for (int j = 1; j <= m; j++) {
					int x;
					std::cin >> x;
					a[i].push_back(x);
				}
			} else {
				int x, y;
				std::cin >> x >> y;
				e[i].push_back(x);
				e[i].push_back(y);
				d[x]++;
				d[y]++;
			}
		}
		std::queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (!d[i]) q.push(i);
		}
		cnt[n] = 1;
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (auto v : e[u]) {
				d[v]--;
				cnt[v] += cnt[u];
				if (!d[v]) {
					q.push(v);
				}
			}
		}
		int64 len = 0, max = 0;
		for (int i = 1; i <= n; i++) {
			// std::cout << cnt[i] << '\n';
			len += cnt[i] * a[i].size();
			for (auto x : a[i]) {
				vis[x] += cnt[i];
			}
		}
		for (auto [x, y] : vis) {
			max = std::max(max, y);
		}
		std::cout << std::min(len, 2ll * (len - max)) << '\n';
	}
};

int main() {
	Fast_IOS;
	WORK work;
	int T = 1;
	std::cin >> T;
	while (T--) {
		work.solve();
	}
	return 0;
}