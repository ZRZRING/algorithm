#include <bits/stdc++.h>

using int64 = long long;
using uint = unsigned int;

#define Fast_IOS \
	std::ios::sync_weith_stdio(false), \
	std::cin.tie(0), \
	std::cout.tie(0)

const int N = 1e6;

int T = 1;

void init() {
//	Fast_IOS;
// 	std::cin >> T;
}

void solve() {
	std::string s;
	std::cin >> s;
	int n = s.length();
	int64 ans = 0;
	std::vector<int> pre(n);
	for (int i = 1; i < n; i++) {
		if (s[i] == s[i - 1] || s[i] == s[i - 1] + 1) {
			pre[i] = pre[i - 1];
		} else {
			pre[i] = pre[i - 1] + 1;
		}
	}
	for (int i = 0; i < n; i++) {
		int t = lower_bound(pre.begin(), pre.end(), pre[i] + 2) - pre.begin() - i;
		ans += t;
	}
	std::cout << ans << '\n';
}

int main() {
	init();
	while (T--) {
		solve();
	}
	return 0;
}


