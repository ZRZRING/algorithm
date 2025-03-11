[Problem - A - Codeforces](https://codeforces.com/contest/1869/problem/A)

[Submission #222726605 - Codeforces](https://codeforces.com/contest/1869/submission/222726605)

首先用一次操作 $(1, n)$ 将所有元素变为全局异或和。

若 $n$ 为偶数，则再将所有元素变为全局异或和即可。

若 $n$ 为奇数，则将前 $n - 1$ 个元素变为其异或和，之后进行两次 $(n - 1, n)$ 操作即可。

[Problem - B - Codeforces](https://codeforces.com/contest/1869/problem/B)

[Submission #222734207 - Codeforces](https://codeforces.com/contest/1869/submission/222734207)

我们贪心地使用传送门，计算出所有点到 $1$ 号点和 $n$ 号点的路径，答案为 $1$ 号点离最近的传送门的距离加上 $n$ 号点离最近的传送门的距离的和。

[Problem - C - Codeforces](https://codeforces.com/contest/1869/problem/C)

[Submission #222748290 - Codeforces](https://codeforces.com/contest/1869/submission/222748290)

我们钦定最后的 $\mathbf{MEX}$ 数组为 $[0, 1, 2, \cdots, t - 1, t, \cdots]$，那么第一行构造为 $[1, 2, \cdots, m - 1, 0]$，第二行构造为 $[2, 3, \cdots, m - 1, 0, 1]$，可以确保对于前 $i$ 行都满足上述构造，即每次将排列循环左移一位，最后剔除 $[0, 1, 2, \cdots, m - 2, m - 1]$ 即可，答案为 $\min(n + 1, m)$。注意需要特判 $m = 1$。

[Problem - D1 - Codeforces](https://codeforces.com/contest/1869/problem/D1)

[Problem - D2 - Codeforces](https://codeforces.com/contest/1869/problem/D2)

[Submission #222789917 - Codeforces](https://codeforces.com/contest/1869/submission/222789917)

[Submission #222897552 - Codeforces](https://codeforces.com/contest/1869/submission/222897552)

赛后将 D1 代码精简了一下并写了 D2，可以参考 D2 的写法来写 D1。

首先考虑如何让每个人相等，算出所有人的平均数来之后，每个人到达这个平均数都有一个差 $d_i$，填补这个差即可。

D1 考虑每个人一定接受一次，给出一次，对于所有 $d_i$，我们可以计算出其需要给出的数量和接受的数量，这个数量是唯一的，即每个人的操作一定为 $(\pm 2^k, \mp 2^{m})$，判断所有人能否操作，并且判断接受数量的集合和给出数量的集合是否相等即可。

D2 由于 $d_i = \pm 2^k$ 时，我们可以只给不收或只收不给，比 D1 多一种选择，但是我们发现他只有 $(\pm 2^k, \mp 0)$ 和 $(\pm 2^{k + 1}, \mp 2^{k})$ 两种选择，于是我们钦定所有人按照 D1 的方法做，从高到低判断，若达不到平衡，就让若干 $d_i = \pm 2^k$ 的人选择另一个方法，使其达到平衡，最后判断一下 $(+0, -0)$ 是否平衡即可。