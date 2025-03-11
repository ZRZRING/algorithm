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

const int N = 2e5, mod = 998244353, inf = 0x3f3f3f3f;

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("wa.txt", "w", stdout);
	int T = read();
	while (T--) {
		int n = read();
		std::string s; std::cin >> s;
		// std::cout << s << ' ';
		int l = 0, r = n - 1, op = 0, ans = -1;
		if (n == 1) {
			if (s[0] == '1') printf("1\n"); else printf("-1\n"); continue;
		}
		while (l <= r) {
			if (l == r) {if (s[l] - '0' != op) ans = op ^ 1; break;}
			if (s[l] != s[r]) {
				if (s[l] - '0' == op) l++; else r--; op ^= 1; continue;
			}
			if (s[l] - '0' != op) {ans = op ^ 1; break;}
			if (s[l + 1] - '0' == op || s[r - 1] - '0' == op) {ans = op; break;}
			// printf("%d %d\n", l, r);
			while (l + 1 < r - 1 && s[l] - '0' == op && s[l + 1] - '0' != op && s[l + 2] - '0' == op) l += 2;
			while (l + 1 < r - 1 && s[r] - '0' == op && s[r - 1] - '0' != op && s[r - 2] - '0' == op) r -= 2;
			if (s[l + 1] - '0' == op || s[r - 1] - '0' == op) {ans = op; break;} else op ^= 1, l++;
		}
		printf("%d\n", ans);
	}
	return 0;
}