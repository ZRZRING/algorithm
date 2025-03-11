[Problem - E - Codeforces](https://codeforces.com/contest/1957/problem/E)

[Submission #258107078 - Codeforces](https://codeforces.com/contest/1957/submission/258107078)

从 $n$ 个数中选 $m$ 个数并组成一个排列方案数为 $A(n, m) = \binom{n}{m}\times m!$，对于每种圆排列，钦定一个起始位置后，可以表示为互不相同的排列，两个不同的圆排列也不可能表示出相同的排列，我们可以得到

$$
C(n, m) = \frac{A(n, m)}{m} = \frac{n(n-1)\cdots(n-m+1)}{m}
$$

我们知道，连续的 $m$ 个数在模 $m$ 意义下等价于 $0$ 到 $m - 1$，于是可以化为

$$
C(n, m) \equiv (m - 1)!\times \Big\lfloor\frac{n}{m}\Big\rfloor \pmod m
$$

根据威尔逊定理我们计算出 $(m - 1)! \bmod m$ 的值，在质数处为 $-1$，$m = 4$ 时为 $2$，其余时候均为 $0$，则我们调换原式的求和顺序，统计出所有质数，枚举其倍数进行计算贡献即可。

[威尔逊定理 - 维基百科，自由的百科全书 (wikipedia.org)](https://zh.wikipedia.org/wiki/%E5%A8%81%E5%B0%94%E9%80%8A%E5%AE%9A%E7%90%86)


![[Pasted image 20240425201110.png]]