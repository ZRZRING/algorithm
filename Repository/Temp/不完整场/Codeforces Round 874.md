[Problem - D - Codeforces](https://codeforces.com/contest/1833/problem/D)

[Submission #217241985 - Codeforces](https://codeforces.com/contest/1833/submission/217241985)

类似于将原排列如下图顺序构造，其中 1 和 3 可以省略，2 必须满足一个奇怪的式子

容易想到贪心得让第一个位置为 $n$，然后对于 2 和 3，我们从 2 的起点开始依次和第一个数进行比较即可确定 2 和 3 的断点位置

当 $n$ 为第一个数时，其若存在为线段1则无法再划出一条线段 2，于是 $n$ 为第一个数时无法使一次操作后的序列第一个数为 $n$，于是考虑让第一个数为 $n - 1$，后续过程同上
