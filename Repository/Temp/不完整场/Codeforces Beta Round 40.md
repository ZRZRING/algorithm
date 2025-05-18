[Problem - D - Codeforces](https://codeforces.com/contest/41/problem/D)

[Submission #217245416 - Codeforces](https://codeforces.com/contest/41/submission/217245416)

显然没有被一个数整除的条件这个题是一个简单题，$f_{i, j}$ 表示从第 $n$ 行走到 $(i, j)$ 所能取到的最大值

但是多了一个条件感觉非常棘手，因为一个方案的结果可能被 $p + 1$ 整除的时候不一定是最优解，所以我们加一维 $k$ 表示我们走到 $(i, j)$ 能否取到 $k$ 个豆子


