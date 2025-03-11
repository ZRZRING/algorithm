#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

template <class T>
T MOD(T& x, int64 p = mod) {
	return x = (x % p + p) % p;
}
template <class T>
T MOD(T&& x, int64 p = mod) {
	return x = (x % p + p) % p;
}

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int n;
		std::cin >> n;
		std::vector e(n + 1, std::vector<int>());
		for (int v = 2; v <= n; v++) {
			int u;
			std::cin >> u;
			e[u].push_back(v);
		}
		std::vector<A2> f(n + 1);
		auto dfs = [&](auto self, int u) -> void {
			f[u][0] = f[u][1] = 1;
			for (auto v : e[u]) {
				self(self, v);
				MOD(f[u][0] *= f[v][0] + f[v][1]);
				MOD(f[u][1] *= f[v][0]);
			}
		};
		dfs(dfs, 1);
		std::cout << MOD(f[1][0] + f[1][1]) << '\n';
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