#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'
#define PII std::pair<int64, int64>
#define NO return (void)(std::cout << "NO" << endl)
#define YES return (void)(std::cout << "YES" << endl)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

template <class T> T MOD(T &x, T p = mod) {return x = (x % p + p) % p;}
template <class T> T MOD(T &&x, T p = mod) {return x = (x % p + p) % p;}
template <class T> T lg(T x) {return (T)log10(x);}
template <class T> T log(T x) {return (T)log2(x);}
template <class T> T abs(T x) {return x < 0 ? -x : x;}
template <class T> T mysqrt(T x) {return std::floor(sqrtl(x));}

struct DSU {
	int n;

	std::map<int, int> fa;

	int find(int x) {
		return x == fa[x] ? x : fa[x] = find(fa[x]);
	}

	int merge(int x, int y) {
		x = find(x); y = find(y);
		if (x == y) return 0;
		fa[x] = y;
		return 1;
	}
};

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int n, m, Q;
		std::cin >> n >> m >> Q;
		#define A3 std::array<int, 3>
		std::vector<A3> e(m + 1);
		for (int i = 1; i <= m; i++) {
			int u, v, t;
			std::cin >> u >> v >> t;
			e[i] = {u, v, t};
		}
		std::sort(e.begin() + 1, e.end(), [](A3 a, A3 b) {
			return a[2] < b[2];
		});
		std::vector<std::set<int>> s(n + 1);
		std::vector<DSU> qry(Q + 1);
		std::vector<int64> k(Q + 1), cnt(Q + 1), ans(Q + 1);
		for (int i = 1; i <= Q; i++) {
			std::cin >> k[i];
			for (int j = 1; j <= k[i]; j++) {
				int x;
				std::cin >> x;
				s[x].insert(i);
				qry[i].fa[x] = x;
			}
		}
		for (int i = 1; i <= m; i++) {
			auto [u, v, t] = e[i];
			if (s[u].size() > s[v].size()) std::swap(u, v);
			for (auto x : s[u]) {
				if (s[v].count(x) == 1) {
					if (qry[x].merge(u, v)) {
						cnt[x]++;
						ans[x] += t;
					}
				}
			}
		}
		for (int i = 1; i <= Q; i++) {
			if (cnt[i] != k[i] - 1) {
				std::cout << -1 << endl;
			} else {
				std::cout << ans[i] << endl;
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