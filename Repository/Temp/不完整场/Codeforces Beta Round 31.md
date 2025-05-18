[Problem - D - Codeforces](https://codeforces.com/contest/31/problem/D)

[Submission #217245551 - Codeforces](https://codeforces.com/contest/31/submission/217245551)

我们考虑线性做法 ~~O(n) 跑 18~~，我们已经在 A 和 B 中放好了 S 的前 i 个数，其中 A 放了 j 个，B 放了 k 个，那么我们对于第 i + 1 个数，它可以放在 A 或 B 的末尾，于是我们有了状态转移方程

$$
f_{i, j, k} = \max\{f_{i - 1, j - 1, k} + 10^{n - j} s_i, f_{i - 1, j, k - 1} + 10^{n - k} s_i\}
$$
放数的时候注意是从最高位开始放