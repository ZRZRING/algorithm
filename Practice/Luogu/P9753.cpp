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
	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;
	s = " " + s;
	std::vector<int> last(n + 1), f(n + 1);
	std::iota(last.begin(), last.end(), 0);
	for (int i = 1; i <= n; i++) {
		int j = i;
		while (j && s[j - 1] != s[i] && last[j - 1] != j - 1) {
			j = last[j - 1];
		}
		if (s[j - 1] == s[i]) {
			last[i] = j - 1;
			f[i] = f[last[i] - 1] + 1;
		}
		// std::cout << i << ' ' << last[i] << ' ' << f[i] << endl;
	}
	int64 ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += f[i];
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