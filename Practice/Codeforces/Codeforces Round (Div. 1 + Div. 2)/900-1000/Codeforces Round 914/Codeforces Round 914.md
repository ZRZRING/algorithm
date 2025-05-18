[Problem - C - Codeforces](https://codeforces.com/contest/1904/problem/C)

[Submission #236979336 - Codeforces](https://codeforces.com/contest/1904/submission/236979336)

> 给定数组 $a$，每次操作选取 $(i, j)$，向 $a$ 中添加 $|a_i - a_j|$，最小化 $k$ 次操作后 $a$ 数组中最小值。

$k\geq 3$ 时，我们可以随意将两个数做两次差并做差得到 $0$。

$k = 0$ 时，输出 $a$ 中最小值，$k = 1$ 时，输出 $a$ 和 $a$ 的任意两个数差的最小值。

$k = 2$ 时，问题等价于选任意两个数的和与一个数做差，预处理 $a$ 中任意两个数的和存入数组 $b$，将两个数组排序后双指针即可。

[Problem - D2 - Codeforces](https://codeforces.com/contest/1904/problem/D2)

[Submission #237033649 - Codeforces](https://codeforces.com/contest/1904/submission/237033649)

> 给定数组 $a, b$，每次操作可以选择一个区间 $[l, r]$，使得 $a$ 数组区间 $[l, r]$ 的值覆盖为 $\max_{i = l}^r a_i$，问能否将 $a$ 数组变为 $b$ 数组。

由于操作具有单调性，我们可以特判 $\exists i\in [1, n],a_i > b_i$。

考虑如果一个 $a_i$ 能变为 $b_i$，那么一定存在一个 $a_j = b_i(j\geq i)$，且对于 $\forall k\in [i, j], a_k\leq b_i, b_k\geq b_i$，$j\leq i$ 同理。这是由于我们不希望存在更大的 $a_k$ 使得更新 $a_i$ 后 $a_i = a_k > b_i$，并且我们不希望存在一个更小的 $b_k$ 使得更新 $a_i$ 后 $a_k = a_i > b_k$。

于是我们求出每个 $b_i$ 前后最近的 $a_j = b_i$，套一个 **RMQ** 模板即可。