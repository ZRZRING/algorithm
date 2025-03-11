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
		std::vector<int> a(n + 1), b(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			std::cin >> b[i];
		}
		std::vector<int> prea(n + 2), preb(n + 2);
		for (int i = 1; i <= n; i++) {
			prea[i] = std::gcd(prea[i - 1], a[i]);
			preb[i] = std::gcd(preb[i - 1], b[i]);
		}
		std::vector<int> sufa(n + 2), sufb(n + 2);
		for (int i = n; i >= 1; i--) {
			sufa[i] = std::gcd(sufa[i + 1], a[i]);
			sufb[i] = std::gcd(sufb[i + 1], b[i]);
		}
		std::vector<A2> a1, b1;
		a1.push_back({0, 1});
		b1.push_back({0, 1});
		for (int i = 1; i <= n; i++) {
			if (prea[i] != prea[i + 1]) {
				a1.push_back({prea[i], i + 1});
			}
			if (preb[i] != preb[i + 1]) {
				b1.push_back({preb[i], i + 1});
			}
		}
		// for (auto [x, y] : a1) std::cout << x << ' '; std::cout << '\n';
		// for (auto [x, y] : b1) std::cout << x << ' '; std::cout << '\n';
		int64 ans = 0, cnt = 0;
		std::vector<A2> a2, b2;
		a2.push_back({0, 1});
		b2.push_back({0, 1});
		for (int r = 1; r <= n; r++) {
			for (int i = 0; i < a2.size(); i++) {
				a2[i][0] = std::gcd(a[r], a2[i][0]);
			}
			a2.push_back({0, r + 1});
			int k = 0;
			for (int i = 1; i < a2.size(); i++) {
				if (a2[i][0] != a2[i - 1][0]) {
					k++;
				}
				a2[k] = a2[i];
			}
			a2.resize(k + 1);

			for (int i = 0; i < b2.size(); i++) {
				b2[i][0] = std::gcd(b[r], b2[i][0]);
			}
			b2.push_back({0, r + 1});
			k = 0;
			for (int i = 1; i < b2.size(); i++) {
				if (b2[i][0] != b2[i - 1][0]) {
					k++;
				}
				b2[k] = b2[i];
			}
			b2.resize(k + 1);

			// for (auto [x, y] : a2) std::cout << x << ' '; std::cout << '\n';
			// for (auto [x, y] : b2) std::cout << x << ' '; std::cout << '\n';
			auto ita1 = a1.begin(), ita2 = a2.begin();
			auto itb1 = b1.begin(), itb2 = b2.begin();
			// std::cout << "r: " << r << '\n';
			auto get = [&]() -> int {
				// std::cout << ita1->at(0) << ' ';
				// std::cout << ita2->at(0) << ' ';
				// std::cout << itb1->at(0) << ' ';
				// std::cout << itb2->at(0) << '\n';
				return std::min({ita1->at(1), ita2->at(1), itb1->at(1), itb2->at(1)});
			};
			int i, j;
			for (i = get(), j = 0; i <= r; j = i, i = get()) {
				int res = 0;
				// std::cout << ita1->at(1) << ' ' << ita2->at(1) << ' ' << sufa[r + 1] << '\n';
				// std::cout << itb1->at(1) << ' ' << itb2->at(1) << ' ' << sufb[r + 1] << '\n';
				res += std::gcd(ita1->at(0), std::gcd(itb2->at(0), sufa[r + 1]));
				res += std::gcd(itb1->at(0), std::gcd(ita2->at(0), sufb[r + 1]));
				// std::cout << res << '\n';
				if (res > ans) {
					ans = res;
					cnt = i - j;
				} else if (res == ans) {
					cnt += i - j;
				}
				if (ita1->at(1) == i) ita1++;
				if (ita2->at(1) == i) ita2++;
				if (itb1->at(1) == i) itb1++;
				if (itb2->at(1) == i) itb2++;
			}
		}
		std::cout << ans << ' ' << cnt << '\n';
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