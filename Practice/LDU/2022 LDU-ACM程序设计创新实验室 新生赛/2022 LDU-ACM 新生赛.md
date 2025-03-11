# 赛前预估

赛时估计难度 C J A B H，其他题基于大家做题经验太少就不好排序了，很抱歉给大家一场不太合格的比赛，下次新生赛还是给大家简单点的题做吧。

# A 窦树科技

当士兵相遇时，因为所有士兵对于这个问题而言是等价的，所以我们可以认为他们并没有原路返回，而是直接穿过去，所以直接对士兵初始位置到达两个端点分别取 $\min$ 和 $\max$，答案就由最慢的那个士兵决定。

```cpp
int n, m;

int main() {
	n = read(); int L = read(), mi = 0, mx = 0;
	for (int i = 1; i <= n; i++) {
		int x = read();
		mi = max(mi, min(L + 1 - x, x));
		mx = max(mx, max(L + 1 - x, x));
	}
	printf("%d %d\n", mi, mx);
	return 0;
}
```

# B 我的牌呢

一个贪心的思想是，最优解一定会保证我们在任意时刻我们的背包装的砖的数量尽可能多，这样我们才会最大限度的往前走

于是我们每次保证从 $i$ 跳到下一个位置 $i+1$ 之前先把 $i$ 位置的砖尽可能的取就行了

```cpp
int n, m, a[N];
 
int main() {
	int T = read();
	while (T--) {
		n = read(), m = read(); int k = read();
		a[1] = read(); bool flag = 1;
		for (int i = 2; i <= n; i++) {
			a[i] = read();
			if (a[i] < k) m += a[i - 1]; else m -= a[i] - (a[i - 1] + k);
			if (m < 0) flag = 0;
		}
		printf(flag ? "YES\n" : "NO\n");
	}
	return 0;
}
```

# C 生不逢七

签到题，按题意模拟即可

```cpp
int n, m;

int main() {
	int T = read();
	while (T--) {
		n = read(); int k = read(), a = read();
		for (int i = k + 1, j = 1; j <= a; i += n, j++) {
			int x = i; bool f = 0;
			while (x) {if (x % 10 == 7) {f = 1; break;} x /= 10;}
			if (f || i % 7 == 0) printf("p "); else printf("%d ", i);
		}
		printf("\n");
	}
	return 0;
}
```

# DE 悄无声息

本题的 hard version 是这次比赛最难的问题

首先考虑 easy version，因为 $t$ 很小，所以我们可以模拟每一个分身走的轨迹，然后对棋盘进行对应的修改，复杂度 $\mathcal{O}(t)$

注意到每个士兵的坐标 $(x, y)$，因为每次行动只会走到 $(x + 1, y)$ 或者 $(x, y + 1)$，$x + y$ 的值每次都会增长 $1$，那么对于棋盘上 $x + y = k$ 这条线上一定只有一个分身，从而可以推出每个位置一定同时只存在一个分身

我们也可以用这个方法推断出 $t$ 秒可能到达 $(x,y)$ 的分身只有可能在 $t - x - y$ 秒在 $(0, 0)$ 出现，对于 hard version，$t$ 非常大，但是我们发现对于一个格子，经过这个格子的分身中，有一半上取整去了右边，有一半下取整去了下面，而我们只关心在 $t - x - y$ 秒出现的分身，我们可以让这个分身之前出现的分身去跑一遍这个棋盘，用上面的结论我们可以得出 $100\times 100$ 区间内所有格子经过的分身数量，从而知道在 $t - x - y$ 秒出现的分身开始行走时整个棋盘的状态，模拟一遍即可，复杂度 $\mathcal{O}(xy)$

```cpp
int n, m, f[N][N];

signed main() {
	int T = 0; cin >> T;
	while (T--) {
		n = read(); int x = read(), y = read();
		if (n < x + y) {printf("NO\n"); continue;}
		f[0][0] = n - x - y;
		for (int i = 0; i <= 100; i++) {
			for (int j = 0; j <= 100; j++) {
				if (i == 0 && j == 0) continue; f[i][j] = 0;
				if (i) f[i][j] += f[i - 1][j] >> 1;
				if (j) f[i][j] += f[i][j - 1] + 1 >> 1;
			}
		}
		int goal = x + y, X = x, Y = y; x = 0; y = 0;
		while (x + y < goal) {
			if (f[x][y] % 2 == 0) y++; else x++;
		}
		printf(x == X && y == Y ? "YES\n" : "NO\n");
	}
	return 0;
}
```

