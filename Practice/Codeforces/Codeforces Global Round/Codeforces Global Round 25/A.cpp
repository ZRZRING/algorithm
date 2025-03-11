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
template <class T> int64 abs(T x) {return x < 0 ? -x : x;}
template <class T> int64 lg(T x) {return (int)log10(x);}
template <class T> int64 log(T x) {return (int)log2(x);}

int solve() {
	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;
	int cnt = 0, cnt1 = s[0] == '1';
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == '1') cnt1++;
		if (s[i] == '1' && s[i - 1] == '1') cnt++;
	}
	if (cnt == 1 && cnt1 == 2 || cnt1 % 2 == 1) {
		std::cout << "NO" << endl;
	} else {
		std::cout << "YES" << endl;
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