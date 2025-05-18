[Problem - A - Codeforces](https://codeforces.com/contest/1855/problem/A)

[Submission #216237881 - Codeforces](https://codeforces.com/contest/1855/submission/216237881)

贪心的让每对坐到自己编号的位置上的同学交换座位，剩下一个同学随便与一个同学交换。

[Problem - B - Codeforces](https://codeforces.com/contest/1855/problem/B)

[Submission #216474837 - Codeforces](https://codeforces.com/contest/1855/submission/216474837)

一定存在一个最大区间的左端点为 $1$，这是因为，考虑每 $a$ 个连续的数一定存在一个数 $b$ 使得 $a | b$，若 $i\in [l, r]$ 都有 $i | n$ ，则一定存在 $(r - l + 1) | n$， 于是对于 $i\in [1, r - l + 1]$ 一定存在 $i | n$

[Problem - C2 - Codeforces](https://codeforces.com/contest/1855/problem/C2)

[Submission #216841201 - Codeforces](https://codeforces.com/contest/1855/submission/216841201)

考虑如果数全正或者全负，最优方法是类似与求前缀和一样的操作，操作次数 $19$

这样如果我们最大值加最小值大于 $0$ 的话，我们可以用最大值去填补所有的负数，使序列全正，这样情况下负数不能超过 $12$ 个

若负数超过 $12$ 个，则正数很少，考虑我们让一个负数不断倍增，只需要至多 $5$ 次即可超过最大的正数，而此时正数最多只有 $7$ 个，于是可以在 $31$ 次操作以内完成

[Problem - D - Codeforces](https://codeforces.com/contest/1855/problem/D)

[Submission #217230197 - Codeforces](https://codeforces.com/contest/1855/submission/217230197)

记 $f_{i, j}$ 表示是否可以只使用前 $i$ 张牌用于解锁，并且解锁了 $j$ 张牌。

考虑解锁了的牌我们一定会用，则我们只需要设置状态 $f_j$ 表示是否可以解锁 $j$ 张牌即可，这时得分即为解锁的牌分数之和减去解锁的牌数。

由于我们可能解锁超过总数的牌，那么我们可以将其视为给牌库扩充若干 $0$ 牌，且转移的时候会发现，我们要使用第 $i$ 张牌的话，我们至少要解锁到第 $i$ 张牌，于是只有 $f_{j(j\geq i)}$ 的状态可以用于转移。

我们扩充的 $0$ 牌不会超过 $n$ 张，这是由于若我们扩充了超过 $n$ 张的 $0$ 牌，用于解锁这些多余牌的牌用于直接得分，结果一定不会更劣。

复杂度 $\mathcal{O}(n ^ 2)$，可以使用 bitset 优化常数