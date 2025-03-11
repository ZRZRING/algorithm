#include<bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0)

using int64 = long long;
using ll = long long;

int main() {
	int n;
	std::cin >> n;
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	std::vector b(n + 1, std::vector<int>(n + 1));
	for (int i = 1; i <= n; i++) {
		std::priority_queue<int> q1;
		std::priority_queue<int, std::vector<int>, std::greater<int>> q2;
		for (int j = i; j <= n; j++) {
			if (q1.empty() || a[j] <= q1.top()) {
				q1.push(a[j]);
			} else {
				q2.push(a[j]);
			}
			while (q1.size() > q2.size()) {
				q2.push(q1.top());
				q1.pop();
			}
			while (q2.size() > q1.size()) {
				q1.push(q2.top());
				q2.pop();
			}
			b[i][j] = q1.top();
		}
	}
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= n; j++) {
	// 		std::cout << b[i][j] << " \n"[j == n];
	// 	}
	// }
	auto cal = [&](int n) -> int {
		return (n * (n + 1) / 2 + 1) / 2;
	};
	auto check = [&](int x) -> bool {
		std::vector B(n + 1, std::vector<int>(n + 1));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				B[i][j] = B[i - 1][j] + B[i][j - 1] - B[i - 1][j - 1];
			}
			for (int j = i; j <= n; j++) {
				B[i][j] = (b[i][j] <= x) + B[i - 1][j] + B[i][j - 1] - B[i - 1][j - 1];
			}
		}
		int ans = 0;
		std::vector C(n + 1, std::vector<int>(n + 1));
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				C[i][j] = (B[j][j] - B[j][i - 1] - B[i - 1][j] + B[i - 1][i - 1]) >= cal(j - i + 1);
				ans += (B[j][j] - B[j][i - 1] - B[i - 1][j] + B[i - 1][i - 1]) >= cal(j - i + 1);
			}
		}
		// for (int i = 1; i <= n; i++) {
		// 	for (int j = 1; j <= n; j++) {
		// 		std::cout << C[i][j] << " \n"[j == n];
		// 	}
		// }
		// std::cout << x << ' ' << ans << '\n';
		return ans >= cal(n);
	};
	int l = 0, r = 1e9;
	while (l < r) {
		int mid = l + r >> 1;
		if (check(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	std::cout << r << '\n';
	return 0;
}