#include <bits/stdc++.h>

using int64 = long long;
using A3 = std::array<int64, 3>;

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

	int abs(int a) {
		return a < 0 ? -a : a;
	}

	int dis(A3 a, A3 b) {
		return std::min(abs(a[0] - b[0]), abs(a[1] - b[1]));
	}

	void solve() {
		int n;
		std::cin >> n;
		std::vector<A3> p(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> p[i][0] >> p[i][1];
			p[i][2] = i;
		}
		std::vector<A3> p1 = p, p2 = p;
		std::sort(p1.begin() + 1, p1.end(), [](A3 a, A3 b) {
			return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
		});
		std::sort(p2.begin() + 1, p2.end(), [](A3 a, A3 b) {
			return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
		});
		std::vector<A3> e;
		for (int i = 1; i <= n - 1; i++) {
			e.push_back({dis(p1[i], p1[i + 1]), p1[i][2], p1[i + 1][2]});
			e.push_back({dis(p2[i], p2[i + 1]), p2[i][2], p2[i + 1][2]});
		}
		for (int i = 2; i <= n; i++) {
			e.push_back({dis(p1[i], p1[i - 1]), p1[i][2], p1[i - 1][2]});
			e.push_back({dis(p2[i], p2[i - 1]), p2[i][2], p2[i - 1][2]});
		}
		DSU dsu(n + 1);
		std::sort(e.begin(), e.end());
		int64 ans = 0;
		for (auto [t, x, y] : e) {
			if (!dsu.merge(x, y)) continue;
			ans += t;
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