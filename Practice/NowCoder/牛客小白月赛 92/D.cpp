#include <bits/stdc++.h>

using int64 = long long;

#define NO 2
#define YES 1
#define endl '\n'
#define PII std::pair<int64, int64>
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0)
#define debug(x) std::cerr << "In Line " << __LINE__ << " the " << #x << " = " << x << '\n';

const int64 mod = 998244353;

template <class T> void MOD(T &x) {x = (x % mod + mod) % mod;}
template <class T> T lg(T x) {return (T)log10(x);}
template <class T> T log(T x) {return (T)log2(x);}
template <class T> T abs(T x) {return x < 0 ? -x : x;}
template <class T> T mysqrt(T x) {return std::floor(sqrtl(x));}

int solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n + 1), b(n + 1);
	int64 sum = 0, delta = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		sum += a[i];
		delta += (3ll - 2ll * i) * a[i];
	}
	int64 res = 0;
	for (int i = 1; i <= n; i++) {
		res += a[i] * (i - 1ll) * (i - 1ll);
	}
	int64 ans = res;
	for (int i = 1; i <= n; i++) {
		res += delta;
		delta += 2ll * sum;
		ans = std::min(ans, res);
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