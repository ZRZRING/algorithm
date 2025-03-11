同洛谷P4462 [CQOI2018]异或序列 - [题目链接](https://www.luogu.com.cn/problem/P4462)

定义异或运算的符号为$\oplus$，考虑对原序列求一个前缀异或，然后询问变成了有多少点对满足$a_x \oplus a_y = k$，其中$x\in [l - 1, r - 1], y\in [l, r]$

如果$a_x \oplus a_y = k$，那么$a_x = a_y \oplus k$，于是另外开一个数组$b$存$a_y \oplus k$的值，问题变成多次询问一段区间内有多少对$(x, y)$使得$a_x = b_y, x \leq y$

莫队即可，复杂度$\mathcal{O}(n^{3 / 2})$

```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 2e6 + 10, inf = 0x3f3f3f3f;

const long long Linf = 0x3f3f3f3f3f3f3f3f;

inline int read() {
	bool sym = 0; int res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

struct QRY{int l, r, id;}qry[N];

int n, m, l[N], r[N], Q, a[N], b[N], bel[N], cnta[N], cntb[N];

long long ans[N];

void init() {
	int S = sqrt(n);
	for (int i = 1; i <= n; i += S) {
		l[++Q] = i; r[Q] = i + S - 1;
	}
	for (int i = 1; i <= Q; i++) {
		for (int j = l[i]; j <= r[i]; j++) bel[j] = i;
	}
}

bool cmp(QRY a, QRY b) {return bel[a.l] == bel[b.l] ? a.r < b.r : a.l < b.l;}

int main() {
	n = read(); m = read(); init(); int t = read();
	for (int i = 1; i <= n; i++) a[i] = read() ^ a[i - 1];
	for (int i = 1; i <= n; i++) b[i] = a[i - 1] ^ t;
	for (int i = 1; i <= m; i++) qry[i] = (QRY){read(), read(), i};
	sort(qry + 1, qry + m + 1, cmp);
	int l = 1, r = 0; long long res = 0;
	for (int i = 1; i <= m; i++) {
		while (l < qry[i].l) res -= cnta[b[l]], cnta[a[l]]--, cntb[b[l]]--, l++;
		while (l > qry[i].l) l--, cnta[a[l]]++, cntb[b[l]]++, res += cnta[b[l]];
		while (r < qry[i].r) r++, cnta[a[r]]++, cntb[b[r]]++, res += cntb[a[r]];
		while (r > qry[i].r) res -= cntb[a[r]], cnta[a[r]]--, cntb[b[r]]--, r--;
		ans[qry[i].id] = res;
	}
	for (int i = 1; i <= m; i++) printf("%lld\n", ans[i]);
	return 0;
}
```