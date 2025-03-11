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
	int n, k;
	std::cin >> n >> k;
	std::vector<std::string> a(5);
	for (int i = 0; i < 5; i++) {
		std::cin >> a[i];
	}
	int c1 = 0, c2 = 0;
	for (int i = 0; i < n; i++) {
		c1 += (a[1][i] == '*') + (a[3][i] == '*');
		c1 += (a[1][i] == '*' && a[0][i] == '*');
		c1 += (a[3][i] == '*' && a[4][i] == '*');
		c2 += (a[1][i] != '*' && a[0][i] == '*');
		c2 += (a[3][i] != '*' && a[4][i] == '*');
	}
	if (c1 >= k) {
		std::cout << k << endl;
	} else {
		std::cout << c1 + std::min(c2, (k - c1) / 2) << endl;
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