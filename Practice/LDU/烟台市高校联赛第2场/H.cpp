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
		int n = s.length();
		std::vector<int> vis(300);
		for (int i = 0; i < s.length(); i++) {
			vis[s[i]]++;
		}
		int64 ans = 0;
		for (int i = 0; i < s.length(); i++) {
			ans += (n - vis[s[i]]);
		}
		std::cout << ans / 2 << '\n';
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