#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'

int main() {
	int n;
	std::cin >> n;
	std::vector<int> to(n + 1), fa(n + 1), vis(n + 1);
	std:iota(fa.begin(), fa.end(), 0);
	std::function<int(int)> find = [&](int x) -> int {
		return fa[x] == x ? x : fa[x] = find(fa[x]);
	};
	for (int u = 1; u <= n; u++) {
		std::cin >> to[u];
		if (to[u] == 0) {
			vis[u] = 1;
		}
	}
	for (int u = 1; u <= n; u++) {
		int x = find(u), y = find(to[u]);
		if (vis[x] || vis[y]) {
			vis[x] = 1;
			vis[y] = 1;
		}
		if (x != y) fa[x] = y;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[find(i)]) ans ^= i; 
	}
	std::cout << ans << endl;
	return 0;
}