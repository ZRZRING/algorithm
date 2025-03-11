[Problem - C - Codeforces](https://codeforces.com/contest/1366/problem/C)

[Submission #220476002 - Codeforces](https://codeforces.com/contest/1366/submission/220476002)

考虑第 $k$ 步一定走到斜线 $x + y = k$ 上，于是我们对于每条斜线，及其在路径中对称的那条斜线，保证其格子上的数相同即可。

[Problem - D - Codeforces](https://codeforces.com/contest/1366/problem/D)

[Submission #220478336 - Codeforces](https://codeforces.com/contest/1366/submission/220478336)

若 $gcd(a, b) = 1$，$ab = c$，则 $gcd(a + b, c) = 1$，于是我们找出每一个 $a_i$ 的一个质因数的最高次幂 $p_i^{k_i}$，输出 $p_i^{k_i}$ 和 $a_i / p_i^{k_i}$ 即可。

[Problem - E - Codeforces](https://codeforces.com/contest/1366/problem/E)

[Submission #220670708 - Codeforces](https://codeforces.com/contest/1366/submission/220670708)

记 $a$ 数组的指针 $x$，$b$ 数组的指针 $y$，从后往前扫，扫到 $a_x = b_y$，则 $b_y$ 对应的 $a$ 的区间必包含 $a_x$，然后 $y$ 往前移动一位，继续执行上述操作，直到能完全匹配且不存在多余数字，则匹配有解，若中途发现 $a_x < b_y$，则无解。

这是因为我们找到的是第一个 $a_x \leq b_y$ 的值，若不这么匹配肯定不能取到 $\min$，然后考虑将每两个相邻的匹配的间隔按插在什么位置即可。