[Problem - A - Codeforces](https://codeforces.com/contest/1842/problem/A)

[Submission #211025533 - Codeforces](https://codeforces.com/contest/1842/submission/211025533)

- 给定A，B两个人拥有的怪兽集合，每个怪兽都有一个力量 $a_i, b_i$，两个力量为 $X, Y$ 的怪兽进行搏斗会使得两个怪兽的力量分别变为 $X - Y, Y - X$，当一个怪兽力量小于等于 $0$ 时不可进行搏斗，当某一方怪兽都不可进行搏斗而另一方存在可以进行搏斗的怪兽则判负，两方都没有可以进行搏斗的怪兽则平局，A，B每轮可以选择一个怪兽进行搏斗，求两人的最优解下获胜的乙方或判断为平局

对A，B的怪兽力量求和进行比较即可

[Problem - B - Codeforces](https://codeforces.com/contest/1842/problem/B)

[Submission #210898986 - Codeforces](https://codeforces.com/contest/1842/submission/210898986)

- 给定三个栈，你有一个能力值 $x$，初始化为 $0$，每次可以从任意栈中取出栈顶的数，将 $x$ 按位或这个数，给定 $k$，问能否使得 $x = k$

对三个栈分别求前缀按位或，并对于每一个栈找到 $k$ 的子集的最后一个位置，记录该前缀，最后把这三个前缀全部按位或起来判断是否等于 $k$

[Problem - C - Codeforces](https://codeforces.com/contest/1842/problem/C)

[Submission #210937880 - Codeforces](https://codeforces.com/contest/1842/submission/210937880)

- 给定一个序列，序列中每个元素都有一个颜色 $c_i$，你可以删除任意端点颜色相同的区间，求一个序列可以删除最多的元素的数量

删除具有括号性质，则我们可以用 $f_{i, 0/1}$ 表示前 $i$ 个元素可以删除的最多的元素数量，$0/1$ 表示第 $i$ 个元素是否作为某一被删除区间的右端点

$$
\begin{aligned}
f_{i, 0} &= \max\{f_{i - 1, 0}, f_{i - 1, 1}\} \\
f_{i, 1} &= \max_{c_i = c_j, j < i}\{f_{j, 0} + i - j + 1\}
\end{aligned}
$$

考虑如何优化第二个式子，注意到 $j$ 到 $i$ 一定是全覆盖的，我们求被删除的元素数量的 $\max$ 可以转化为求没有被删除的元素数量的  $\min$，于是状态改为 $f_{i, 0/1}$ 表示前 $i$ 个元素可以保留的最少的元素数量，$g_i$ 表示颜色 $i$ 的最小不作为删除区间的右端点的答案

$$
\begin{aligned}
g_{c_i} &= \min_{c_j = c_i, j < i}\{f_{j, 0}\} \\
f_{i, 0} &= \min\{f_{i - 1, 0}, f_{i - 1, 1}\} \\
f_{i, 1} &= g_{c_i} - 1
\end{aligned}
$$

于是我们可以线性维护 $g_i$ 的信息

[Problem - D - Codeforces](https://codeforces.com/contest/1842/problem/D)

[Submission #210960093 - Codeforces](https://codeforces.com/contest/1842/submission/210960093)

- 有 $n$ 个物品，每个物品有个状态 $0/1$，在一轮游戏中，给定 $m$ 个关系 $(u, v, t)$，表示 $u$ 和 $v$ 状态不同最多持续 $t$ 单位时间，钦定 $1$ 号物品状态始终为 $1$，$n$ 号物品状态始终为 $0$，在任意时刻你可以任意指定 $2$ 到 $n - 1$ 的状态，求该轮游戏最长可以持续多久，并输出方案，若可以一直持续下去输出 `inf`

将 $(u, v, t)$ 抽象为一条 $u$ 到 $v$ 边权为 $t$ 的边

每次遍历所有边，找到所有端点状态不同的边中边权最小的边，然后进行该边权的时间，更新整张图，若存在一条边被减至 $0$，则删除该边并将端点状态设为 $0$，重复此操作直至 $1$ 号点状态为 $0$，若某一轮判定下去不存在端点状态不同的边，则判定为 `inf`

由于我们每次至少删掉一条边，复杂度 $\mathcal{O}(m^2)$