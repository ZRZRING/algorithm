#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'
#define PII std::pair<int64, int64>
#define NO return (void)(std::cout << "NO" << endl)
#define YES return (void)(std::cout << "YES" << endl)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

template <class T> void MOD(T &x) {x = (x % mod + mod) % mod;}
template <class T> T lg(T x) {return (T)log10(x);}
template <class T> T log(T x) {return (T)log2(x);}
template <class T> T abs(T x) {return x < 0 ? -x : x;}
template <class T> T mysqrt(T x) {return std::floor(sqrtl(x));}

struct WORK {
	int N;

	WORK() {}

	void solve() {
		int n;
		std::cin >> n;
		std::vector<int> val(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> val[i];
		}
		std::vector<std::vector<int>> e(n + 1);
		for (int i = 1; i < n; i++) {
			int u, v;
			std::cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		std::vector<int> vis(n + 1), size(n + 1);
		auto dfs1 = [&](auto self, int u, int last) -> void {
			size[u] = 1;
			for (auto v : e[u]) {
				if (v == last) continue;
				self(self, v, u);
				size[u] += size[v];
			}
		};
		dfs1(dfs1, 1, 0);
		int ans = n;
		auto dfs2 = [&](auto self, int u, int last, int d) -> int {
			int cnt = 0;
			for (auto v : e[u]) {
				if (v == last) continue;
				int t = (d || val[u] * 2 < val[v]);
				if (self(self, v, u, t) || val[v] * 2 < val[u]) {
					cnt++;
				}
			}
			// std::cout << u << ' ' << cnt << ' ' << d << endl;
			if (cnt + d >= 2) ans = 0;
			return cnt;
		};
		dfs2(dfs2, 1, 0, 0);
		if (ans == 0) {
			std::cout << 0 << endl;
			return;
		}
		int s = 1, t = 0;
		auto dfs3 = [&](auto self, int u, int last) -> int {
			for (auto v : e[u]) {
				if (v == last) continue;
				if (val[v] * 2 < val[u]) {
					s = v;
					t = u;
					ans = size[v];
				}
				self(self, v, u);
			}
			return 0;
		};
		dfs3(dfs3, 1, 0);
		// std::cout << s << ' ' << t << endl;
		auto dfs4 = [&](auto self, int u, int last) -> int {
			for (auto v : e[u]) {
				if (v == last) continue;
				if (val[u] * 2 < val[v]) {
					ans -= size[v];
				} else {
					self(self, v, u);
				}
			}
			return 0;
		};
		dfs4(dfs4, s, t);
		std::cout << ans << endl;
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