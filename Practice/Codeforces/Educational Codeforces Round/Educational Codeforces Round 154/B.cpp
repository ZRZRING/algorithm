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
	int T = read();
	while (T--) {
		std::string s, t;
		std::cin >> s >> t;
		int n = s.length(), a[n];
		for (int i = 0; i < n; i++) {
			if (s[i] != t[i]) a[i] = 2; else a[i] = s[i] - '0';
		}
		bool flag = 0;
		for (int i = 1; i <= n - 1; i++) {
			if (a[i - 1] == 0 && a[i] == 1) goto YES;
		}
		NO:{printf("NO\n"); continue;}
		YES:{printf("YES\n"); continue;}
	}
	return 0;
}