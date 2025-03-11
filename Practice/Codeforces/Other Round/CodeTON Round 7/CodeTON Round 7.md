[Problem - C - Codeforces](https://codeforces.com/contest/1896/problem/C)

[Submission #234292313 - Codeforces](https://codeforces.com/contest/1896/submission/234292313)

> 给定序列 $a, b$，对序列 $b$ 重排，使得 $a_i > b_i$ 的位置恰好 $x$ 个。

贪心，类似于田忌赛马，我们先贪心让 $a$ 的最大的元素和 $b$ 的最小的元素配对，凑够 $x$ 对，这样肯定能尽可能凑出更多的匹配，剩下的从小到大对应，因为 $b$ 剩余的元素是 $b$ 中最大的，$a$ 中剩余元素是 $a$ 中最小的，刚好能满足贪心需求。

[Problem - D - Codeforces](https://codeforces.com/contest/1896/problem/D)

[Submission #234304493 - Codeforces](https://codeforces.com/contest/1896/submission/234304493)

> 给定序列 $a_i\in \{1, 2\}$，你需要支持两种操作：查询是否存在一个子段和为 $s$。将 $a_i$ 修改为 $t\in \{1, 2\}$。

我们记 $A$ 为小于等于该子段的和所有正整数的集合，考虑对于一个 $1$，如果其为一个子段的右端点，那么对于这个子段，去掉这个 $1$ 的所有后缀可以表示出集合 $S = \{s_i\}$，加上这个 $1$ 的所有后缀可以表示出集合 $S' = \{s_i + 1\}$，由于值域 $\{1, 2\}$ ，故 $S\cup S' = A$。

所以我们可以得出结论，最左边的 $1$ 的后缀和和最右边的 $1$ 的前缀和一定都能表示出来，除此以外，向外扩展一定是不断添加 $2$。

于是我们需要一种数据结构维护上述答案，这里我使用的线段树，其实堆，树状数组，set 等数据结构也可以维护。