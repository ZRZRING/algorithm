#include <bits/stdc++.h>

using int64 = long long;

#define A2 std::array<int, 2>

int main() {
	int T, n = 30;
	std::cin >> T;
	std::vector<A2> ans(n + 1);
	std::vector<int> dic = {0, 25, 21, 18, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	std::vector<int> vis(n + 1), score(n + 1);
	while (T--) {
		for (int i = 1; i <= 20; i++) {
			int x, y;
			std::cin >> x >> y;
			vis[x] = 1;
			score[x] += dic[y];
		}
	}
	for (int i = 1; i <= 30; i++) {
		ans[i] = {score[i], i};
	}
	std::sort(ans.begin() + 1, ans.end(), [](A2 a, A2 b) {
		return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
	});
	for (int i = 1; i <= 30; i++) {
		if (!vis[ans[i][1]]) continue;
		std::cout << ans[i][1] << ' ' << ans[i][0] << '\n';
	}
}
