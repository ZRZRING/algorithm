#include <bits/stdc++.h>

using int64 = long long;

#define NO 2
#define YES 1
#define endl '\n'
#define PII std::pair<int64, int64>
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0)
#define debug(x) std::cerr << "In Line " << __LINE__ << " the " << #x << " = " << x << '\n';

const int64 mod = 1e9 + 7;

template <class T> void MOD(T &x) {x = x % mod;}
template <class T> int64 lg(T x) {return (int)log10(x);}
template <class T> int64 log(T x) {return (int)log2(x);}
template <class T> int64 abs(T x) {return x < 0 ? -x : x;}
template <class T> int64 mysqrt(T x) {return std::floor(sqrtl(x));}

int solve() {
	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y;
		std::cin >> x >> y;
		if (x == y) {
			n--;
		} else {
			n -= 2;
		}
	}
	if (n == 0) {
		std::cout << 1 << endl;
		return 0;
	}
	std::vector<int64> f(n + 1);
	f[0] = f[1] = 1;
	for (int i = 2; i <= n; i++) {
		f[i] = (2ll * (i - 1) * f[i - 2] + f[i - 1]) % mod;
	}
	std::cout << f[n] << endl;
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