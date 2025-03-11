#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

class WORK {
public:
	int N;

	WORK() {}
	
	bool check(std::string s, char a, char b) {
		int n = s.length();
		std::string ans(n, ' ');
		ans[0] = a;
		ans[1] = b;
		for (int i = 1; i <= n - 2; i++) {
			int64 kind = (ans[i] == 'S') ^ (s[i] == 'o') ^ (ans[i - 1] == 'S');
			ans[i + 1] = (kind ? 'S' : 'W');
		}
		int64 kind;
		kind = (ans[n - 1] == 'S') ^ (s[n - 1] == 'o') ^ (ans[n - 2] == 'S');
		if (ans[0] != (kind ? 'S' : 'W')) {
			return 0;
		}
		kind = (ans[0] == 'S') ^ (s[0] == 'o') ^ (ans[n - 1] == 'S');
		if (ans[1] != (kind ? 'S' : 'W')) {
			return 0;
		}
		std::cout << ans << '\n';
		return 1;
	}

	void solve() {
		int n;
		std::cin >> n;
		std::string s;
		std::cin >> s;
		if (check(s, 'S', 'S')) return;
		if (check(s, 'W', 'S')) return;
		if (check(s, 'S', 'W')) return;
		if (check(s, 'W', 'W')) return;
		std::cout << -1 << '\n';
	}
};

int main() {
	Fast_IOS;
	WORK work;
	int T = 1;
	// std::cin >> T;
	while (T--) {
		work.solve();
	}
	return 0;
}