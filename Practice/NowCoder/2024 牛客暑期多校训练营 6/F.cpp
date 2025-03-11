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

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int n, m;
		std::cin >> n >> m;
		std::vector<int> d(n + 1);
		std::vector<std::vector<int>> e(n + 1);
		for (int i = 1; i <= m; i++) {
			int u, v;
			std::cin >> u >> v;
			d[u]++;
			d[v]++;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		std::vector<int> vis(n + 1, 0);
		std::vector<std::vector<int>> ans(2);
		for (int i = 1; i <= n; i++) {
			if (d[i] == 0) {
				ans[0].push_back(i);
			}
		}
		for (int i = 1; i <= n; i++) {
			if (d[i] == n - 1) {
				std::cout << "-1" << '\n';
				return;
			}
			if (d[i] != 1 || vis[i]) continue;
			std::queue<A2> q;
			q.push({i, 0});
			while (!q.empty()) {
				auto [u, d] = q.front();
				q.pop();
				vis[u] = 1;
				ans[d].push_back(u);
				for (auto v : e[u]) {
					if (vis[v]) continue;
					q.push({v, d ^ 1});
				}
			}
		}
		for (auto x : ans[1]) {
			std::cout << x << ' ';
		}
		// for (auto x : ans[2]) {
		// 	std::cout << x << ' ';
		// }
		for (auto x : ans[0]) {
			std::cout << x << ' ';
		}
		std::cout << '\n';
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