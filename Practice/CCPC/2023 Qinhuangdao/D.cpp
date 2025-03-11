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
		int n, m;
		std::cin >> n >> m;
		std::vector<int64> a(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		#define A2 std::array<int64, 2>
		std::vector<A2> tck(m + 1);
		for (int i = 1; i <= m; i++) {
			std::cin >> tck[i][0] >> tck[i][1];
		}
		std::sort(tck.begin() + 1, tck.end());
		std::priority_queue<A2, std::vector<A2>, std::greater<A2>> q;
		for (int i = 1, j = 0; i <= m; i++) {
			while (j < tck[i][0]) {
				j++;
				q.push({a[j], j});
			}
			auto [x, y] = q.top();
			q.pop();
			a[y] = x - tck[i][1];
			q.push({x - tck[i][1], y});
		}
		std::sort(a.begin() + 1, a.end());
		int64 ans = 0;
		for (int i = 1; i <= n; i++) {
			ans += a[i];
			std::cout << ans << " \n"[i == n];
		}
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