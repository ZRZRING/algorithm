#include <bits/stdc++.h>

#define endl '\n'
#define int64 long long

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> e(n + 1);
	for (int i = 1; i <= m; i++) {
		int u, v;
		std::cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	std::vector<int> vis(n + 1), to(n + 1);
	int ans = 0, size = 0, cir_size = 0, flag = 0;
	auto dfs = [&](auto self, int u, int last) -> void {
		vis[u] = 1;
		for (auto v : e[u]) {
			if (v == last) continue;
			to[u] = v;
			if (vis[v]) {
				flag++;
				if (flag != 1) continue;
				int x = v;
				while (x != u) {
					cir_size++;
					x = to[x];
				}
				cir_size++;
				continue;
			}
			self(self, v, u);
		}
	};
	auto check = [&](int x) -> bool {
		flag = 0;
		cir_size = 0;
		dfs(dfs, x, x);
//		std::cout << flag << endl;
		if (flag == 2) {
			return 1;
		}
		return 0;
	};
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		int x = check(i);
		if (x) {
			ans += x;
			size = cir_size;
		}
	}
	if (ans == 1) {
		std::cout << "Yes" << ' ' << size << endl;
	} else {
		std::cout << "No" << ' ' << ans << endl;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
}
