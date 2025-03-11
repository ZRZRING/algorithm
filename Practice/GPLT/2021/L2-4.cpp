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
	for (int i = 1; i <= n; i++) {
		int c;
		std::cin >> c;
		while (c--) {
			int x;
			std::cin >> x;
			e[i].push_back(x);
		}
	}
	int u = 1;
	std::map<int, int> mp;
	while (m--) {
		int opt, x;
		std::cin >> opt >> x;
		if (opt == 0) {
			u = e[u][x - 1];
		}
		if (opt == 1) {
			std::cout << u << endl;
			mp[x] = u;
		}
		if (opt == 2) {
			u = mp[x];
		}
	}
	std::cout << u << endl;
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