#include <bits/stdc++.h>

#define int64 long long
#define PII std::pair<int, int>
#define endl '\n'

int64 read() {
	int64 res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int mod = 998244353;

bool ispower(char c) {
	return c >= 'A' && c <= 'Z';
}

bool islower(char c) {
	return c >= 'a' && c <= 'z';
}

int get(char c) {
	if (isdigit(c)) return c - '0';
	if (ispower(c)) return c - 'A' + 10;
	if (islower(c)) return c - 'a' + 36;
}

int n;

std::string s;

int64 solve(bool f1, bool f2, bool f3) {
	if (f1 && f2 && f3) return 0;
	int64 f[2][62] = {0}, sum[2] = {0};
	sum[0] = 1;
	for (int i = 1; i <= n; i++) {
		if (isdigit(s[i]) && f1) return 0;
		if (ispower(s[i]) && f2) return 0;
		if (islower(s[i]) && f2 && f3) return 0;
		for (int j = 0; j < 62; j++) f[i & 1][j] = 0; sum[i & 1] = 0;
		if (isdigit(s[i])) {
			f[i & 1][get(s[i])] = (sum[i & 1 ^ 1] - f[i & 1 ^ 1][get(s[i])] + mod) % mod;
		}
		if (ispower(s[i])) {
			f[i & 1][get(s[i])] = (sum[i & 1 ^ 1] - f[i & 1 ^ 1][get(s[i])] + mod) % mod;
		}
		if (islower(s[i])) {
			if (!f2) f[i & 1][get(s[i]) - 26] = (f[i & 1][get(s[i]) - 26] + sum[i & 1 ^ 1] - f[i & 1 ^ 1][get(s[i]) - 26] + mod) % mod;
			if (!f3) f[i & 1][get(s[i])] = (f[i & 1][get(s[i])] + sum[i & 1 ^ 1] - f[i & 1 ^ 1][get(s[i])] + mod) % mod;
		}
		if (s[i] == '?') {
			if (!f1) {
				for (int j = 0; j < 10; j++) {
					f[i & 1][j] = (sum[i & 1 ^ 1] - f[i & 1 ^ 1][j] + mod) % mod;
				}
			}
			if (!f2) {
				for (int j = 10; j < 36; j++) {
					f[i & 1][j] = (sum[i & 1 ^ 1] - f[i & 1 ^ 1][j] + mod) % mod;
				}
			}
			if (!f3) {
				for (int j = 36; j < 62; j++) {
					f[i & 1][j] = (sum[i & 1 ^ 1] - f[i & 1 ^ 1][j] + mod) % mod;
				}
			}
		}
		for (int j = 0; j < 62; j++) {
			// printf("%d ", f[i & 1][j]);
			sum[i & 1] = (sum[i & 1] + f[i & 1][j]) % mod;
		}
		// puts("");
	}
	return sum[n & 1];
}

int main() {
	n = read();
	std::cin >> s;
	s = " " + s;
	int64 c, ans = 0;
	for (int i = 0; i < 8; i++) {
		c = __builtin_popcount(i) & 1 ? -1 : 1;
		int64 t = solve(i % 2, i / 2 % 2, i / 4);
		// printf("%d %d %d %d %d\n", i, c, i % 2, i / 2 % 2, i / 4);
		ans = (ans + c * t + mod) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}