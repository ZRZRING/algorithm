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

struct DAT {int l, r;} dat[N];

bool cmp(DAT a, DAT b) {return a.r == b.r ? a.l < b.l : a.r < b.r;}

// 贪心

int main() {
	n = read();
	for (int i = 1; i <= n; i++) dat[i] = (DAT){read(), read()};
	sort(dat + 1, dat + n + 1, cmp);
	long long ans = 0; int last = 0;
	for (int i = 1; i <= n; i++) {
		int l = i, r = i;
		while (dat[r + 1].r == dat[l].r) r++;
		ans += 1ll * max(last, dat[r].l) * (r - l + 1);
		last = max(last, dat[r].l);	i = r;
	}
	printf("%lld", ans);
	return 0;
}