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
		int n = read(), k = read() - 1, a[n + 1];
		memset(a, 0, sizeof(a));
		memset(a, 0, sizeof(a));
		bool imp = 0;
		for (int i = 2; i <= n; i++) a[i] = read() ^ a[i - 1];
		if (n == 1) {printf("%d\n", k); continue;}
		int pt[n];
		memset(pt, 0, sizeof(pt));
		std::vector<int> c;
		pt[0] = 1;
		for (int i = 29; i >= 0; i--) {
			int bit = -1;
			for (int j = 2; j <= n; j++) {
				if (pt[j - 1]) continue;
				if ((a[j - 1] >> i & 1) < (a[j] >> i & 1)) {
					if (bit == 1) {imp = 1; break;} bit = 0; pt[j - 1] = 1;
				}
				if ((a[j - 1] >> i & 1) > (a[j] >> i & 1)) {
					if (bit == 0) {imp = 1; break;} bit = 1; pt[j - 1] = 1;
				}
			}
			if (imp) break; if (bit == -1) c.push_back(i); else a[1] |= bit << i;
		}
		std::reverse(c.begin(), c.end());
		int m = c.size();
		if (imp || 1 << m < k + 1) {printf("-1\n"); continue;}
		for (int i = 0; i < m; i++) {
			if (k >> i & 1) a[1] |= 1 << c[i];
		}
		for (int i = 2; i <= n; i++) a[i] = a[1] ^ a[i];
		for (int i = 1; i <= n; i++) printf("%d ", a[i]); puts("");
	}
	return 0;
}