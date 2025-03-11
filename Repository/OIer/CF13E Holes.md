和弹飞绵羊一样，多维护一个出块时最后一个点就行了，弹飞绵羊写的LCT，那写一个分块题解

考虑询问模拟链表走一直到出去，最差复杂度$\mathcal{O}(mn)$，我们可以把若干点合成一个块，维护块内所有点走出这个块的步数，修改就重新计算这个块所有点的答案，这个过程复杂度取决于块大小，而这样询问复杂度取决于块数量，于是块取根号可以做到平衡，复杂度$\mathcal{O}(m\sqrt{n})$

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

int n, m, cnt, to[N], val[N], k[N], l[N], r[N], bel[N], last[N];

int main() {
	n = read(); m = read();
	for (int i = 1; i <= n; i++) k[i] = read();
	int S = sqrt(n);
	for (int i = 1; i <= n; i += S) {
		l[++cnt] = i; r[cnt] = min(i + S - 1, n);
	}
	for (int i = 1; i <= cnt; i++) {
		for (int j = l[i]; j <= r[i]; j++) bel[j] = i;
	}
	for (int i = n; i >= 1; i--) {
		if (i + k[i] > r[bel[i]]) to[i] = i + k[i], last[i] = i, val[i] = 1;
		else to[i] = to[i + k[i]], last[i] = last[i + k[i]], val[i] = val[i + k[i]] + 1;
	}
	for (int i = 1; i <= m; i++) {
		int opt = read();
		if (opt == 0) {
			int x = read(), t = read(); k[x] = t;
			for (int i = r[bel[x]]; i >= l[bel[x]]; i--) {
				if (i + k[i] > r[bel[i]]) to[i] = i + k[i], last[i] = i, val[i] = 1;
				else to[i] = to[i + k[i]], last[i] = last[i + k[i]], val[i] = val[i + k[i]] + 1;
			}
		}
		if (opt == 1) {
			int x = read(), res = 0;
			while (to[x] <= n) res += val[x], x = to[x]; res += val[x];
			printf("%d %d\n", last[x], res);
		}
	}
	return 0;
}
```