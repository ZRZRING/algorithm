https://www.luogu.com.cn/problem/P8848

> 给定一个由 $1$ 和 $-1$ 序列 $a$，询问有多少个将 $a$ 重排后的序列使得该序列的最大子段和最小化，称两个序列不同，当且仅当这两个序列有任意一个位置上的数不同

考虑最大的最大字段和的一个区间 $[l,r]$，$a_{l-1}$ 和 $a_{r+1}$ 一定是 $-1$，令 $1$ 的数量为 $A$，$-1$ 的数量为 $B$，若 $A>B$，那么全局和 $A-B$ 一定是最大字段和的下界，否则下界为 $1$

考虑如何取到下界，若 $A\leq B$，我们要保证每个 $1$ 的相邻位置都为 $-1$，经典插板法，方案数即为 $\binom{B + 1}{A}$

若 $A>B$，该问题就可以转化成走格子，每次可以从 $(i, j)$ 走到 $(i + 1, j + 1)$ 或 $(i + 1, j - 1)$，且不能走到 $y = -1$ 以及 $y = A - B + 1$ 两条线，最后要求的就是走到 $(n, A - B)$ 的方案数，简单DP即可，复杂度 $\mathcal{O}(n^2)$

参考 [P3266 [JLOI2015]骗我呢](https://www.luogu.com.cn/problem/P3266) 可以做到 $\mathcal{O}(n)$ 的复杂度

这里给出 $\mathcal{O}(n^2)$ 的代码

```cpp
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

const int N = 2e6 + 10, mod = 998244353;

inline int read() {
	bool sym = 0; int res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int n, m, k, cnt1, cnt2, mul[N], f[2][10010];

int qpow(int a, int x) {
	int res = 1;
	while (x) {if (x & 1) res = 1ll * res * a % mod; a = 1ll * a * a % mod; x >>= 1;}
	return res;
}

int C(int n, int m) {
	return 1ll * mul[n] * qpow(mul[m], mod - 2) % mod * qpow(mul[n - m], mod - 2) % mod;
}

int main() {
	n = read(); mul[0] = 1;
	for (int i = 1; i <= 100000; i++) mul[i] = 1ll * mul[i - 1] * i % mod;
	for (int i = 1; i <= n; i++) if (read() == 1) cnt1++; else cnt2++;
	if ((cnt1 == 1 || cnt2 == 1) && n == 1) {printf("2"); return 0;}
	if (cnt1 == 1 && cnt2 == 1) {printf("2"); return 0;}
	if (cnt1 == 1 && cnt2 == 2) {printf("3"); return 0;}
	if (cnt1 == cnt2) {printf("%d", n / 2 + 1); return 0;}
	if (cnt1 < cnt2) {printf("%d", C(cnt2 + 1, cnt1)); return 0;}
	f[0][0] = 1; m = cnt1 - cnt2;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= min(i, m); j++) {
			f[i & 1][j] = 0;
			if (j - 1 >= 0) f[i & 1][j] = f[i & 1 ^ 1][j - 1];
			if (j + 1 <= m + 1) f[i & 1][j] = 1ll * (f[i & 1][j] + f[i & 1 ^ 1][j + 1]) % mod;
		}
		// for (int j = 0; j <= m; j++) printf("%d ", f[i & 1][j]); printf("\n");
	}
	printf("%d", f[n & 1][cnt1 - cnt2]);
	return 0;
}
```