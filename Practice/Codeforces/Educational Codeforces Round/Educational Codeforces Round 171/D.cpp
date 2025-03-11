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
		// Fast_IOS;
		// std::cin >> T;
	}

	void solve() {
		int n;
		std::cin >> n;
		std::vector<int64> a(n + 1);

		// a 的前缀和
		std::vector<int64> p(n + 1);
		for (int i = 1; i <= n; i++) {
			p[i] = p[i - 1] + a[i];
		}

		// a 的前缀和的前缀和
		std::vector<int64> pp(n + 1);
		for (int i = 1; i <= n; i++) {
			pp[i] = pp[i - 1] + p[i];
		}

		// a 从 i 开始的前缀和的和
		std::vector<int64> b(n + 1);
		for (int i = 1; i <= n; i++) {
			b[i] += 
		}
	}
};

int main() {
	ICPC icpc;
	while (icpc.T--) {
		icpc.solve();
	}
	return 0;
}