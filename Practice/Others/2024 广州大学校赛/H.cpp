#include <bits/stdc++.h>

using int64 = long long;

#define NO 2
#define YES 1
#define endl '\n'
#define lg(x) ((int)log10(x))
#define log(x) ((int)log2(x))
#define PII std::pair<int64, int64>
#define abs(x) ((x) < 0 ? -(x) : (x))
#define MOD(x) ((x) = ((x) % mod + mod) % mod)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0)
#define debug(x) std::cerr << "In Line " << __LINE__ << " the " << #x << " = " << x << '\n';

const int64 mod = 998244353;

int solve() {
	std::string s = "a4b6ccdde3ffg9hhiijjkkl1mmnno0ppqqrrs5t7uuvvwwxxyyz2";
	std::map<char, char> map;
	for (int i = 0; i < s.length(); i += 2) {
		map[s[i + 1]] = s[i];
	}
	std::getline(std::cin, s);
	for (int i = 0; i < s.length(); i++) {
		if (map.find(s[i]) == map.end()) continue;
		s[i] = map[s[i]];
	}
	std::cout << s << endl;
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