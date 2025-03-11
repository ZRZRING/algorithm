#include <bits/stdc++.h>

#define int64 long long

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int N = 2e5 + 10, mod = 998244353, inf = 0x3f3f3f3f;

int main() {
	int T = read();
	while (T--) {
		std::string s;
		std::cin >> s;
		int n = s.length(), ans = 0;
		for (int i = 0; i < n; i++) {
			int x = i;
			while (x < n - 1 && s[x + 1] == s[i]) x++;
			int len = x - i + 1; ans += len - 1; i = x;
		}
		printf("%d\n", ans);
	}
	return 0;
}