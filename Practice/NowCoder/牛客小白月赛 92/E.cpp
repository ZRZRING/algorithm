#include <bits/stdc++.h>

using int64 = long long;

#define NO 2
#define YES 1
#define endl '\n'
#define PII std::pair<int64, int64>
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0)
#define debug(x) std::cerr << "In Line " << __LINE__ << " the " << #x << " = " << x << '\n';

const int64 mod = 998244353, inf = 1e15;

template <class T> void MOD(T &x) {x = (x % mod + mod) % mod;}
template <class T> T lg(T x) {return (T)log10(x);}
template <class T> T log(T x) {return (T)log2(x);}
template <class T> T abs(T x) {return x < 0 ? -x : x;}
template <class T> T mysqrt(T x) {return std::floor(sqrtl(x));}

int solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int64> x(n + 1), y(n + 1);
	int64 ans = inf;
	for (int i = 1; i <= n; i++) {
		std::cin >> x[i] >> y[i];
		if (x[i] >= m) ans = std::min(ans, y[i]);
		if (2 * x[i] >= m) ans = std::min(ans, y[i] / 2ll);
	}
	std::vector<std::vector<int64>> f(2 * m + 1, std::vector<int64>(2, inf));
	f[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 2 * m; j >= 0; j--) {
			if (j - x[i] >= 0) {
				f[j][0] = std::min(f[j][0], f[j - x[i]][0] + y[i]);
				f[j][1] = std::min(f[j][1], f[j - x[i]][1] + y[i]);
			}
			if (j - 2 * x[i] >= 0) {
				f[j][1] = std::min(f[j][1], f[j - 2 * x[i]][0] + y[i] / 2);
			}
		}
	}
	for (int i = m; i <= 2 * m; i++) {
		ans = std::min({ans, f[i][0], f[i][1]});
	}
	std::cout << ans << endl;
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