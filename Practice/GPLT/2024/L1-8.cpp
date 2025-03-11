#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'

int solve() {
	std::vector<std::vector<int>> a(10, std::vector<int>(10));
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			std::cin >> a[i][j];
		}
	}
	for (int i = 0; i < 9; i++) {
		std::vector<int> vis(10);
		for (int j = 0; j < 9; j++) {
			if (a[i][j] > 9 || a[i][j] < 1 || vis[a[i][j]]) return 0;
			vis[a[i][j]] = 1;
		}
	}
	for (int i = 0; i < 9; i++) {
		std::vector<int> vis(10);
		for (int j = 0; j < 9; j++) {
			if (a[j][i] > 9 || a[j][i] < 1 || vis[a[j][i]]) return 0;
			vis[a[j][i]] = 1;
		}
	}
	for (int k = 0; k < 9; k++) {
		std::vector<int> vis(10);
		int X = k / 3 * 3, Y = k % 3 * 3;
		for (int i = X; i < X + 3; i++) {
			for (int j = Y; j < Y + 3; j++) {
				if (a[i][j] > 9 || a[i][j] < 1 || vis[a[i][j]]) return 0;
				vis[a[i][j]] = 1;
			}
		}
	}
	return 1;
}

int main() {
	int T;
	std::cin >> T;
	while (T--) {
		std::cout << solve() << endl;
	}
}
