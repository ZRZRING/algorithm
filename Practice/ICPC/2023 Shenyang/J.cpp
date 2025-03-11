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
		if (n == 2) {
			std::cout << "Bob\n";
			return;
		}
		std::vector<int> d(n + 1);
		for (int i = 1; i < n; i++) {
			int u, v;
			std::cin >> u >> v;
			d[u]++;
			d[v]++;
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (d[i] == 1) cnt++;
		}
		if ((n - cnt) % 2 == 1) {
			std::cout << "Bob\n";
		} else {
			std::cout << "Alice\n";
		}
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