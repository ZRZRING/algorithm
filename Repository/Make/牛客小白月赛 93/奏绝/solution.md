每个区间记录该区间内的答案，黑白之章往前和往后的长度和与数量。两个区间合并，跨越区间的贡献可以表示为，将某一区间的黑白之章长度和 $\times$ 另一区间的相反颜色的数量。

通过上述想法，使用线段树即可解决此问题，但是线段树本身较为复杂，于是我们可以继续挖掘上述计算中的性质。

考虑以上维护的信息包括：区间前后缀长度和，区间某种元素的数量，区间的答案。

这些信息均满足可减性，于是可以通过差分 $\mathcal{O}(1)$ 得出，将复杂度优化到 $\mathcal{O}(n)$。

本来是想卡线段树的，后来因为其他语言的同学过不去，于是下调了数据范围，线段树是可以通过的。

```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1e6 + 10, M = 2e6 + 10, inf = 0x3f3f3f3f, mod = 998244353;

const long long Linf = 0x3f3f3f3f3f3f3f3f;

inline int read() {
	bool sym = 0; int res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

struct NODE {
	int cnt[2]; long long dis[2], ans;
} ans[N];

int n, m, cnt;

char ch[N];

NODE operator + (const NODE &x, const NODE &y) {
	NODE t;
	t.cnt[0] = x.cnt[0] + y.cnt[0]; t.dis[0] = x.dis[0] + y.dis[0];
	t.cnt[1] = x.cnt[1] + y.cnt[1]; t.dis[1] = x.dis[1] + y.dis[1];
	t.ans = x.ans + y.ans + x.cnt[0] * y.dis[1] - x.dis[0] * y.cnt[1] + x.cnt[1] * y.dis[0] - x.dis[1] * y.cnt[0];
	return t;
}

NODE operator - (const NODE &x, const NODE &y) {
	NODE t;
	t.cnt[0] = x.cnt[0] - y.cnt[0]; t.dis[0] = x.dis[0] - y.dis[0];
	t.cnt[1] = x.cnt[1] - y.cnt[1]; t.dis[1] = x.dis[1] - y.dis[1];
	t.ans = x.ans - y.ans + t.cnt[0] * x.dis[1] - t.dis[0] * x.cnt[1] + t.cnt[1] * x.dis[0] - t.dis[1] * x.cnt[0];
	return t;
}

NODE make(int x, int c) {
	NODE t; t.cnt[c] = 1; t.dis[c] = x; t.cnt[c ^ 1] = 0; t.dis[c ^ 1] = 0; t.ans = 0; return t;
}

int main() {
	n = read(); m = read(); scanf("%s", ch + 1);
	for (int i = 1; i <= n; i++) ans[i] = ans[i - 1] + make(i, ch[i] - '0');
	for (int i = 1; i <= m; i++) {
		int l = read(), r = read();
		printf("%d\n", 1ll * (ans[r] - ans[l - 1].ans) % mod);
	}
	return 0;
}
```