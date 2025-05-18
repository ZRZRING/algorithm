[Problem - A - Codeforces](https://codeforces.com/contest/1867/problem/A)

[Submission #222912860 - Codeforces](https://codeforces.com/contest/1867/submission/222912860)

贪心让最大的和最小的作差。

[Problem - B - Codeforces](https://codeforces.com/contest/1867/problem/B)

[Submission #222934747 - Codeforces](https://codeforces.com/contest/1867/submission/222934747)

题目等价于，询问修改恰好 $t$ 个位置，能否使得 $s$ 变为回文串。

如果我们修改 $S$ 集合的位置的数可以达成条件，那么我们修改 $S$ 的补集的数也可以达成条件，可以得出结论，修改 $t$ 个位置和修改 $n + 1 - t$ 个位置的可行性是一样的，于是我们只需要判断修改 $t\leq n / 2$ 个字符能否使得 $s$ 变为回文串即可。

设至少需要修改 $k$ 个字符才能使 $s$ 变成回文串，当 $n$ 为偶数时，修改 $k + 1$ 个位置的数无法达到条件，而修改 $k + 2$ 个位置的数可以通过修改一对合法的回文位置的数达成目的，于是仅有 $k + a$，$a$ 为奇数时可以达成目标，当 $n$ 为奇数时，我们可以通过修改中间点使得修改 $k + 1$ 个位置的数达到条件，于是对于任意的 $a$，$k + a$ 都可以达成目标。

[Problem - C - Codeforces](https://codeforces.com/contest/1867/problem/C)

[Submission #222943882 - Codeforces](https://codeforces.com/contest/1867/submission/222943882)

第一步把当前 $\mathbf{MEX}$ 尽可能变大，后续电脑删啥补啥即可保持住第一步的 $\mathbf{MEX}$。

[Problem - D - Codeforces](https://codeforces.com/contest/1867/problem/D)

[Submission #222982755 - Codeforces](https://codeforces.com/contest/1867/submission/222982755)

考虑我们把序列抽象成一张图，$a_i$ 表示 $i$ 向 $a_i$ 连一条边，一次变换操作会使得 $\{a_{l_i}\}$ 构成一个环，于是我们找出图中所有的环，若存在长度不为 $k$ 的环即为非法。

由于 $a_i \geq 1$，则该图一定是一个基环树森林，于是不存在没有环的情况。