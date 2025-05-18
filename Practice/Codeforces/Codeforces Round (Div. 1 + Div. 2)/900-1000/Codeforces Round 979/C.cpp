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
		int n;
		std::cin >> n;
		std::string s;
		std::cin >> s;
		bool flag = 0;
		for (int i = 1; i < s.length(); i++) {
			if (s[i - 1] == '1' && s[i] == '1') flag = 1;
		}
		if (s[0] == '1' || s[n - 1] == '1') flag = 1;
		std::cout << (flag ? "YES" : "NO") << '\n';
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