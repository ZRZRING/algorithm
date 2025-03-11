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
	int n, m;
	std::cin >> n >> m;
    std::vector<std::vector<int>> e(n + 1);
    bool vis[n + 1] = {0};
    for (int i = 1; i <= m; i++) {
		int x;
		std::cin >> x;
        vis[x] = 1;
	}
    for (int i = 1; i < n; i++) {
        int u, v;
		std::cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    std::vector<int> dep(n + 1), cnt(n + 1);
    std::function<int(int, int, int)> dfs = [&](int u, int last, int t) -> int {
        dep[u] = dep[last] + 1;
        int t = dep[u];
        for (auto v : e[u]) {
            if (v == last) continue;
            t = std::max(t, dfs(v, last, t));
        }
        return t;
    };
    for (auto i : e[1]) {
        int t = dfs(i, 1, 1);
        for (int i = 1; i <= t; i++) {
            cnt[i] = 0;
        }
    }
	return 0;
}

int main() {
	Fast_IOS;
	int T = 1;
	// std::cin >> T;
	while (T--) {
		int t = solve();
		if (t == 0) continue;
		if (t == YES) std::cout << "YES" << endl;
		if (t == NO) std::cout << "NO" << endl;
	}
	return 0;
}