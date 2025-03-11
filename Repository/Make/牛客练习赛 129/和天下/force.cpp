#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

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

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int n, k;
		std::cin >> n >> k;
		std::vector<int64> a(n + 1);
		DSU dsu(n);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
			for (int j = 1; j < i; j++) {
				if ((a[i] & a[j]) >= k) {
					dsu.merge(i, j);
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (dsu.find(i) == i) ans = std::max(ans, dsu.size[i]);
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