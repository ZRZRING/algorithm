#include <bits/stdc++.h>

using int64 = long long;
using ui64 = unsigned long long;

#define endl '\n'
#define PII std::pair<int64, int64>
#define NO return (void)(std::cout << "NO" << endl)
#define YES return (void)(std::cout << "YES" << endl)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;
const ui64 inf = 1e19 + 8e18;

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
		int n, k = 20;
		std::cin >> n;
		std::vector<ui64> a(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		std::vector<std::vector<int>> e(n + 1);
		for (int i = 1; i < n; i++) {
			int u, v;
			std::cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		std::vector<std::vector<ui64>> f(n + 1, std::vector<ui64>(k + 2));
		std::vector<std::vector<ui64>> pre(n + 1, std::vector<ui64>(k + 2));
		std::vector<std::vector<ui64>> suf(n + 1, std::vector<ui64>(k + 2));
		auto dfs = [&](auto self, int u, int last) -> void {
			for (int i = 1; i <= k; i++) {
				f[u][i] = a[u] * i;
			}
			for (auto v : e[u]) {
				if (v == last) continue;
				self(self, v, u);
				for (int i = 1; i <= k; i++) {
					f[u][i] += std::min(pre[v][i - 1], suf[v][i + 1]);
				}
			}
			pre[u][0] = inf;
			for (int i = 1; i <= k; i++) {
				pre[u][i] = std::min(pre[u][i - 1], f[u][i]);
			}
			suf[u][k + 1] = inf;
			for (int i = k; i >= 1; i--) {
				suf[u][i] = std::min(suf[u][i + 1], f[u][i]);
			}
		};
		dfs(dfs, 1, 1);
		ui64 ans = inf;
		for (int i = 1; i <= k; i++) {
			ans = std::min(ans, f[1][i]);
		}
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