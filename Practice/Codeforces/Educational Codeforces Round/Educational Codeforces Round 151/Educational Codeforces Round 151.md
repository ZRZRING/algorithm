[Problem - D - Codeforces](https://codeforces.com/contest/1845/problem/D)

[Submission #211599463 - Codeforces](https://codeforces.com/contest/1845/submission/211599463)

- 给定你近期 rating 变化，你可以指定一个 $k$，当你 rating 大于等于 $k$ 之后你的 rating 不会掉到小于 $k$ 的区间，求你能达到最高的 rating 时你应该取的 $k$ 是多少

考虑我们用 $k$ 去消除最小子段和的影响一定是最优解，于是我们令 $k$ 为最小子段和前的第一个前缀和即可。

上述为我做这个题的第一想法，但一直苦于无法证明，就有了以下做法。

考虑如果我们能够达到 $k$，我们一定会存在某个时间节点使得 rating 达到 $k$，并且后续将不会低于 $k$，这样的话我们最终的 rating 一定是 $k$ $+$ 一段后缀，于是我们枚举后缀和，然后对于每个后缀和找到对应的最大的 $k$，显然这个 $k$ 一定是该后缀前最大的前缀和，最后对于上述贡献取 $\max$ 即为答案。