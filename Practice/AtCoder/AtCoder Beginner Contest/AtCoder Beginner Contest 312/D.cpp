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

const int N = 2e5 + 10, mod = 998244353, inf = 0x3f3f3f3f;

int main() {
	std::string s; std::cin >> s;
	int n = s.length();
	if (s[0] == ')') {printf("0\n"); return 0;}
	int f[n + 1][n + 1];
	memset(f, 0, sizeof(f)); f[0][1] = 1;
	for (int i = 1; i < n; i++) {
		if (s[i] == '(') {
			for (int j = 1; j <= i + 1; j++) {
				f[i][j] = f[i - 1][j - 1];
			}
		}
		if (s[i] == ')') {
			for (int j = 0; j <= i; j++) {
				f[i][j] = f[i - 1][j + 1];
			}
		}
		if (s[i] == '?') {
			f[i][0] = f[i - 1][1];
			f[i][i + 1] = f[i - 1][i];
			for (int j = 1; j <= i; j++) {
				f[i][j] = (f[i - 1][j - 1] + f[i - 1][j + 1]) % mod;
			}
		}
	}
	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j <= i; j++) printf("%d ", f[i][j]); puts("");
	// }
	printf("%d", f[n - 1][0]);
	return 0;
}