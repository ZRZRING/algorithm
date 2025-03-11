#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'

int main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> a(n + 1);
	std::vector<std::vector<int>> b(m + 1);
	for (int i = 1; i <= n; i++) {
		int k;
		std::cin >> k;
		while (k--) {
			int x;
			std::cin >> x;
			a[i].push_back(x);
			b[x].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		std::sort(a[i].begin(), a[i].end());
	}
	int Q;
	std::cin >> Q;
//	std::map<std::pair<int, int>, int> A;
	while (Q--) {
		int x, y, ans = 0;
		std::cin >> x >> y;
//		if (A.find({x, y}) != A.end()) {
//			std::cout << A[{x, y}] << endl;
//			continue;
//		}
		for (auto i : b[x]) {
			int t = std::lower_bound(a[i].begin(), a[i].end(), y) - a[i].begin();
			if (t >= a[i].size()) continue;
			if (a[i][t] == y) {
				ans++;
			}
		}
//		A[{x, y}] = ans;
		std::cout << ans << endl;
	}
}
