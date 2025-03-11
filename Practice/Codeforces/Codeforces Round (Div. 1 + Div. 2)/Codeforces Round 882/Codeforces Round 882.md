[Problem - A - Codeforces](https://codeforces.com/contest/1847/problem/A)

[Submission #212524742 - Codeforces](https://codeforces.com/contest/1847/submission/212524742)

考虑选中 $r_i$，即贡献中减去了 $|r_i - r_{i + 1}|$，差分后把差分序列排序，去掉最大的 $k$ 个贡献即可

[Problem - B - Codeforces](https://codeforces.com/contest/1847/problem/B)

[Submission #212524760 - Codeforces](https://codeforces.com/contest/1847/submission/212524760)

$a \& b \leq \min(a, b)$，于是贪心地不断把尽可能多的数与起来，如果全局按位与的值为 $0$，则将其分成尽可能多的 $0$ 段

[Problem - C - Codeforces](https://codeforces.com/contest/1847/problem/C)

[Submission #212524785 - Codeforces](https://codeforces.com/contest/1847/submission/212524785)

选一段区间并生成其异或和在数列末尾，考虑我们选择操作 $[r, n]$，操作完之后会发现 $[r, n + 1]$ 异或和为 $0$，这样我们每次操作都会使得一段后缀的异或和等于 $0$，于是我们能生成的最大的数字应当是原序列的最大异或和子区间，记录前缀异或和之后用 dp 或者 trie 跑一边即可

[Problem - D - Codeforces](https://codeforces.com/contest/1847/problem/D)

[Submission #217057295 - Codeforces](https://codeforces.com/contest/1847/submission/217057295)

考虑每个位置的数，对于若干连续子序列连接生成的新序列，其在新序列中相同元素的变化是统一的，于是每个元素只考虑其出现的第一次即可。该过程可以通过线段树或者并查集维护，这样就求出了每个位置的优先级 $r_i$。

然后考虑求出初始需要交换的次数，之后每一次都只有一个位置的数变动，记全局 $1$ 的数量为 $m$，优先级 $r_i\leq m$ 的位置的数量 $k$，则我们可以 $\mathcal{O}(1)$ 对这两个量进行更新