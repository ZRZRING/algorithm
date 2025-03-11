#include <bits/stdc++.h>

using int64 = long long;

#define NO 2
#define YES 1
#define endl '\n'
#define PII std::pair<int64, int64>
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0)
#define debug(x) std::cerr << "In Line " << __LINE__ << " the " << #x << " = " << x << '\n';

const int64 mod = 998244353;

template <class T> void MOD(T &x) {x = x % mod;}
template <class T> int64 lg(T x) {return (int)log10(x);}
template <class T> int64 log(T x) {return (int)log2(x);}
template <class T> int64 abs(T x) {return x < 0 ? -x : x;}
template <class T> int64 mysqrt(T x) {return std::floor(sqrtl(x));}

int solve() {
	int n, K;
	std::cin >> n >> K;
	std::vector<std::vector<int>> e(n + 1);
	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	std::vector<int> size(n + 1);
	if (K < 400) {
		std::vector<int> g(K + 2);
		std::vector<std::vector<int>> f(n + 1, std::vector<int>(K + 2));
		auto dfs1 = [&](auto self, int u, int last) -> void {
			size[u] = 1;
			f[u][1] = 1;
			for (auto v : e[u]) {
				if (v == last) continue;
				self(self, v, u);
				g.clear();
				g.resize(K + 2);
				for (int i = std::min(K + 1, size[u]); i >= 1; i--) {
					for (int j = 0; j <= std::min(K + 1, size[v]); j++) {
						if (i + j > K + 1) continue;
						MOD(g[i + j] += 1ll * f[u][i] * f[v][j] % mod);
					}
				}
				f[u].swap(g);
				size[u] += size[v];
			}
			f[u][0] = (f[u][K] + f[u][K + 1]) % mod;
		};
		dfs1(dfs1, 1, 1);
		std::cout << f[1][0] << endl;
	} else {
		std::unordered_map<int, int> g(n + 1);
		std::vector<std::unordered_map<int, int>> f(n + 1);
		auto dfs2 = [&](auto self, int u, int last) -> void {
			size[u] = 1;
			f[u][1] = 1;
			for (auto v : e[u]) {
				if (v == last) continue;
				self(self, v, u);
				g.clear();
				for (auto x : f[u]) {
					for (auto y : f[v]) {
						if (x.first + y.first > K + 1) continue;
						MOD(g[x.first + y.first] += 1ll * x.second * y.second % mod);
					}
				}
				f[u].swap(g);
				size[u] += size[v];
			}
			f[u][0] = (f[u][K] + f[u][K + 1]) % mod;
			if (f[u][0] == 0) f[u].erase(0);
			if (f[u][K] == 0) f[u].erase(K);
			if (f[u][K + 1] == 0) f[u].erase(K + 1);
			for (auto v : e[u]) {
				if (v == last) continue;
				f[v].clear();
			}
		};
		dfs2(dfs2, 1, 1);
		std::cout << f[1][0] << endl;
	}
	return 0;
}

int main() {
	Fast_IOS;
	int T = 1;
	std::cin >> T;
	while (T--) {
		int t = solve();
		if (t == 0) continue;
		if (t == YES) std::cout << "YES" << endl;
		if (t == NO) std::cout << "NO" << endl;
	}
	return 0;
}