# FG 德国心脏病

直接按照题意模拟即可，注意每次覆盖要消除上一次的影响，对于 easy version，每次翻牌遍历场上牌判断即可，对于 hard version，需要每次翻牌立即对可能产生影响的牌进行判断，可以使用 map 直接使用字符作为下标，使代码简洁明了

```cpp
char ch[N][10];

int n, m, a[N];

map<char, int>mp;

int main() {
	int T = read();
	while (T--) {
		n = read(); int k = read(); bool f = 0;
		for (int i = 0; i < k; i++) {
			scanf("%s", ch[i]);
			if (ch[i][0] != 'E' && ch[i][0] != 'P' && ch[i][0] != 'M') a[i] = read(); else a[i] = 1;
		}
		for (int i = 0; i < k; i++) {
			if (ch[i][0] == 'P') {printf("%d\n", i % n + 1); f = 1; break;} // 猪
			if (i - n >= 0) { // 消除上一轮影响
				if (ch[i - n][0] == 'S') { // 草莓对于象
					mp['S'] -= a[i - n];
					if (!mp['S'] && mp['E'] && (ch[i][0] != 'S' || a[i] == 0)) {
						printf("%d\n", i % n + 1); f = 1; break;
					}
				} else
				if (ch[i - n][0] == 'L') { // 柠檬对于猴子
					mp['L'] -= a[i - n];
					if (!mp['L'] && mp['M'] && (ch[i][0] != 'L' || a[i] == 0)) {
						printf("%d\n", i % n + 1); f = 1; break;
					}
				} else mp[ch[i - n][0]] -= a[i - n];
			}
			if (ch[i][0] == 'E') { // 象对于草莓
				if (mp['S'] == 0) {printf("%d\n", i % n + 1); f = 1; break;} mp[ch[i][0]] += a[i];
			} else
			if (ch[i][0] == 'M') { // 猴子对于柠檬
				if (mp['L'] == 0) {printf("%d\n", i % n + 1); f = 1; break;} mp[ch[i][0]] += a[i];
			} else mp[ch[i][0]] += a[i]; // 水果
			if (ch[i][0] != 'E' && ch[i][0] != 'M' && mp[ch[i][0]] == 5) {
				printf("%d\n", i % n + 1); f = 1; break;
			}
			if (ch[i - n][0] != 'E' && ch[i - n][0] != 'M' && mp[ch[i - n][0]] == 5) {
				printf("%d\n", i % n + 1); f = 1; break;
			}
		}
		if (!f) printf("-1\n"); mp.clear();
	}
	return 0;
}
```

# H 均衡之光·马龙

著名的海盗分赃博弈，本题只需要达到一半人数就可以通过，和原本的问题中超过一半人数不太一样

考虑 $2$ 个人的时候是 **1000 0**，那么 $3$ 个人的时候，如果第一个人提出 **999 0 1** 的方案的话，第三个人就能获得 $1$ 个金币，那么他肯定同意第一个人的方案，于是超过一半人同意，考虑 $4$ 个人，如果第一个人提出 **999 0 1 0** 的方案的话，第三个人也会同意他的方案，因为如果不同意变成 $3$ 个人的情况，他将没有金币可以拿

以此类推，每次让少一个人的方案中有金币的人给他 $0$ 个金币，没有金币的人给他 $1$ 个金币，自己拿走剩下的所有钱，即为最优解

```cpp
int n, m, a[110][110];

int main() {
	int T = read();
	a[1][1] = 1000;
	for (int i = 2; i <= 100; i++) {
		int sum = 0;
		for (int j = 2; j <= i; j++) a[i][j] = !a[i - 1][j - 1], sum += a[i][j];
		a[i][1] = 1000 - sum;
	}
	while (T--) {
		n = read();
		for (int i = 1; i <= n; i++) printf("%d ", a[n][i]); printf("\n");
	}
	return 0;
}
```

# I 夜月之刃·里欧德

