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
		int n = read(), ans1 = 0, ans2 = 0;
		std::string s, t1, t2;
		std::cin >> s >> t1;
		t2 = t1;
		std::reverse(t2.begin(), t2.end());
		if (s == t1) {
			printf("0\n"); continue;
		}
		if (s == t2) {
			printf("2\n"); continue;
		}
		for (int i = 0; i < n; i++) {
			if (s[i] != t1[i]) ans1++;
			if (s[i] != t2[i]) ans2++;
		}
		printf("%d\n", std::min(ans1 * 2 - (ans1 & 1), ans2 * 2 - (ans2 & 1 ^ 1)));
	}
	return 0;
}