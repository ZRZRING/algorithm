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

int n, m, a[N];

int main() {
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	int lc = 1, rc = n, l = 1, r = n;
	while (a[lc] < a[lc + 1]) lc++; while (a[rc] < a[rc - 1]) rc--; rc = n - rc + 1;
	// printf("%d %d\n", lc, rc);
	for (int i = 1; i <= n; i++) {
		// printf("%d\n", i);
		if (!lc) if (rc & 1) {puts(i & 1 ? "Alice" : "Bob"); break;}
		if (!rc) if (lc & 1) {puts(i & 1 ? "Alice" : "Bob"); break;}
		if (a[l] == a[r]) {
			if (lc & 1 || rc & 1) {puts(i & 1 ? "Alice" : "Bob"); break;}
			else if (lc) l++, lc--; else r--, rc--;
		} else
		if (a[l] > a[r]) {
			if (lc & 1) {puts(i & 1 ? "Alice" : "Bob"); break;} else r--, rc--;
		} else
		if (a[r] > a[l]) {
			if (rc & 1) {puts(i & 1 ? "Alice" : "Bob"); break;} else l++, lc--;
		}
	}
	return 0;
}