考虑对于一个位置 $r$，如果一个区间 $[l,r], l < r$ 符合条件，那么 $[l + 1, r]$ 一定也符合条件

于是我们可以对于每个 $r$ 找到最左边的 $l$，那么对于 $r$ 我们可以记录 $r - l + 1$ 个区间的贡献

然后我们发现对于一个位置 $i$，记可以延伸到最左边的地方为 $i - f_i + 1$（也可以认为第 $i$ 个位置可以往左延伸 $f_i$ 的长度），计算 $f_i$ 时，我们可以得到关系式

$$
f_i = min(f_{i - 1} + 1, a_i)
$$

答案对 $f_i$ 求和即可

```cpp
int n, m, a[N];
 
int main() {
	int T = read();
	while (T--) {
		n = read(); int last = 0; long long ans = 0;
		for (int i = 1; i <= n; i++) {
			int x = read(); if (x >= last + 1) last++; else last = x; ans += min(last, x);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
```

# J 天外之花·爱莲娜

一个贪心的策略即为将 $a_i$ 从大到小排序并将 $b_i$ 从小到大排序，如果这样重排都不能做到的话，这个序列任意重排都做不到

注意数据范围，请使用快速排序

```cpp
int n, x, cnt, a[N], b[N];
 
bool cmp(int a, int b) {return a > b;}
 
int main() {
	int T = read();
	while (T--) {
		n = read(); x = read(); int flag = 0;
		for (int i = 1; i <= n; i++) a[i] = read();
		for (int i = 1; i <= n; i++) b[i] = read();
		sort(a + 1, a + n + 1); sort(b + 1, b + n + 1, cmp);
		for (int i = 1; i <= n; i++) if (a[i] + b[i] > x) {flag = 1; break;}
		if (flag) printf("NO\n"); else printf("YES\n");
	}
	return 0;
}
```

# K 兽人战士·赛德斯

将合法括号串的位置设为 $1$，其他位置设为 $0$，直接计算每一段连续的 $1$ 的长度即可

```cpp
int n, m, s[N];

bool p[N];

char ch[N];

int main() {
	int T = read();
	while (T--) {
		scanf("%s", ch + 1); n = strlen(ch + 1); int top = 0, ans = 0, cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (ch[i] == '(') s[++top] = i; else if (top) {p[s[top--]] = p[i] = 1;}
		}
		for (int i = 1; i <= n; i++) {
			int res = 0; while (p[i]) res++, i++;
			if (res > ans) ans = res, cnt = 1;
			else if (res == ans) cnt++;
		}
		for (int i = 1; i <= n; i++) p[i] = 0;
		printf("%d %d\n", ans, ans ? cnt : 1);
	}
	return 0;
}
```

# L 禁断之腕·尼古拉

加法和异或运算都有逆运算，其中异或的逆运算为它本身，差分即可

```cpp
int n, m, a[N], xr[N], sm[N];

int main() {
	n = read(); m = read();
	for (int i = 1; i <= n; i++) a[i] = read(), xr[i] = xr[i - 1] ^ a[i], sm[i] = sm[i - 1] + a[i];
	for (int i = 1; i <= m; i++) {
		int l = read(), r = read();
		printf("%d\n", sm[r] - sm[l - 1] - (xr[r] ^ xr[l - 1]));
	}
	return 0;
}
```

# M 肃清的英雄·梅希亚

首先如果一个数被增加了，那么这个数已经超过了之后将要取的数，可以理解为直接将这个数删除

因为是从大到小取数，考虑最小的数最好用，所以最坏情况就是每次能量溢出影响的数都为最小的数，并且自己每次取数都会取当前能取的数里最大的数，按这样操作枚举 $k$ 模拟可行性即可

```cpp
int n, m, a[N];

int main() {
	int T = read();
	while (T--) {
		n = read();
		for (int i = 1; i <= n; i++) a[i] = read();
		sort(a + 1, a + n + 1); int ans = 0;
		for (int k = n; k >= 1; k--) {
			bool flag = 1; int x = n;
			for (int i = 1; i <= k; i++) {
				while (a[x] > k - i + 1) x--;
				if (x <= i - 1) {flag = 0; break;} x--;
			}
			if (flag) {ans = k; break;}
		}
		printf("%d\n", ans);
	}
	return 0;
}
```