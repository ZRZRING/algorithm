#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;
using A3 = std::array<int64, 3>;

#define Fast_IOS \
	std::ios::sync_with_stdio(false), \
	std::cin.tie(0), \
	std::cout.tie(0)

const int64 mod = 998244353;

struct PLAYER {
	int n;
	std::vector<A3> a;

	PLAYER(int n) : n(n) {
		a.resize(n + 1);
		a[0][2] = 1e9;
		for (int i = 1; i <= n; i++) {
			int x;
			std::cin >> x;
			a[i] = {x, x, 0};
		}
	}

	int move() {
		int min = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i][1] > 0 && a[i][2] < a[min][2]) {
				min = i;
			}
		}
		return min;
	}

	void print() {
		bool flag = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i][1] <= 0) continue;
			std::cout << a[i][0] << '/' << a[i][1] << ' ';
			flag = 1;
		}
		if (!flag) {
			std::cout << "empty\n";
		} else {
			std::cout << '\n';
		}
	}
	
	std::vector<int> get() {
		std::vector<int> g;
		for (int i = 1; i <= n; i++) {
			if (a[i][1] > 0) {
				g.push_back(i);
			}
		}
		return g;
	}
};

class ICPC {
public:
	int N, T = 1;

	ICPC() {
		// Fast_IOS;
		// std::cin >> T;
	}

	void solve() {
		int n, m;
		std::cin >> n >> m;
		std::vector<PLAYER> P = {PLAYER(n), PLAYER(m)};
		// std::cout << P[0].n << ' ' << P[1].n << '\n';
		std::vector<double> ans(3, 0);
		// std::vector ans(3, std::vector<double>());
		auto dfs = [&](auto self, int o, double p) -> void {
			// P[0].print();
			// P[1].print();
			// printf("\n\n");
			A2 M = {P[0].move(), P[1].move()};
			if (M[0] == 0 || M[1] == 0) {
				if (M[0] == 0 && M[1] == 0) {
					// ans[2].push_back(p);
					ans[2] += p;
					// std::cout << 2 << ' ' << p << '\n';
				} else if (M[0] == 0) {
					// ans[1].push_back(p);
					ans[1] += p;
					// std::cout << 1 << ' ' << p << '\n';
				} else {
					// ans[0].push_back(p);
					ans[0] += p;
					// std::cout << 0 << ' ' << p << '\n';
				}
				return;
			}
			int cnt = 0;
			std::vector<int> g = P[o ^ 1].get();
			int x = M[o];
			for (auto y : g) {
				P[o].a[x][1] -= P[o ^ 1].a[y][0];
				P[o ^ 1].a[y][1] -= P[o].a[x][0];
				P[o].a[x][2]++;
				// P[o ^ 1].a[y][2]++;
				self(self, o ^ 1, p / g.size());
				P[o].a[x][1] += P[o ^ 1].a[y][0];
				P[o ^ 1].a[y][1] += P[o].a[x][0];
				P[o].a[x][2]--;
				// P[o ^ 1].a[y][2]--;
			}
		};
		if (P[0].n == P[1].n) {
			dfs(dfs, 0, 0.5);
			dfs(dfs, 1, 0.5);
		} else if (P[0].n > P[1].n) {
			dfs(dfs, 0, 1.0);
		} else {
			dfs(dfs, 1, 1.0);
		}
		std::cout << std::fixed << std::setprecision(15);
		// for (auto x : ans[0]) std::cout << x << ' '; std::cout << '\n';
		// for (auto x : ans[1]) std::cout << x << ' '; std::cout << '\n';
		// for (auto x : ans[2]) std::cout << x << ' '; std::cout << '\n';
		std::cout << ans[0] << '\n';
		std::cout << ans[1] << '\n';
		std::cout << ans[2] << '\n';
	}
};

int main() {
	ICPC icpc;
	while (icpc.T--) {
		icpc.solve();
	}
	return 0;
}