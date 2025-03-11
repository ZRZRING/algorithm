#include <bits/stdc++.h>

#define endl '\n'
#define int64 long long

const int gox[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int goy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::string> a(n + 2);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		a[i] = "." + a[i] + ".";
	}
	for (int i = 0; i <= n + 1; i++) {
		a[0].push_back('.');
		a[n + 1].push_back('.');
	}
	std::vector<std::vector<int>> vis(n + 2, std::vector<int>(m + 2));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == 'w') {
				int flag = 0;
				for (int k = 0; k < 8; k++) {
					if (a[i + gox[k]][j + goy[k]] == 'm') {
						flag = 1;
					}
				}
				if (!flag) {
					for (int k = 0; k < 8; k++) {
						if (a[i + gox[k]][j + goy[k]] == '.') {
							vis[i + gox[k]][j + goy[k]] = 1;
						}
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == 'c') {
				for (int k = 0; k < 8; k++) {
					vis[i + gox[k]][j + goy[k]] = 0;
				}
			}
		}
	}
	std::vector<std::pair<int, int>> ans;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (vis[i][j]) {
				ans.push_back({i, j});
			}
		}
	}
	if (ans.empty()) {
		std::cout << "Too cold!" << endl;
	} else {
		for (auto [x, y] : ans) {
			std::cout << x << ' ' << y << endl;
		}
	}
}
