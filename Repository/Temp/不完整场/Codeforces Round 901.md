[Problem - D - Codeforces](https://codeforces.com/contest/1875/problem/D)

[Submission #226024316 - Codeforces](https://codeforces.com/contest/1875/submission/226024316)

当我们把所有的 $0$ 删除后，贡献会一直为 $0$，于是我们以删掉所有 $0$ 为目标。

我们记录每个数出现的次数，由于初始 $\mathbf{MEX} < n$，故可以将输入里很大的数舍弃，然后记录其它数出现的次数 $cnt_x$。

考虑如果当前 $\mathbf{MEX} = k$，则我们一定会选择一个数 $x(x < k)$ 删除，直到 $x$ 删完，把 $x$ 删完的贡献为 $k\times cnt_x$，这样一来我们有了一个状态转移的方向，可以考虑 dp。

我们把这个过程倒着考虑，我们可以设置状态 $f_n$ 表示 $\mathbf{MEX} = n$ 时删到 $\mathbf{MEX} = 0$ 的最小贡献，这样一来有转移方程

$$
f_i = \min_{j < i} \{f_j + cnt_j\times i\}
$$

记初始 $\mathbf{MEX} = n$，最后输出 $f_n - n$ 即可。