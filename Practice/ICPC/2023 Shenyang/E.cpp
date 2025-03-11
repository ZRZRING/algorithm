#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;
using A3 = std::array<int64, 3>;

#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 inf = 1e9, mod = 998244353;

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int S, W, P, Q;
		std::cin >> S >> W >> P >> Q;
		std::vector f(S + 1, std::vector<A2>(W + 1, {inf, inf}));
		std::vector vis(S + 1, std::vector<A2>(W + 1, {0, 0}));
		f[S][W][0] = 0;
		std::queue<A3> q;
		q.push({S, W, 0});
		auto check = [S, W, Q](int x, int y) -> bool {
			if (x < 0 || y < 0 || x > S || y > W) return 1;
			if (x == 0) return 0;
			return y > x + Q;
		};
		while (!q.empty()) {
			auto [x, y, s] = q.front();
			// std::cout << x << ' ' << y << ' ' << s << ' ' << f[x][y][s] << '\n';
			q.pop();
			if (vis[x][y][s]) continue;
			vis[x][y][s] = 1;
			if (x == 0 && s == 1) {
				std::cout << f[x][y][s] << '\n';
				return;
			}
			if (s == 0) {
				for (int i = 0; i <= std::min(S, P); i++) {
					for (int j = 0; j <= std::min(W, P - i); j++) {
						auto [x0, y0] = (A2){x - i, y - j};
						if (check(x0, y0)) continue;
						f[x0][y0][s ^ 1] = std::min(f[x0][y0][s ^ 1], f[x][y][s] + 1);
						q.push({x0, y0, s ^ 1});
					}
				}
			} else {
				for (int i = 0; i <= std::min(S, P); i++) {
					for (int j = 0; j <= std::min(W, P - i); j++) {
						auto [x0, y0] = (A2){x + i, y + j};
						if (check(S - x0, W - y0)) continue;
						f[x0][y0][s ^ 1] = std::min(f[x0][y0][s ^ 1], f[x][y][s] + 1);
						q.push({x0, y0, s ^ 1});
					}
				}
			}
		}
		std::cout << -1 << '\n';
	}
};

int main() {
	// Fast_IOS;
	WORK work;
	int T = 1;
	// std::cin >> T;
	while (T--) {
		work.solve();
	}
	return 0;
}