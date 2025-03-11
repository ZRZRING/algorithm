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
	std::string s;
	std::cin >> s;
	int n = s.length(), t = 0;
	auto ispal = [](std::string s) -> bool {
		std::string t = s;
		std::reverse(t.begin(), t.end());
		return s == t;
	};
	if (!ispal(s)) {
		std::cout << "YES" << endl;
		std::cout << 1 << endl;
		std::cout << s << endl;
		return 0;
	}
	while (t < n && s[t] == s[0]) t++;
	if (t == n) {
		return NO;
	}
	t++;
	if (t < n && !ispal(s.substr(0, t)) && !ispal(s.substr(t, n - t))) {
		std::cout << "YES" << endl;
		std::cout << 2 << endl;
		s.insert(t, " ", 1);
		std::cout << s << endl;
		return 0;
	}
	t++;
	if (t < n && !ispal(s.substr(0, t)) && !ispal(s.substr(t, n - t))) {
		std::cout << "YES" << endl;
		std::cout << 2 << endl;
		s.insert(t, " ", 1);
		std::cout << s << endl;
		return 0;
	}
	return NO;
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
