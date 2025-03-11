#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		std::string s, t;
		std::cin >> s >> t;
		int n = s.length(), m = t.length(), ans = n + m;
		for (int i = 0; i < std::min(n, m); i++) {
			if (s[i] == t[i]) ans--;
			else break;
		}
		std::cout << ans + (ans != n + m) << '\n';
	}
};

int main() {
	Fast_IOS;
	WORK work;
	int T = 1;
	std::cin >> T;
	while (T--) {
		work.solve();
	}
	return 0;
}