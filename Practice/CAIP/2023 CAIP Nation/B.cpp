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

int main() {
	int T = read();
	while (T--) {
		int n = read(), vis[10][10] = {0};
		std::vector<int> a[10];
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 6; j++) vis[j][read()] = 1;
		}
		for (int i = 0; i < 6; i++) {
			for (int j = 1; j <= 8; j++) {
				if (!vis[i][j]) a[i].push_back(j);
			}
		}
		int ans = 1e9;
		for (int i = 7; i < 1 << 6; i++) {
			std::vector<int> ask;
			for (int j = 0; j < 6; j++) {
				if (i >> j & 1) ask.push_back(j);
			}
			if (ask.size() == 3) {
				int f[100] = {0}, l = 0, r = 0, sum = 0;
				for (int i = 0; i < 8 - n; i++) {
					for (int j = 0; j < 8 - n; j++) {
						for (int k = 0; k < 8 - n; k++) {
							l = std::min(l, a[ask[0]][i] + a[ask[1]][j] + a[ask[2]][k]);
							r = std::max(r, a[ask[0]][i] + a[ask[1]][j] + a[ask[2]][k]);
							f[a[ask[0]][i] + a[ask[1]][j] + a[ask[2]][k]]++;
						}
					}
				}
				for (int i = l; i <= r; i++) sum += f[i], f[i] += f[i - 1];
				for (int i = l; i <= r; i++) {
					for (int j = i; j <= r; j++) {
						ans = std::min(ans, std::max(f[j] - f[i - 1], sum - f[j] + f[i - 1]));
					}
				}
			}
		}
		printf("%d\n", ans * (8 - n) * (8 - n) * (8 - n));
	}
	return 0;
}