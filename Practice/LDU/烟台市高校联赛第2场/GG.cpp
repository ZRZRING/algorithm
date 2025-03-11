#include <bits/stdc++.h>

using int64 = long long;
using A3 = std::array<int64, 3>;

#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

class WORK {
public:
	int N;

	WORK() {}

	int abs(int a) {
		return a < 0 ? -a : a;
	}

	int dis(A3 a, A3 b) {
		return std::min(abs(a[0] - b[0]), abs(a[1] - b[1]));
	}

	void solve() {
		int n;
		std::cin >> n;
		std::vector<A3> p(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> p[i][0] >> p[i][1];
			p[i][2] = i;
		}
		std::vector<A3> p1 = p, p2 = p;
		std::sort(p1.begin() + 1, p1.end(), [](A3 a, A3 b) {
			return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
		});
		std::sort(p2.begin() + 1, p2.end(), [](A3 a, A3 b) {
			return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
		});
		std::vector<A3> e;
		for (int i = 1; i <= n; i++) {
			auto it = std::upper_bound(p1.begin(), p1.end(), p1[i]);
			if (it != p1.end()) e.push_back({dis(p1[i], *it), p1[i][2], it->at(2)});
			it--;
			it--;
			if (it != p1.rend()) e.push_back({dis(p1[i], *it), p1[i][2], it->at(2)});
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