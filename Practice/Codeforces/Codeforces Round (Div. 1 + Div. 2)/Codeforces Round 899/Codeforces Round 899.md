[Problem - A - Codeforces](https://codeforces.com/contest/1882/problem/A)

[Submission #225094885 - Codeforces](https://codeforces.com/contest/1882/submission/225094885)

每个位置贪心取当前能取到的最小的数即可。

[Problem - B - Codeforces](https://codeforces.com/contest/1882/problem/B)

[Submission #225111725 - Codeforces](https://codeforces.com/contest/1882/submission/225111725)

钦定最终集合里不存在 $i$，枚举 $i$ 计算最终集合大小，取最小值即可。

[Problem - C - Codeforces](https://codeforces.com/contest/1882/problem/C)

[Submission #225123945 - Codeforces](https://codeforces.com/contest/1882/submission/225123945)

一种显然的思路尽可能让所有正数都在奇数位置被取，我们考虑第三张牌以后的牌，每次取最后一张奇数位置的正数，直到不能取为止，我们从前两张里选一张，再执行上述操作，可以将所有原始序列中第三张牌及其之后的所有正数牌取完，于是我们计算全局正数和，并对前两张牌分类讨论即可。

[Problem - D - Codeforces](https://codeforces.com/contest/1882/problem/D)

[Submission #225148240 - Codeforces](https://codeforces.com/contest/1882/submission/225148240)

记 $f_u$ 表示 $u$ 的父亲节点，考虑我们对于将整棵树的问题沿着树分治到各个子树中，我们每一步所作的事情是唯一确定的，且不会对分治前的状态有影响，故最终答案为

$$
\sum size_u\times (a_u\oplus a_{f_u})
$$

换根 dp 即可。