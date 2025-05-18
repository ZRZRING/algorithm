[Problem - D - Codeforces](https://codeforces.com/contest/1780/problem/D)

[Submission #191044742 - Codeforces](https://codeforces.com/contest/1780/submission/191044742)

二进制下 $10^9$ 刚好 $30$ 位，也就是说我们平均每一次操作要至少确定二进制下的一位，设 $x = \sum c_i * 2^i$，从 $i = 0$ 开始，我们如果减去 $2^i$ 后，返回值表示 $1$ 的数量变少了，那么 $c_i = 1$，否则 $c_i = 0$

注意每一次执行这个操作的时候只能代表当前的 $x$ 的情况，最后还是要靠这些信息推断原来的 $x$ 的信息的

[Problem - E - Codeforces](https://codeforces.com/contest/1780/problem/E)

[Submission #191631268 - Codeforces](https://codeforces.com/contest/1780/submission/191631268)

考虑每种边权是否存在于这张图上，对于 $i$，若其不存在于这张图的边权上，则该区间一定不存在任意 $x$，满足 $i | x$，使得 $x + i$ 也存在于这个区间，反之边权 $i$ 存在

于是我们需要找到所有满足 $\lfloor\frac{R}{i}\rfloor > \lceil\frac{L}{i}\rceil$ 的 $i$

考虑整除分块，对于连续的一段 $i\in [l, r]$，这一段里的 $i$ 不一定全部满足，容易考虑到我们需要找到最小的 $x$，使得 $\lceil\frac{L}{x}\rceil < \lfloor\frac{R}{i}\rfloor$，则 $x = \lceil\frac{L}{\lfloor\frac{R}{i}\rfloor - 1}\rceil$

[Problem - F - Codeforces](https://codeforces.com/contest/1780/problem/F)

[Submission #196352043 - Codeforces](https://codeforces.com/contest/1780/submission/196352043)

对 $a_i$ 排序，则需计算

$$
\sum_{i < k < j} [gcd(a_i, a_j) = 1]
$$

将艾弗森括号展开成莫比乌斯函数形式，并枚举 $k$

$$
\sum_k \sum_{i < k} \sum_{j > k} \sum_{d | a_i, d | a_j} \mu(d)
$$

对于 $k$，后面的可以 $\mathcal{O}(1)$ 转移，即每次把 $k - 1$ 对后面的贡献加上，$k$ 对前面的贡献减去
