>多次询问区间内出现次数大于区间长度/k的数

主席树板子题，因为出现次数超过区间长度除以$k$的数不超过$k$个，于是复杂度就是主席树的复杂度乘$k$，可以通过此题

```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1e7 + 10, M = 2e6 + 10, inf = 0x3f3f3f3f;

const long long Linf = 0x3f3f3f3f3f3f3f3f;

inline int read() {
	bool sym = 0; int res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int n, m, cnt;

int ls[N], rs[N], sum[N], rt[N];

void ins(int &x, int y, int l, int r, int pos) {
	x = ++cnt; ls[x] = ls[y]; rs[x] = rs[y]; sum[x] = sum[y] + 1;
	if (l == r) return; int mid = l + r >> 1;
	if (mid >= pos) ins(ls[x], ls[y], l, mid, pos);
	else ins(rs[x], rs[y], mid + 1, r, pos);
}

int query(int x, int y, int l, int r, int t) {
	if (l == r) return l; int mid = l + r >> 1, res = 0;
	if (sum[ls[x]] - sum[ls[y]] > t) if (res = query(ls[x], ls[y], l, mid, t)) return res;
	if (sum[rs[x]] - sum[rs[y]] > t) if (res = query(rs[x], rs[y], mid + 1, r, t)) return res;
	return res;
}

int main() {
	n = read(); m = read();
	for (int i = 1; i <= n; i++) {
		int x = read(); ins(rt[i], rt[i - 1], 1, n, x);
	}
	for (int i = 1; i <= m; i++) {
		int l = read(), r = read(), c = read();
		int ans = query(rt[r], rt[l - 1], 1, n, (r - l + 1) / c);
		printf("%d\n", ans ? ans : -1);
	}
	return 0;
}
```