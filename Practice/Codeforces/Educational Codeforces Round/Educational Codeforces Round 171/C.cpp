#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS \
	std::ios::sync_with_stdio(false), \
	std::cin.tie(0), \
	std::cout.tie(0)

const int64 mod = 998244353;

class ICPC {
public:
	int N, T = 1;

	ICPC() {
		Fast_IOS;
		std::cin >> T;
	}

	void solve() {
		int n;
		std::cin >> n;
		std::string s;
		std::cin >> s;
		s = " " + s;
		std::deque<int> q;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i] == '1') {
				q.push_back(i);
				cnt--;
			} else {
				cnt++;
			}
			while (cnt < 0) {
				s[q.front()] = '0';
				q.pop_front();
				cnt += 2;
			}
		}
		int64 ans = 0;
		for (int i = 1; i <= n; i++) {
			ans += (s[i] == '0') * i;
		}
		std::cout << ans << '\n';
	}
};

int main() {
	ICPC icpc;
	while (icpc.T--) {
		icpc.solve();
	}
	return 0;
}