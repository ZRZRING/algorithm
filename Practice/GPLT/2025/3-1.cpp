#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);

using A2 = std::array<int, 2>;

int main() {
	IOS
	int B, n, m, Q;
	std::cin >> B >> n >> m >> Q;
	std::vector d(n + 1, std::vector(n + 1, int(1e9)));
	std::vector hps(n + 1, std::vector(n + 1, int()));
	for (int i = 1; i <= m; i++) {
		int u, v, c, h;
		std::cin >> u >> v >> c >> h;
		d[u][v] = d[v][u] = c;
		hps[u][v] = hps[v][u] = h;
	}
	std::vector dis = d;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dis[i][k] + dis[k][j] < dis[i][j]) {
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}
	while (Q--) {
		int x;
		std::cin >> x;
		std::vector<int> Dis(n + 1), ddis(n + 1);
		std::queue<int> q;
		q.push(x);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (int i = 1; i <= n; i++) {
				if (Dis[i] < Dis[u] + hps[u][i] && ddis[u] + d[u][i] <= B) {
					Dis[i] = Dis[u] + hps[u][i];
					ddis[i] = ddis[u] + d[u][i];
					q.push(i);
				}
			}
		}
		int max = 0;
		std::vector<int> a, b;
		for (int i = 1; i <= n; i++) {
			if (dis[x][i] <= B) {
				a.push_back(i);
			}
			if (Dis[i] > max) {
				b.clear();
				max = Dis[i];
			}
			if (Dis[i] == max) {
				b.push_back(i);
			}
		}
		if (a.empty()) {
			std::cout << "T_T\n";
		} else {
			for (int i = 0; i < a.size(); i++) {
				std::cout << a[i] << " \n"[i == a.size() - 1];
			}
			for (int i = 0; i < b.size(); i++) {
				std::cout << b[i] << " \n"[i == b.size() - 1];
			}
		}
	}
}
