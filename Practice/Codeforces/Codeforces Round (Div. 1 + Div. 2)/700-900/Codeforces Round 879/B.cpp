#include <bits/stdc++.h>

#define int64 long long

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int main() {
	int T = read();
	while (T--) {
		std::string s, t;
		std::cin >> s >> t;
		int n = s.length(), m = t.length();
		while (n < m) {
			s = "0" + s; n++;
		}
		bool flag = 1;
		int ans = 0;
		for (int i = 0; i < m; i++) {
			if (s[i] == t[i] && flag) continue;
			if (flag) ans += t[i] - s[i], flag = 0; else ans += 9;
		}
		printf("%d\n", ans);
	}
	return 0;
}