#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'
#define PII std::pair<int, int>

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int N = 2e5 + 10, mod = 998244353, inf = 0x3f3f3f3f;

int main() {
	int n = read(), a[n + 1], f[n + 1][3];
	for (int i = 1; i <= n; i++) a[i] = read();
	memset(f, 0x3f, sizeof(f));
	f[1][0] = 1; f[1][1] = a[1] ? 1 : inf; f[1][2] = 0;
	for (int i = 2; i <= n; i++) {
		if (a[i] == 0) {
			f[i][0] = std::min(f[i - 1][0] + 1, f[i - 1][1]);
			f[i][2] = std::min(f[i - 1][0], f[i - 1][1]);
		}
		if (a[i] == 1) {
			f[i][0] = std::min({f[i - 1][0] + 1, f[i - 1][1], f[i - 1][2] + 1});
			f[i][1] = std::min(f[i - 1][0] + 1, f[i - 1][1]);
			f[i][2] = std::min({f[i - 1][0], f[i - 1][1], f[i - 1][2]});
		}
		if (a[i] == 2) {
			f[i][1] = std::min({f[i - 1][0] + 1, f[i - 1][1], f[i - 1][2] + 1});
			f[i][2] = std::min({f[i - 1][0], f[i - 1][1], f[i - 1][2]});
		}
	}
	// for (int i = 1; i <= n; i++) printf("%d %d\n", f[i][0], f[i][1]);
	printf("%d", std::min(f[n][0], f[n][1]));
	return 0;
}