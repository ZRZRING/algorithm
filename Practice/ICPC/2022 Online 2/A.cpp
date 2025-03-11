#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

#define file(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout);
#define dbg(x) cerr<<"In Line"<<__LINE__<<" the "<<#x<<" = "<<x<<'\n';
#define abs(x) ((x) < 0 ? -(x) : (x))

using namespace std;

const int N = 2e6 + 10;

inline int read() {
	bool sym = 0; int res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int n, q, a[110][110];

int main() {
	int T = read();
	while (T--) {
		n = read();
		for (int i = 1; i <= min(n, 100); i++) for (int j = 1; j <= i; j++) a[i][j] = read();
		q = read();
		if (n <= 100) {
			for (int i = 1; i <= q; i++) {
				int mod = read(), c = 0;
				for (int i = 1; i <= n; i++) c = (c * 10 + a[n][i]) % mod;
				printf("%d\n", c);
			}
		} else {
			for (int i = 1; i <= q; i++) {
				int mod = read(), c = 0;
				for (int i = n % (mod - 1) + 1; i <= mod - 1; i++) c = (c * 10 + a[mod - 1][i]) % mod;
				for (int i = 1; i <= n % (mod - 1); i++) c = (c * 10 + a[mod - 1][i]) % mod;
				printf("%d\n", c);
			}
		}
	}
	return 0;
}