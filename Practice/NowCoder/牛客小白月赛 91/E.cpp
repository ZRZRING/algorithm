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
	std::string s;
	std::cin >> s;
	s = " " + s;
	std::vector<std::vector<int>> f(n + 2, std::vector<int>(26, n + 1));
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < 26; j++) {
			f[i][j] = f[i + 1][j];
		}
		f[i][s[i + 1] - 'A'] = i + 1;
	}
	std::string ac = "ACCEPT", wa = "WA";
	int64 ans = 0;
	for (int i = 1; i <= n; i++) {
		int t1 = i - 1, t2 = i - 1;
		for (int j = 0; j < 6; j++) {
			t1 = f[t1][ac[j] - 'A'];
		}
		for (int j = 0; j < 2; j++) {
			t2 = f[t2][wa[j] - 'A'];
		}
		ans += std::max(0, t2 - std::max(i + k - 1, t1));
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