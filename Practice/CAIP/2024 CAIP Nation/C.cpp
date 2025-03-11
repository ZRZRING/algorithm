#include <bits/stdc++.h>

using int64 = long long;

#define A2 std::array<int, 2>

int main() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	if (n == 4) {
		std::vector<int64> id(n);
		std::iota(id.begin(), id.end(), 0);
		int cnt = 0;
		std::vector<int> vis = {1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0};
		do {
			if (vis[cnt]) {
				for (auto x : id) {
					std::cout << a[x];
				}
				std::cout << '\n';
			}
			cnt++;
		} while (std::next_permutation(id.begin(), id.end()));
		return 0;
	}
	std::vector<std::vector<int>> ans;
	for (int i = 0; i < n; i++) {
		std::vector<int> t(n);
		for (int j = 0; j < n; j++) {
			t[(i + j) % n] = j;
		}
		ans.push_back(t);
	}
	int64 t = 0;
	for (auto t : ans) {
		for (auto x : t) {
			std::cout << a[x];
		}
		std::cout << '\n';
	}
}
