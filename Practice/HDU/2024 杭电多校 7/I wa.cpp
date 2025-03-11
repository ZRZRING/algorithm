#include <bits/stdc++.h>

using int64 = long long;

#define A2 std::array<int64, 2>
#define lowbit(x) ((x) & -(x))
#define NO return (void)(std::cout << "NO" << endl)
#define YES return (void)(std::cout << "YES" << endl)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353, UP = 1e9 + 1;

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
		int n, k;
		std::cin >> n >> k;
		std::vector<int> time(n + 1);
		std::vector<std::vector<A2>> e(n + 1);
		for (int i = 1; i <= n; i++) {
			int opt;
			std::cin >> opt;
			if (opt == 1) {
				int k;
				std::cin >> k;
				for (int j = 1; j <= k; j++) {
					int t, x;
					std::cin >> t >> x;
					e[i].push_back({x, t});
					e[x].push_back({i, t});
				}
			} else {
				std::cin >> time[i];
			}
		}
		std::vector<int64> cnt(n + 1), res(n + 1);
		cnt[k] = 1;
		auto dfs = [&](auto self, int u, int last) -> void {
			if (e[u].size() == 1) {
				res[u] = std::min(UP, cnt[u] * time[u]);
				return;
			}
			for (auto [v, t] : e[u]) {
				if (v == last || t == 0) continue;
				cnt[v] = std::min(UP, cnt[u] * t);
				self(self, v, u);
				res[u] += res[v];
			}
		};
		dfs(dfs, k, k);
		int64 max = 0;
		for (auto [v, t] : e[k]) {
			std::cout << res[v] << ' ';
			if (res[v] > res[max]) max = v;
		}
		std::cout << '\n';
		for (auto &[v, t] : e[k]) {
			if (v == max) t = 0;
		}
		cnt.clear();
		res.clear();
		cnt.resize(n + 1);
		res.resize(n + 1);
		cnt[k] = 1;
		dfs(dfs, k, k);
		if (res[k] > 1e9) {
			std::cout << "Impossible\n";
		} else {
			std::cout << res[k] << '\n';
		}
	}
};

int main() {
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	Fast_IOS;
	WORK work;
	int T = 1;
	std::cin >> T;
	while (T--) {
		work.solve();
	}
	return 0;
}