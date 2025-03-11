> 给定一个$n$个数的序列，对于每个$k(1\leq k \leq n)$求出最小的$m$，使得将序列划分成$m$段每段不同的数不超过$k$个

$k<\sqrt{n}$时暴力计算，$k>\sqrt{n}$时，$m<\sqrt{n}$，于是不同的$m$只有$\sqrt{n}$种，分治寻找答案相同的$k$直接覆盖即可

```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 2e6 + 10, M = 2010, inf = 0x3f3f3f3f;

const long long Linf = 0x3f3f3f3f3f3f3f3f;

inline int read() {
	bool sym = 0; int res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int n, m, dat[N], ans[N];

bool vis[N];

int calc(int k) {
	int cnt = 0, ans = 0, r = 1;
	while (r <= n) {
		int l = r; cnt = 0; ans++;
		while (cnt + (vis[dat[r]] ^ 1) <= k && r <= n) {
			cnt += vis[dat[r]] ^ 1; vis[dat[r]] = 1; r++;
		}
		for (int i = l; i <= r; i++) vis[dat[i]] = 0;
	}
	return ans;
}

void solve(int l, int r) {
	int sl = calc(l), sr = calc(r);
	if (sl == sr) {
		for (int i = l; i <= r; i++) ans[i] = sl;
	} else {
		int mid = l + r >> 1; solve(l, mid); solve(mid + 1, r);
	}
}

int main() {
	n = read();
	for (int i = 1; i <= n; i++) dat[i] = read();
	int ln = 0; while (1 << ln < n) ln++;
	for (int k = 1; k * k <= n * ln; k++) m = k, ans[k] = calc(k);
	solve(m + 1, n);
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	return 0;
}
```