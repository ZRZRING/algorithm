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
	int ans = 0, cnt = 0;
	std::vector<int> vis(200);
	for (int i = 0; i < n; i++) {
		if (s[i] == 'g' || s[i] == 'z' || s[i] == 'h' || s[i] == 'u') cnt++;
		vis[s[i]]++;
		ans++;
		if (std::min({vis['g'], vis['z'], vis['h'], vis['u']}) >= 1) {
			i += cnt;
			cnt = 0;
			vis['g'] = 0;
			vis['z'] = 0;
			vis['h'] = 0;
			vis['u'] = 0;
		}
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