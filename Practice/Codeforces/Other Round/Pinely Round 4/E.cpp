#include <bits/stdc++.h>

using int64 = long long;

#define A2 std::array<int, 2>
#define lowbit(x) ((x) & -(x))
#define NO return (void)(std::cout << "NO" << std::endl)
#define YES return (void)(std::cout << "YES" << std::endl)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

template <class T> T lg(T x) {return (T)log10(x);}
template <class T> T log(T x) {return (T)log2(x);}
template <class T> T abs(T x) {return x < 0 ? -x : x;}
template <class T> T mysqrt(T x) {return std::floor(sqrtl(x));}
template <class T> T MOD(T &x, int64 p = mod) {return x = (x % p + p) % p;}
template <class T> T MOD(T &&x, int64 p = mod) {return x = (x % p + p) % p;}
template <class T1, class T2> T1 getbit(T1 x, T2 t) {return x >> t & 1ll;}

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int n, m;
		std::cin >> n >> m;
		std::vector<std::vector<int>> e(n + 1);
		for (int i = 1; i <= m; i++) {
			int u, v;
			std::cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		bool flag = 0;
		std::vector<int> vis(n + 1, -1);
		auto dfs = [&](auto self, int u, int last, int t) -> void {
			vis[u] = t;
			for (auto v : e[u]) {
				if (~vis[v]) {
					flag |= (vis[u] == vis[v]);
				} else {
					self(self, v, u, t ^ 1);
				}
			}
		};
		dfs(dfs, 1, 1, 0);
		if (flag) {
			std::cout << "Alice" << std::endl;
			for (int i = 1; i <= n; i++) {
				std::cout << 1 << ' ' << 2 << std::endl;
				int a, b;
				std::cin >> a >> b;
			}
		} else {
			std::cout << "Bob" << std::endl;
			std::vector<std::vector<int>> col(2);
			for (int i = 1; i <= n; i++) {
				col[vis[i]].push_back(i);
			}
			for (int i = 1; i <= n; i++) {
				int a, b;
				std::cin >> a >> b;
				std::vector<int> vis(3);
				vis[a - 1] = 1;
				vis[b - 1] = 1;
				if (vis[0] && !col[0].empty()) {
					std::cout << col[0].back() << ' ' << 1 << std::endl;
					col[0].pop_back();
				} else if (vis[1] && !col[1].empty()) {
					std::cout << col[1].back() << ' ' << 2 << std::endl;
					col[1].pop_back();
				} else if (!col[0].empty()) {
					std::cout << col[0].back() << ' ' << 3 << std::endl;
					col[0].pop_back();
				} else {
					std::cout << col[1].back() << ' ' << 3 << std::endl;
					col[1].pop_back();
				}
			}
		}
	}
};

int main() {
	WORK work;
	int T = 1;
	std::cin >> T;
	while (T--) {
		work.solve();
	}
	return 0;
}