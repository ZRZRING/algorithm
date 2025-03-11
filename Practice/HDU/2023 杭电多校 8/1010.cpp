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
		int n = abs(read() - read());
		// int n = read();
		int x = sqrt(n);
		if (x * x == n) {printf("1\n"); continue;}
		if (n % 2 == 1) {printf("2\n"); continue;}
		if (n % 4 == 0) {printf("2\n"); continue;}
		if (n % 4 == 2) {
			bool flag = 0;
			for (int i = 1; i * i <= n; i++) {
				int x = sqrt(n - i * i);
				if (x * x == n - i * i) {flag = 1; break;}
			}
			if (flag) printf("2\n"); else printf("3\n");
			continue;
		}
	}
	return 0;
}