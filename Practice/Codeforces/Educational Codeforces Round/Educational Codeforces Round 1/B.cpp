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
		std::string s;
		std::cin >> s;
		int n = s.length(), m;
		std::cin >> m;
		for (int i = 1; i <= m; i++) {
			std::string t = s;
			int l, r, k;
			std::cin >> l >> r >> k;
			l--;
			k %= r - l;
			for (int j = l; j < r; j++) {
				t[j] = s[(j - l - k + r - l) % (r - l) + l];
			}
			s = t;
		}
		std::cout << s << '\n';
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