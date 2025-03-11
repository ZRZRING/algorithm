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
		int n = read();
		std::string s; std::cin >> s;
		char c = ' ';
		for (int i = 0; i < n; i++) {
			if (c == ' ') {c = s[i]; continue;}
			if (s[i] == c) {
				putchar(s[i]); c = ' ';
			}
		}
		puts("");
	}
	return 0;
}