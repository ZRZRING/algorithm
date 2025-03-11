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

int n, m, a[110][110];

int main() {
	int T = read();
	a[1][1] = 1000;
	for (int i = 2; i <= 100; i++) {
		int sum = 0;
		for (int j = 2; j <= i; j++) a[i][j] = !a[i - 1][j - 1], sum += a[i][j];
		a[i][1] = 1000 - sum;
	}
	while (T--) {
		n = read();
		for (int i = 1; i <= n; i++) printf("%d ", a[n][i]); printf("\n");
	}
	return 0;
}