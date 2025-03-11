考虑要计算的总贡献，对于每个人的$c_i$给定一个系数，这个系数为这个伤害的贡献

如果考虑每种方案的话，这个伤害会从起点顺着一条连续的链进行数次贡献，直到这个伤害被末尾的人往回打，这样的话我们还是得枚举所有情况的所有链

一条链可以在每一阶段都进行一次贡献，我们把它拆开单独考虑这个贡献的长度，这样一来$c_i$确定，路径上的$k_i$也确定，每次的贡献的伤害量都是确定的，我们就可以对于重复的贡献进行统一计算了

钦定目前这个人的攻击会途径$x$个人，并把这$x$个人的$k_i$乘上，这条链的最后一个人会有一个攻击目标，我们不管这个攻击目标是谁，这个伤害总会释放出去，就是这个攻击造成的一次贡献，再乘上满足上述条件的方案数即可

枚举每个人并枚举伤害经过的人数，能得到原式

$$
\sum_{i = 1}^{n} c_i \times \left(\sum_{j = 0}^{n - 1}2^{n - j}\binom{n}{j + 1}(n - j - 1)!\left(\prod_{l = i + 1}^{i + j}k_l + \prod_{l = i - j}^{i - 1}k_l\right)\right)
$$

简单处理一下就有40分了

考虑到中间几项只和$j$有关，把$c_i$乘进去，提取出$j = 0$项，对后面的用差分处理，把加号拆开，可以得到

$$
\sum_{i = 1}^{n}2^{n + 1}c_in! + \sum_{i = 1}^{n}\sum_{j = 1}^{n - 1}\frac{f(j)g_1(i + j)}{g_2(i)} + \sum_{i = 1}^{n}\sum_{j = 1}^{n - 1}\frac{f(j)g_3(i)}{g_4(i - j)}
$$

化式子都是基础，所以我就为了简洁明了直接用函数代替了，那么这个式子直接卷积计算即可，复杂度$\mathcal{O}(n\log n)$

```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

#define inv3 332748118
#define file(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout);

using namespace std;

const int N = 2e6 + 10, mod = 998244353;

inline int read() {
	bool sym = 0; int res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int n, m, ans, rev[N], c[N], r[N], W[2][N];

int mul[N], rmul[N], irmul[N], inv[N], C[N];

int f[N], g1[N], g2[N], g3[N], g4[N];

void MOD(int &x) {while (x >= mod) x -= mod; while (x < 0) x += mod;}

int power(int a, int x) {
	int res = 1;
	while (x) {if (x & 1) res = 1ll * res * a % mod; a = 1ll * a * a % mod; x >>= 1;}
	return res;
}

void init() {
	m = 1; while (m <= 3 * n) m <<= 1;
	for (int i = 0; i < m; i++) rev[i] = rev[i >> 1] >> 1 | (i & 1 ? m >> 1 : 0);
	mul[0] = rmul[0] = inv[1] = 1; C[1] = n;
	for (int i = 1; i <= n; i++) mul[i] = 1ll * mul[i - 1] * i % mod;
	for (int i = 2; i <= m; i++) inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
	for (int i = 2; i <= n; i++) C[i] = 1ll * C[i - 1] * (n - i + 1) % mod * inv[i] % mod;
	for (int i = 1; i <= 3 * n; i++) rmul[i] = 1ll * rmul[i - 1] * r[i] % mod;
	for (int i = 1; i <= 3 * n; i++) irmul[i] = power(rmul[i], mod - 2);
	for (int i = 1; i <= n - 1; i++) f[i] = 1ll * C[i + 1] * mul[n - i - 1] % mod * power(2, n - i) % mod;
	for (int i = n + 2; i <= 3 * n - 1; i++) g1[i] = rmul[i];
	for (int i = n + 1; i <= 2 * n; i++) g2[i] = 1ll * irmul[i] * c[i] % mod;
	for (int i = n + 1; i <= 2 * n; i++) g3[i] = 1ll * rmul[i - 1] * c[i] % mod;
	for (int i = 2; i <= 2 * n - 1; i++) g4[i] = irmul[i - 1];
	for (int i = 1; i < m; i <<= 1) {
		W[0][i] = power(inv3, (mod - 1) / (i << 1));
		W[1][i] = power(3, (mod - 1) / (i << 1));
	}
}

void ntt(int a[], int opt) {
	for (int i = 0; i < m; i++) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int i = 1; i < m; i <<= 1) {
		int t = W[opt][i];
		for (int j = 0; j < m; j += i << 1) {
			int w = 1;
			for (int k = j; k < j + i; k++) {
				int x = a[k], d = 1ll * w * a[k + i] % mod;
				MOD(a[k] = x + d); MOD(a[k + i] = x - d); w = 1ll * w * t % mod;
			}
		}
	}
	if (!opt) {for (int i = 0; i < m; i++) a[i] = 1ll * a[i] * inv[m] % mod;}
}

int main() {
	n = read();
	for (int i = 1; i <= n; i++) c[i + n] = read(), MOD(ans += c[i + n]);
	for (int i = 1; i <= n; i++) r[i] = r[i + n] = r[i + 2 * n] = read();
	init(); ans = 1ll * ans * mul[n] % mod * power(2, n) % mod;
	ntt(f, 1); ntt(g2, 1); ntt(g4, 1);
	for (int i = 0; i < m; i++) g2[i] = 1ll * g2[i] * f[i] % mod, g4[i] = 1ll * g4[i] * f[i] % mod;
	ntt(g2, 0); ntt(g4, 0);
	for (int i = n + 2; i <= 3 * n - 1; i++) MOD(ans += 1ll * g1[i] * g2[i] % mod);
	for (int i = n + 1; i <= 2 * n; i++) MOD(ans += 1ll * g3[i] * g4[i] % mod);
	printf("%d", ans);
	return 0;
}
```