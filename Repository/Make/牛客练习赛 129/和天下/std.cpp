#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

struct DSU {
	int n;

	std::vector<int> fa, size;

	DSU(std::vector<int64> a) : n(a.size() - 1) {
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
		if (x < y) std::swap(x, y);
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
		int n;
		int64 k;
		std::cin >> n >> k;
		int64 d = 0;
		while (1ll << d < k) d++;
		std::vector<int64> a(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		DSU dsu(a);
		#define lowbit(x) ((x) & -(x))
		for (int i = 0; i < 1; i++) {
			int p = 0;
			for (int j = 1; j <= n; j++) {
				if ((a[j] & k) != k) continue;
				if (!p) p = j;
				else dsu.merge(p, j);
			}
		}
		for (int i = 1; i < d; i++) {
			if ((k >> i & 1ll) == 1ll) continue;
			int64 p = 0, t = (k >> i | 1ll) << i;
			for (int j = 1; j <= n; j++) {
				if ((a[j] & t) != t) continue;
				if (!p) p = j;
				else dsu.merge(p, j);
			}
		}
		for (int i = d; i <= 62; i++) {
			int p = 0;
			for (int j = 1; j <= n; j++) {
				if ((a[j] >> i & 1) == 0) continue;
				if (!p) p = j;
				else dsu.merge(p, j);
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (dsu.find(i) == i) {
				ans = std::max(ans, dsu.size[i]);
				// std::cout << a[i] << '\n';
			}
		}
		std::cout << ans << '\n';
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