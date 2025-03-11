[Problem - A - Codeforces](https://codeforces.com/contest/1862/problem/A)

[Submission #220163398 - Codeforces](https://codeforces.com/contest/1862/submission/220163398)

如果出现前置字母，再判断后续字母即可。

[Problem - B - Codeforces](https://codeforces.com/contest/1862/problem/B)

[Submission #220173076 - Codeforces](https://codeforces.com/contest/1862/submission/220173076)

如果 $a_{i - 1} \leq a_{i}$，那么不用添加任何数字，反之在这之前添加一个 $a_i$。

[Problem - C - Codeforces](https://codeforces.com/contest/1862/problem/C)

[Submission #220173076 - Codeforces](https://codeforces.com/contest/1862/submission/220173076)

计算出转置后的积木群，判断是否等价即可。

[Problem - D - Codeforces](https://codeforces.com/contest/1862/problem/D)

[Submission #220237376 - Codeforces](https://codeforces.com/contest/1862/submission/220237376)

容易发现每种颜色最多使用两个，否则会产生浪费，于是记选择 $m$ 种颜色，其中 $k$ $(k \leq m)$种颜色使用两个，计算满足 $\frac{m(m + 1)}{2} + k = n$ 情况下最小化 $m + k$，因为已知 $m$ 可以快速求出 $k$，于是令 $m$ 在 $[\sqrt{2n} - a, \sqrt{2n} + a]$ 区间内计算一个最小值即可，实测 $a = 100$ 可以通过此题。

[Problem - E - Codeforces](https://codeforces.com/contest/1862/problem/E)

[Submission #220255567 - Codeforces](https://codeforces.com/contest/1862/submission/220255567)

考虑如果我们已知最后一次买票是在第 $i$ 天，则我们为此消耗的 $d$ 的数量即为 $i$，其为定值，于是我们枚举 $i$， 对于前 $i$ 天我们维护前 $m$ 大的娱乐价值，用一个堆即可实现 $\mathcal O(\log n)$ 转移。

[Problem - F - Codeforces](https://codeforces.com/contest/1862/problem/F)

[Submission #220334953 - Codeforces](https://codeforces.com/contest/1862/submission/220334953)

计算出怪物需要的魔法总量，再用 01 背包算出若干怪物可以刚好被多少数量的魔法打死，则我们用其中一种魔法，剩下的用另一种魔法打死即可，二分时间算出最小花费的时间。