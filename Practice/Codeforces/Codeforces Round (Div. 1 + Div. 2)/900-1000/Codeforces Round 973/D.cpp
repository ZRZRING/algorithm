#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

using P = std::pair<int, int>;

#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int n;
		std::cin >> n;
		std::vector<int64> a(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		std::stack<A2> s;
		s.push({a[1], 1});
		for (int i = 2; i <= n; i++) {
			int64 sum = a[i], cnt = 1;
			auto [x, y] = s.top();
			while (!s.empty() && sum / cnt <= x) {
				s.pop();
				sum += x * y;
				cnt += y;
				if (!s.empty()) {
					x = s.top().at(0);
					y = s.top().at(1);
				}
			}
			if (sum % cnt == 0) {
				s.push({sum / cnt, cnt});
			} else {
				s.push({sum / cnt + 1, sum % cnt});
				s.push({sum / cnt, cnt - sum % cnt});
			}
			// auto a = s;
			// std::cout << "-------\n";
			// while (!a.empty()) {
			// 	auto [x, y] = a.top();
			// 	a.pop();
			// 	std::cout << x << ' ' << y << '\n';
			// }
			// std::cout << "-------\n";
		}
		int64 max = s.top().at(0), min = s.top().at(0);
		while (!s.empty()) {
			min = std::min(min, s.top().at(0));
			max = std::max(max, s.top().at(0));
			s.pop();
		}
		std::cout << max - min << '\n';
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