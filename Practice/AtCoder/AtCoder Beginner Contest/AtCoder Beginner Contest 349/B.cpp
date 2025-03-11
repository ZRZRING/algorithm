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
	std::string s;
	std::cin >> s;
	int n = s.length();
	std::vector<int> cnt(26), vis(n + 1);
	for (int i = 0; i < n; i++) {
		cnt[s[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (cnt[i] == 0) continue;
		vis[cnt[i]]++;
		if (vis[cnt[i]] >= 3) return NO;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 1) {
			return NO;
		}
	}
	return YES;
}

int main() {
	Fast_IOS;
	int T = 1;
	// std::cin >> T;
	while (T--) {
		int t = solve();
		if (t == 0) continue;
		if (t == YES) std::cout << "Yes" << endl;
		if (t == NO) std::cout << "No" << endl;
	}
	return 0;
}