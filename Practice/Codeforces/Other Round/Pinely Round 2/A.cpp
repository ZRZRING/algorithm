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
		int n = read(), a = read(), q = read();
		std::string s;
		std::cin >> s;
		int cnt = a;
		bool flag = 0;
		if (a >= n) flag = 1;
		for (int i = 0; i < q; i++) {
			if (s[i] == '+') cnt++, a++; else a--;
			if (a >= n) flag = 1;
		}
		if (flag) printf("YES\n");
		else if (cnt >= n) printf("MAYBE\n");
		else printf("NO\n");
	}
	return 0;
}