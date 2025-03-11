#include <bits/stdc++.h>

#define int64 long long
#define pii std::pair<int, int>
#define mp(x, y) make_pair(x, y)

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int gox[4] = {0, 0, 1, -1}, goy[4] = {1, -1, 0, 0};

struct EDGE {
	int node, dis;
};

void dij(int n, int s, std::vector<EDGE> edge[], int dis[]) {
	bool vis[n + 1];
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	std::priority_queue<pii, std::vector<pii>, std::greater<pii>> q;
	q.push({0, s}); dis[s] = 0;
	while (!q.empty()) {
		int u = q.top().second; q.pop(); if (vis[u]) continue; vis[u] = 1;
		for (auto e : edge[u]) {
			int v = e.node, t = e.dis;
			if (dis[u] + t < dis[v]) {
				dis[v] = dis[u] + t; q.push({dis[v], v});
			}
		}
	}
}

int main() {
	int n = read(), m = read(), nm = n * m;
	std::string s[n];
	for (int i = 0; i < n; i++) std::cin >> s[i];
	std::vector<EDGE> edge[2 * nm];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int u0 = i * m + j, u1 = i * m + j + nm;
			for (int k = 0; k < 4; k++) {
				int x = i + gox[k], y = j + goy[k];
				if (x < 0 || x > n - 1 || y < 0 || y > m - 1) continue;
				int v0 = x * m + y, v1 = x * m + y + nm;
				if (s[x][y] == '1') {
					edge[u0].push_back({v1, 1});
					edge[u1].push_back({v0, 2});
				} else {
					edge[u0].push_back({v1, 2});
					edge[u1].push_back({v0, 1});
				}
			}
		}
	}
	int dis[nm];
	dij(2 * nm, nm * (s[0][0] == '1'), edge, dis);
	printf("%d %d\n", dis[nm - 1], dis[2 * nm - 1]);
	return 0;
}