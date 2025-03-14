# A 生不逢七

签到题，按照题目模拟即可。

官方提交代码

# B 交换数字

由于我们交换任意位置的数字，$a + b$ 的值恒为定值，只会改变 $a - b$ 的值，而我们知道 $4ab = (a + b)^2 - (a - b)^2$，于是我们最大化 $a - b$ 的值即可最小化 $ab$ 的值。

官方提交代码

# C 老虎机

概率和组合数学的基础，我们可以用 $期望=\sum 概率\times 价值$ 计算，概率可以将问题情形分成若干相等概率的情况，用满足条件的情况数，除以总情况数得到概率。

有一个简单的小技巧，我们可以很容易发现图案均不相同的情况以及图案全部相同的情况计数很方便，一对图案的方案数可以用总方案数减去上述情况数计算得来。

官方提交代码

# D 幻兽帕鲁

我们跟踪某个数他是怎么移动到最终的位置的，可以发现每个数都是类似于在线段树上移动，而移动的方向取决于他二进制下从低位到高位的值，我们知道线段树的每次进入左右儿子的移动，相当于对二进制的数从高位到低位进行值的填充，于是我们可以发现，我们这个变换的过程就相当于将每个数的二进制逆序输出。~~当然你也可以写一个暴力然后发现规律~~

官方提交代码

# E 奏绝

每个区间记录该区间内的答案，黑白之章往前和往后的长度和与数量。两个区间合并，跨越区间的贡献可以表示为，将某一区间的黑白之章长度和 $\times$ 另一区间的相反颜色的数量。

通过上述想法，使用线段树即可解决此问题，但是线段树本身较为复杂，于是我们可以继续挖掘上述计算中的性质。

考虑以上维护的信息包括：区间前后缀长度和，区间某种元素的数量，区间的答案。

这些信息均满足可减性，于是可以通过差分 $\mathcal{O}(1)$ 得出，将复杂度优化到 $\mathcal{O}(n)$。

本来是想卡线段树的，后来内测的时候，使用 C++ 以外的语言的同学过不去，于是下调了数据范围，现在的数据线段树是可以通过的。

官方提交代码

# F 本初字符串

记 $n = |S|, m = |T|$，首先 $|S'| = |T'| = k\times lcm(n, m)$，其中 $k$ 为任意正整数

考虑如果我们有了一个 $T$，对于每个 $T_i$，找出该位置在 $S'$ 中的匹配集合，那么 $T_i$ 取自己的匹配集合中出现次数最多的字母能最大化匹配，这样枚举 $T$ 的长度，找到匹配数大于 $\displaystyle\left\lfloor\frac{n}{2}\right\rfloor$ 最短的那个 $T$ 即可，时间复杂度 $\mathcal{O}(n^2)$

$T_i$ 的匹配集合是 $i + k\times \gcd(n, m)$，也就是说 $\gcd(n, m)\not = m$ 的话，一定存在有相同匹配集合的 $i$

重复贡献并不会增加答案，所以如果 $\gcd(n, m_0)\not = m_0$，$m_0$ 的答案和 $m = \displaystyle\frac{m_0}{\gcd(n, m_0)}$ 的答案一样

所以我们只需要枚举 $n$ 的约数即可，复杂度 $\mathcal{O}(nd(n))$，其中 $d(n)$ 表示 $n$ 的约数个数

构造字典序最小的操作，每次对于当前最优的后缀，判断当前枚举到的字母是否满足题目要求即可，复杂度 $\mathcal{O}(nd(n) + 26n)$。

官方提交代码