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
	int T = read();
	while (T--) {
		int n = read(), len_s, len_t;
		std::string s; std::cin >> s;
		std::string t(n, '0'); t = s + t + s;
		len_s = s.length(); len_t = t.length();
		s = " " + s; t = " " + t;
		int to[len_s + 1]; to[1] = 0;
		for (int i = 2, j = 0; i <= len_s; i++) {
			while (j && s[i] != s[j + 1]) j = to[j];
			if (s[i] == s[j + 1]) j++; to[i] = j;
		}
		// for (int i = 1; i <= len_s; i++) printf("%d ", to[i]); puts("");
		int ans = 0; bool flag = 0;
		for (int i = 1, j = 0; i < len_t; i++) {
			while (j && t[i] != s[j + 1]) j = to[j];
			if (t[i] == s[j + 1]) j++;
			// printf("%d %d\n", i, j);
			if (j == len_s && i != len_s) flag = 1;
		}
		if (flag) {
			std::string ans(n, '1'); std::cout << ans << '\n';
		} else {
			std::string ans(n, '0'); std::cout << ans << '\n';
		}
	}
	return 0;
}