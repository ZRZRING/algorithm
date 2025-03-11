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
		int n, m, rev = 0;
		std::cin >> n >> m;
		if (n * (n + 1) % 4 != 0 && m * (m + 1) % 4 != 0) {
			return (void)(std::cout << "No\n");
		}
		std::cout << "Yes\n";
		if (n * (n + 1) % 4 != 0) {
			std::swap(n, m);
			rev = 1;
		}
		int flag = 0;
		std::vector<int> ans;
		int64 t1 = 1ll * n * (n + 1) / 4;
		int t2 = n, j = n;
		while (t1) {
			while (t1 - 1ll * j * (j + 1) / 2 < 1ll * t2 - j) j--;
			ans.push_back(j);
			t1 -= 1ll * j * (j + 1) / 2;
			t2 -= j;
		}
		std::vector<int> res;
		j = 0;
		for (auto x : ans) {
			// std::cout << x << ' ';
			j ^= 1;
			for (int i = 0; i < x; i++) {
				res.push_back(j);
			}
		}
		// std::cout << '\n';
		if (rev) {
			for (int i = 0; i < m; i++) {
				for (auto x : res) {
					std::cout << x << ' ';
				}
				std::cout << '\n';
			}
		} else {
			for (auto x : res) {
				for (int i = 0; i < m; i++) {
					std::cout << x << ' ';
				}
				std::cout << '\n';
			}
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