#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <functional>

int read() {
	int res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int n, m, ans, ans1;

std::vector<std::string> ch;

std::vector<std::vector<bool> > vis;

bool dfs(int x, int y) {
	if (x < 1 || x > n || y < 1 || y > m) return 0;
	if (ch[x][y] == '0') return 0;
	if (vis[x][y]) return 0; vis[x][y] = 1;
	bool res = (ch[x][y] > '1');
	res |= dfs(x + 1, y);
	res |= dfs(x - 1, y);
	res |= dfs(x, y + 1);
	res |= dfs(x, y - 1);
	return res;
}

int main() {
	n = read(); m = read(); ch.resize(n + 1); vis.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		vis[i].resize(m + 1);
		std::cin >> ch[i]; ch[i] = "0" + ch[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!vis[i][j] && ch[i][j] != '0') {
				ans1 += dfs(i, j); ans++;
			}
		}
	}
	printf("%d %d\n", ans, ans1);
}