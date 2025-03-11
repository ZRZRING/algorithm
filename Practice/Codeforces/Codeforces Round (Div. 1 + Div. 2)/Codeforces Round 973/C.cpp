#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

class WORK {
public:
	int N;

	WORK() {}

	int ask(std::string s) {
		std::cout << "? " << s << std::endl;
		int x;
		std::cin >> x;
		return x;
	}

	void solve() {
		int n;
		std::cin >> n;
		std::string s;
		int flag = 0;
		while (s.length() < n) {
			s = s + "0";
			if (!ask(s)) {
				s.pop_back();
				s = s + "1";
				if (!ask(s)) {
					s.pop_back();
					flag = 1;
					break;
				}
			}
		}
		if (flag) {
			while (s.length() < n) {
				s = "0" + s;
				if (!ask(s)) {
					s.erase(0, 1);
					s = "1" + s;
				}
			}
		}
		std::cout << "! " << s << std::endl;
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