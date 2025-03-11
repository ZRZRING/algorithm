记 $n = |S|, m = |T|$，首先 $|S'| = |T'| = k\times lcm(n, m)$，其中 $k$ 为任意正整数

考虑如果我们有了一个 $T$，对于每个 $T_i$，找出该位置在 $S'$ 中的匹配集合，那么 $T_i$ 取自己的匹配集合中出现次数最多的字母能最大化匹配，这样枚举 $T$ 的长度，找到匹配数大于 $\displaystyle\left\lfloor\frac{n}{2}\right\rfloor$ 最短的那个 $T$ 即可，时间复杂度 $\mathcal{O}(n^2)$

$T_i$ 的匹配集合是 $i + k\times \gcd(n, m)$，也就是说 $\gcd(n, m)\not = m$ 的话，一定存在有相同匹配集合的 $i$

重复贡献并不会增加答案，所以如果 $\gcd(n, m_0)\not = m_0$，$m_0$ 的答案和 $m = \displaystyle\frac{m_0}{\gcd(n, m_0)}$ 的答案一样

所以我们只需要枚举 $n$ 的约数即可，复杂度 $\mathcal{O}(nd(n))$，其中 $d(n)$ 表示 $n$ 的约数个数

构造字典序最小的操作，每次对于当前最优的后缀，判断当前枚举到的字母是否满足题目要求即可，复杂度 $\mathcal{O}(nd(n) + 26n)$。

```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1e6 + 10, M = 2e6 + 10, inf = 0x3f3f3f3f;

const long long Linf = 0x3f3f3f3f3f3f3f3f;

inline int read() {
	bool sym = 0; int res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int n, m, cnt, dat[N], vis[N][26], suf[N];

char ch[N], ans[N];

int main() {
	int T = read();
	while (T--) {
		scanf("%s", ch + 1); n = strlen(ch + 1); bool flag = 1; cnt = 0;
		memset(ans, '\0', sizeof(ans));
		for (int i = 1; i <= sqrt(n) + 1; i++) {
			if (n % i == 0) dat[++cnt] = i, dat[++cnt] = n / i;
		}
		sort(dat + 1, dat + cnt + 1);
		for (int i = 1; i <= cnt; i++) {
			int len = dat[i], res = 0;
			for (int s = 1; s <= len; s++) {
				memset(vis[s], 0, sizeof(vis[s]));
				for (int i = s; i <= n; i += len) {
					vis[s][ch[i] - 'a']++; suf[s] = max(suf[s], vis[s][ch[i] - 'a']);
				}
			}
			for (int i = len - 1; i >= 1; i--) suf[i] += suf[i + 1];
			if (suf[1] >= (n + 1) / 2) {
				int sum = 0;
				for (int s = 1; s <= len; s++) for (int i = 0; i < 26; i++) {
					if (vis[s][i] + sum + suf[s + 1] >= (n + 1) / 2) {
						sum += vis[s][i]; ans[s] = i + 'a'; break;
					}
				}
				for (int i = 1; i <= len; i++) suf[i] = 0; break;
			}
			for (int i = 1; i <= len; i++) suf[i] = 0;
		}
		puts(ans + 1);
	}
	return 0;
}