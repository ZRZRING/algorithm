#include <bits/stdc++.h>

#define int64 long long

inline int64 read() {
	int64 res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int N = 1e5;

int s[N][2], val[N], cnt;

int main() {
	int n = read(), m = read(), T[n], E[n + 1][m + 1], D[n + 1];
	memset(E, 0, sizeof(E));
	for (int i = 1; i < n; i++) T[i] = read();
	for (int i = 1; i <= n; i++) E[i][1] = read();
	for (int i = 1; i <= n; i++) D[i] = read();
	for (int i = 1; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			E[i][j] = E[i][j - 1] - D[i];
			if (E[i][j] <= 0) {E[i][j] = 0; break;}
		}
		for (int j = 1; j <= m; j++) {
			E[i][j] += E[i][j - 1];
		}
	}
	int f[n + 1][m + 1];
	memset(f, -0x3f, sizeof(f));
	f[1][0] = 0;
	for (int i = 1; i <= m; i++) f[1][i] = E[1][i];
	for (int i = 2; i <= n; i++) {
		for (int k = T[i - 1]; k <= m; k++) {
			for (int j = 0; k - j - T[i - 1] >= 0; j++) {
				f[i][k] = std::max(f[i][k], f[i - 1][j] + E[i][k - j - T[i - 1]]); 
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		// for (int j = 0; j <= m; j++) {
		// 	if (f[i][j] < 0) printf("- "); else printf("%d ", f[i][j]);
		// }
		// puts("");
		ans = std::max(ans, f[i][m]);
	}
	printf("%d", ans);
}