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

const int N = 300;

inline int read() {
	bool sym = 0; int res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int n, a[5] = {0, 2, 3, 17, 19}, b[N] = {0, 5, 7, 11, 13}, fa[N], fb[N];

int main() {
	int T = read();
	while (T--) {
		n = read(); memset(fa, 0x3f, sizeof(fa)); memset(fb, 0x3f, sizeof(fb));
		if (n >= 287) {printf("A\n"); continue;}
		fa[0] = fb[0] = 0;
		for (int i = 1; i <= 4; i++) {
			for (int j = a[i]; j <= n; j++) {
				fa[j] = min(fa[j - a[i]] + 1, fa[j]);
			}
		}
		for (int i = 1; i <= 4; i++) {
			for (int j = b[i]; j <= n; j++) {
				fb[j] = min(fb[j - b[i]] + 1, fb[j]);
			}
		}
		// printf("%d %d\n", fa[n], fb[n]);
		if (fa[n] == 0x3f3f3f3f && fb[n] == 0x3f3f3f3f) {printf("-1\n"); continue;}
		printf(fa[n] == fb[n] ? "both\n" : fa[n] < fb[n] ? "A\n" : "B\n");
	}
	return 0;
}