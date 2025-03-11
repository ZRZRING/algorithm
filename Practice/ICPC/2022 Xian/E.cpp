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
		int64 L, R;
		std::cin >> L >> R;
		std::vector<int> l, r;
		int64 ans = 0, ansr = 0;
		while (R) {
			r.push_back(R % 3);
			ansr += R % 3;
			R /= 3;
		}
		while (l.size() < r.size()) {
			l.push_back(L % 3);
			L /= 3;
		}
		int64 res = 0, flag = 0;
		for (int i = r.size() - 1; i >= 0; i--) {
			if (r[i] == 0) continue;
			if (flag || l[i] != r[i]) {
				flag = 1;
				ans = std::max(ans, res + r[i] - 1 + i * 2 - (i == r.size() - 1 && r[i] == 1));
			}
			res += r[i];
		}
		std::cout << std::max(ans + r.size(), ansr + r.size()) << '\n';
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