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
	std::string s, t;
	std::cin >> s >> t;
	for (auto &x : t) {
		x = std::tolower(x);
	}
	int n = s.length(), m = t.length(), flag = 0;
	for (int i = 0, j = 0; i < n; i++) {
		if (s[i] == t[j]) j++;
		if (j == 3 || j == 2 && t[j] == 'x') {
			flag = 1;
			break;
		}
	}
	if (flag) return YES;
	else return NO;
}

int main() {
	Fast_IOS;
	int T = 1;
	// std::cin >> T;
	while (T--) {
		int t = solve();
		if (t == 2) continue;
		if (t == YES) std::cout << "Yes" << endl;
		if (t == NO) std::cout << "No" << endl;
	}
	return 0;
}