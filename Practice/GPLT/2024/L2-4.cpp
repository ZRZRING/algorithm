#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'

int main() {
	int L, n, ans = 0;
	std::cin >> L >> n;
	std::vector<int> vx(n + 1, L), vy(n + 1, L);
	auto dfs = [&](auto self, int x, int y) -> void {
		if (x == n) {
			int sumx = 0, sumy = 0;
			for (int i = 1; i < n; i++) {
				sumx += vx[i];
			}
			for (int i = 1; i < n; i++) {
				sumy += vy[i];
			}
			if (sumx != sumy || sumx > L || sumy > L) return;
			ans++;
			return;
		}
		for (int i = 0; i <= std::min(vx[x], vy[y]); i++) {
			vx[x] -= i;
			vy[y] -= i;
			if (y == n - 1) self(self, x + 1, 1);
			else self(self, x, y + 1);
			vx[x] += i;
			vy[y] += i;
		}
	};
	dfs(dfs, 1, 1);
	std::cout << ans << endl;
}