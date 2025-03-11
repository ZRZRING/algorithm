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

int n, m;

int main() {
	int T = read();
	while (T--) {
		n = read(); int k = read(), a = read();
		for (int i = k + 1, j = 1; j <= a; i += n, j++) {
			int x = i; bool f = 0;
			while (x) {if (x % 10 == 7) {f = 1; break;} x /= 10;}
			if (f || i % 7 == 0) printf("p "); else printf("%d ", i);
		}
		printf("\n");
	}
	return 0;
}