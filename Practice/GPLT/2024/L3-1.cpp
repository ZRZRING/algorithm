#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'
#define PII std::pair<int, int>

const int gox[4] = {0, 0, -1, 1}, goy[4] = {-1, 1, 0, 0};

int main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> a(n + 2, std::vector<int>(m + 2));
	std::vector<std::vector<int>> ans(n + 2, std::vector<int>(m + 2, -1));
	int X = 0, Y = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cin >> a[i][j];
			if (a[i][j] == 2) {
				X = i;
				Y = j;
			}
		}
	}
	std::queue<PII> q;
	q.push({X, Y});
	ans[X][Y] = 0;
	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + gox[i], yy = y + goy[i];
			if (!a[xx][yy]) continue;
			if (ans[xx][yy] != -1) continue;
			ans[xx][yy] = ans[x][y] + 1;
			q.push({xx, yy});
		}
	}
	int Q;
	std::cin >> Q;
	std::vector<PII> p(Q + 1);
	for (int i = 1; i <= Q; i++) {
		int x, y;
		std::cin >> y >> x;
		p[i] = {i, ans[x][y]};
	}
	std::sort(p.begin() + 1, p.end(), [](PII a, PII b) {
		return a.second < b.second;
	});
//	for (auto [x, y] : p) {
//		std::cout << x << ' ' << y << endl;
//	}
	int s = 1;
	while (p[s].second == -1) s++;
	for (int i = s; i <= Q; i++) {
		if (p[i].second == p[i + 1].second) {
			while (i + 1 <= Q && p[i].second == p[i + 1].second) i++;
		} else {
			std::cout << p[i].first << ' ' << p[i].second << endl;
			return 0;
		}
	}
	std::cout << "No winner." << endl;
}
