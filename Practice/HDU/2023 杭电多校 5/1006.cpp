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
		std::string a; std::cin >> a;
		int c1 = 0, c2 = 0, c3 = 0, s = 0, len = a.length(), sum = 'R' + 'G' + 'B', ans = 0;
		while ((!c1 || !c2 || !c3) && s < len) {
			if (a[s] == 'R' && ++c1 == 3) {s++; break;}
			if (a[s] == 'G' && ++c2 == 3) {s++; break;}
			if (a[s] == 'B' && ++c3 == 3) {s++; break;}
			s++;
		}
		// printf("%d %d %d %d\n", c1, c2, c3, s);
		if (c1 == 3 || c2 == 3 || c3 == 3) {
			int i = s - 1; ans++;
			if (i + 2 < len) c1 = a[i + 1] != a[i + 2] ? sum - a[i + 1] - a[i + 2] : a[i + 2], c2 = 0;
		} else {
			int i = s - 1;
			if (i + 1 < len) c1 = a[i + 1], c2 = a[i + 1];
		}
		for (int i = s; i < len; i++) {
			if (!c1) {c1 = a[i]; continue;}
			if (!c2) {c2 = a[i]; continue;}
			c3 = a[i];
			if (c1 != c2) {
				if (i + 1 >= len) break;
				c1 = a[i + 1], c2 = a[i + 1];
			} else {
				ans++; if (i + 2 >= len) break;
				c1 = a[i + 1] != a[i + 2] ? sum - a[i + 1] - a[i + 2] : a[i + 2], c2 = 0;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}