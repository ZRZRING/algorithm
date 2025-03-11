#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'
#define PII std::pair<int, int>
#define init_0(x) memset(x, 0, sizeof(x))
#define init_inf(x) memset(x, 0x3f, sizeof(x))

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int N = 2e5, mod = 1e9 + 7, inf = 0x3f3f3f3f;

int main() {
	int T = read();
	while (T--) {
		int n = read(), m = read();
		std::vector<std::vector<int> > k(n, std::vector<int>(30));
		std::vector<std::vector<int> > b(n, std::vector<int>(30));
		std::vector<std::vector<int> > to(n, std::vector<int>(30));
		for (int i = 0; i < n; i++) k[i][0] = read();
		for (int i = 0; i < n; i++) b[i][0] = read();
		for (int i = 0; i < n; i++) to[i][0] = read() - 1;
		for (int i = 1; 1 << i <= 1e9; i++) {
			for (int j = 0; j < n; j++) {
				to[j][i] = to[to[j][i - 1]][i - 1];
				k[j][i] = 1ll * k[j][i - 1] * k[to[j][i - 1]][i - 1] % mod;
				b[j][i] = (1ll * k[to[j][i - 1]][i - 1] * b[j][i - 1] + b[to[j][i - 1]][i - 1]) % mod;
			}
		}
		// for (int i = 0; i < n; i++) {for (int j = 0; j < 4; j++) printf("%d ", k[i][j]); puts("");}
		// for (int i = 0; i < n; i++) {for (int j = 0; j < 4; j++) printf("%d ", b[i][j]); puts("");}
		// for (int i = 0; i < n; i++) {for (int j = 0; j < 4; j++) printf("%d ", to[i][j]); puts("");}
		for (int i = 1; i <= m; i++) {
			int x = to[read() - 1][0], t = read(), y = read();
			for (int j = 0; t >> j; j++) {
				if (t >> j & 1) y = (1ll * y * k[x][j] + b[x][j]) % mod, x = to[x][j];
			}
			printf("%d\n", y);
		}
	}
	return 0;
}