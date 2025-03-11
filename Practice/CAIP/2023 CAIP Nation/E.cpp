#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'
#define PII std::pair<int, int>

int64 read() {
	int64 res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int gox[4] = {1, -1, 0, 0}, goy[4] = {0, 0, 1, -1};

int n, m, k, a[1010][1010];

bool th[1010][1010];

bool dfs(int x, int y) {
	if (x && a[x - 1][y] != a[x][y]) return 0;
	th[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int tx = x + gox[i], ty = y + goy[i];
		if (tx < 1) continue;
		if (tx > n) continue;
		if (ty < 1) continue;
		if (ty > m) continue;
		if (th[tx][ty]) continue;
		if (a[tx][ty] == a[x][y]) if (!dfs(tx, ty)) return 0;
	}
}

void remove(int x) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == x) a[i][j] = 0;
		}
	}
}

int main() {
	n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			a[i][j] = read(); k = std::max(k, a[i][j]);
		}
	}
	bool vis[k + 1] = {0}, flag = 0;
	while (1) {
		bool doflag = 0;
		for (int i = 1; i <= k; i++) {
			if (vis[i]) continue;
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= m; k++) {
					if (a[j][k] == i) {
						memset(th, 0, sizeof(th));
						if (dfs(j, k)) vis[i] = 1, remove(i), doflag = 1, printf("%d ", i);
					}
				}
			}
		}
		if (!doflag) {flag = 1; break;}
	}
	if (flag) printf("Impossible");
	return 0;
}