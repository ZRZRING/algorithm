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
	int n, k, c = 1;
	std::cin >> n >> k;
	if (n == 1) {
		std::cout << k << endl;
		return 0;
	}
	n -= 2;
	int ans = 0;
	while ((1 << c) - 1 < k) ans = (1 << c) - 1, c++;
	std::cout << ans << ' ' << k - ans << ' ';
	while (n--) std::cout << 0 << ' ';
	std::cout << endl;
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