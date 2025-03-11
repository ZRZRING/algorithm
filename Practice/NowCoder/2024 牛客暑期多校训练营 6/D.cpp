#include <bits/stdc++.h>

using int64 = long long;

#define A2 std::array<int, 2>
#define lowbit(x) ((x) & -(x))
#define NO return (void)(std::cout << "NO" << endl)
#define YES return (void)(std::cout << "YES" << endl)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

template <class T> T lg(T x) {return (T)log10(x);}
template <class T> T log(T x) {return (T)log2(x);}
template <class T> T abs(T x) {return x < 0 ? -x : x;}
template <class T> T mysqrt(T x) {return std::floor(sqrtl(x));}
template <class T> T MOD(T &x, int64 p = mod) {return x = (x % p + p) % p;}
template <class T> T MOD(T &&x, int64 p = mod) {return x = (x % p + p) % p;}
template <class T1, class T2> T1 getbit(T1 x, T2 t) {return x >> t & 1ll;}

struct DSU {
	int n, cnt;

	std::vector<int> fa, size;

	DSU(int n) : n(n), cnt(n) {
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
		cnt--;
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
		int n, m;
		std::cin >> n >> m;
		std::vector<std::vector<std::pair<int, std::string>>> e(n + 1);
		for (int i = 1; i <= m; i++) {
			int u, v;
			std::string s;
			std::cin >> u >> v >> s;
			e[u].push_back({v, s});
			e[v].push_back({u, s});
		}
		int cnt = 0;
		std::stack<int> stk;
		std::vector<int> dfn(n + 1), low(n + 1), col(n + 1);
		std::vector<std::vector<int>> scc;
		auto dfs = [&](auto self, int u, int last) -> void {
			stk.push(u);
			dfn[u] = low[u] = ++cnt;
			for (auto [v, s] : e[u]) {
				if (v == last || s != "Lun") continue;
				if (!dfn[v]) {
					self(self, v, u);
					low[u] = std::min(low[u], low[v]);
				} else {
					low[u] = std::min(low[u], dfn[v]);
				}
			}
			if (dfn[u] == low[u]) {
				int t = scc.size();
				col[u] = t;
				scc.push_back({u});
				while (stk.top() != u) {
					int x = stk.top();
					stk.pop();
					col[x] = t;
					scc.back().push_back(x);
				}
				stk.pop();
			}
		};
		for (int i = 1; i <= n; i++) {
			if (!dfn[i]) dfs(dfs, i, i);
		}
		// for (int i = 1; i <= n; i++) {
		// 	std::cout << col[i] << ' ' << dfn[i] << ' ' << low[i] << '\n';
		// }
		DSU dsu(n);
		std::vector<A2> ans;
		for (int u = 1; u <= n; u++) {
			for (auto [v, s] : e[u]) {
				if (v < u) continue;
				if (s == "Lun" && col[u] == col[v]) {
					dsu.merge(u, v);
					ans.push_back({u, v});
				}
			}
		}
		for (int u = 1; u <= n; u++) {
			for (auto [v, s] : e[u]) {
				if (v < u) continue;
				if (s == "Qie" && col[u] != col[v]) {
					if (dsu.merge(u, v)) {
						ans.push_back({u, v});
					}
				}
			}
		}
		if (dsu.cnt != 1) {
			std::cout << "NO\n";
		} else {
			std::cout << "YES\n";
			std::cout << ans.size() << '\n';
			for (auto [u, v] : ans) {
				std::cout << u << ' ' << v << '\n';
			}
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