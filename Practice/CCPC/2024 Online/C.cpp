#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

class WORK {
public:
	int N;

	WORK() {}

	struct DSU {
		int n;
	
		std::vector<int> fa, size;
	
		DSU(int n) : n(n) {
			fa.resize(n + 1);
			size.resize(n + 1);
			std::iota(fa.begin(), fa.end(), 0);
			std::fill(size.begin(), size.end(), 1);
		}
	
		int find(int x) {
			return x == fa[x] ? x : fa[x] = find(fa[x]);
		}
	
		int merge(int x, int y) {
			x = find(x); y = find(y);
			if (x == y) return 0;
			fa[x] = y;
			size[y] += size[x];
			return 1;
		}
	};

	void solve() {
		int n, m;
		std::cin >> n >> m;
		std::vector<int> col(n + 1);
		for (int i = 1; i <= m; i++) {
			int x;
			std::cin >> x;
			col[x] = 1;
		}
		DSU dsu(n);
		std::vector e(n + 1, std::vector<int>());
		for (int i = 2; i <= n; i++) {
			int u, v;
			std::cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
			if (col[u] == 0 && col[v] == 0) {
				dsu.merge(u, v);
			}
		}
		for (int i = 1; i <= n; i++) {
			if (col[i] == 0) continue;
			int x = 0;
			for (auto v : e[i]) {
				if (col[v] == 0) {
					if (!x) x = v;
					else dsu.merge(x, v);
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (col[i] == 0 && i == dsu.find(i)) {
				ans += dsu.size[i] % 2;
			}
		}
		std::cout << (ans + n - m + 1) / 2 << '\n';
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