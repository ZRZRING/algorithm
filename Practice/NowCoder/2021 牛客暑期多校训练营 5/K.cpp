#include <bits/stdc++.h>

using int64 = long long;

#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int n, Q;
		std::cin >> n >> Q;
		std::vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		while (Q--) {
			int k;
			std::cin >> k;
			std::deque<int> q1, q2;
			q1.push_back(1);
			q2.push_back(1);
			int64 ans = 0;
			for (int l = 1, r = 1; l <= n; l++) {
				if (q1.front() < l) q1.pop_front();
				if (q2.front() < l) q2.pop_front();
				while (r < l || a[q1.front()] - a[q2.front()] <= k) {
					if (r == n) break;
					r++;
					while (!q1.empty() && a[q1.back()] < a[r]) q1.pop_back();
					while (!q2.empty() && a[q2.back()] > a[r]) q2.pop_back();
					q1.push_back(r);
					q2.push_back(r);
				}
				// std::cout << l << ' ' << r << '\n';
				if (a[q1.front()] - a[q2.front()] <= k) {
					break;
				}
				ans += n - r + 1;
			}
			std::cout << ans << '\n';
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