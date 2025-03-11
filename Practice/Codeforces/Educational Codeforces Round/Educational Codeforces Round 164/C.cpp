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
		int n = s.length(), flag = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == t[i]) continue;
			if (!flag) {
				flag = 1;
				if (s[i] < t[i]) std::swap(s[i], t[i]);
			} else {
				if (s[i] > t[i]) std::swap(s[i], t[i]);
			}
		}
		std::cout << s << '\n' << t << '\n';
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