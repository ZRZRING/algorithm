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

int n, m, k;

int main() {
	int a1 = read(), a2 = read(), a3 = read();
	int ans = min(a1, a2); a1 -= ans; a2 -= ans; ans <<= 1;
	if (!a1) ans += a2 / 3 * 6, ans += (a2 % 3 == 2) * 4;
	if (!a2) ans += a1 / 3 * 3, ans += (a1 % 3 == 2);
	printf("%d", ans);
	return 0;
}