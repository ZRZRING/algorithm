#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'
#define PII std::pair<int64, int64>
#define NO return (void)(std::cout << "NO" << endl)
#define YES return (void)(std::cout << "YES" << endl)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

const int go[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};

template <class T> void MOD(T &x) {x = (x % mod + mod) % mod;}
template <class T> T lg(T x) {return (T)log10(x);}
template <class T> T log(T x) {return (T)log2(x);}
template <class T> T abs(T x) {return x < 0 ? -x : x;}
template <class T> T mysqrt(T x) {return std::floor(sqrtl(x));}

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int n, m;
		std::cin >> n >> m;
		std::vector<std::string> map(n + 2);
		for (int i = 0; i <= m + 1; i++) {
			map[0].push_back(' ');
			map[n + 1].push_back(' ');
		}
		for (int i = 1; i <= n; i++) {
			std::cin >> map[i];
			map[i] = " " + map[i] + " ";
		}
		#define A3 std::array<int, 3>
		N = 4 * (n + 2) * (m + 2);
		std::vector<int> ans(N + 1);
		std::vector<int> vis(N + 1);
		std::set<PII> S;
		std::set<A3> SS;
		auto cal = [&](A3 a) -> int {
			return (a[0] * (m + 2) + a[1]) * 4 + a[2];
		};
		auto dfs = [&](auto self, A3 X, int K) -> void {
			vis[cal(X)] = 1;
			auto [x, y, d] = X;
			// std::cout << x << ' ' << y << ' ' << d << endl;
			int xx = x + go[0][d], yy = y + go[1][d], dd, M = 1;
			if (map[xx][yy] == '|') {
				if (d <= 1) dd = d, M = 0;
				else dd = d ^ 1;
			}
			if (map[xx][yy] == '-') {
				if (d >= 2) dd = d, M = 0;
				else dd = d ^ 1;
			}
			if (map[xx][yy] == '/') {
				dd = d ^ 3;
			}
			if (map[xx][yy] == '\\') {
				dd = d ^ 2;
			}
			if (map[xx][yy] == ' ') {
				return;
			}
			if (K) {
				SS.insert(X);
				A3 Y = {xx, yy, dd};
				if (vis[cal(Y)]) {
					S.insert({xx, yy});
					return;
				}
				self(self, Y, K);
				if (M) S.insert({xx, yy});
			} else {
				A3 Y = {xx, yy, dd};
				self(self, Y, K);
				if (M) S.insert({xx, yy});
				ans[cal(X)] = S.size();
			}
		};
		for (int i = 1; i <= n; i++) {
			S.clear();
			dfs(dfs, {i, 0, 3}, 0);
			S.clear();
			dfs(dfs, {i, m + 1, 2}, 0);
		}
		for (int i = 1; i <= m; i++) {
			S.clear();
			dfs(dfs, {0, i, 1}, 0);
			S.clear();
			dfs(dfs, {n + 1, i, 0}, 0);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				for (int k = 0; k < 4; k++) {
					if (!vis[cal({i, j, k})]) {
						S.clear();
						SS.clear();
						dfs(dfs, {i, j, k}, 1);
						for (auto X : SS) {
							ans[cal(X)] = S.size();
						}
					}
				}
			}
		}
		// for (int k = 0; k < 4; k++) {
		// 	for (int i = 1; i <= n; i++) {
		// 		for (int j = 1; j <= m; j++) {
		// 			std::cout << ans[{i, j, k}] << " \n"[j == m];
		// 		}
		// 	}
		// 	std::cout << endl;
		// }
		int T;
		std::cin >> T;
		std::map<std::string, int> dic;
		dic["above"] = 0;
		dic["below"] = 1;
		dic["left"] = 2;
		dic["right"] = 3;
		while (T--) {
			int x, y;
			std::string dir;
			std::cin >> x >> y >> dir;
			std::cout << ans[cal({x, y, dic[dir]})] << endl;
		}
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