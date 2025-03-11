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
		int cnt = 0;
		for (int i = 1; i <= 2 * n; i++) {
			int x;
			std::cin >> x;
			cnt += x;
		}
		std::cout << cnt - n << ' ' << std::min(cnt, n) << '\n';
	}
};

int main() {
	ICPC icpc;
	while (icpc.T--) {
		icpc.solve();
	}
	return 0;
}