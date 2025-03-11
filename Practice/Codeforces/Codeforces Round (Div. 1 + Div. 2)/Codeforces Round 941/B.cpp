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
	int n, m;
	std::cin >> n >> m;
	std::vector s(n + 1, std::string());
	for (int i = 1; i <= n; i++) {
		std::cin >> s[i];
		s[i] = " " + s[i];
	}
	int cnt0 = 0, cnt1 = 0;
	for (int i = 1; i <= n; i++) {
		cnt0 |= (s[i][1] == 'W');
		cnt1 |= (s[i][1] == 'B');
	}
	for (int i = 1; i <= n; i++) {
		cnt0 |= (s[i][m] == 'W') * 2;
		cnt1 |= (s[i][m] == 'B') * 2;
	}
	for (int i = 1; i <= m; i++) {
		cnt0 |= (s[1][i] == 'W') * 4;
		cnt1 |= (s[1][i] == 'B') * 4;
	}
	for (int i = 1; i <= m; i++) {
		cnt0 |= (s[n][i] == 'W') * 8;
		cnt1 |= (s[n][i] == 'B') * 8;
	}
	if (cnt0 == 15 || cnt1 == 15) {
		return YES;
	} else {
		return NO;
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