[Problem - D - Codeforces](https://codeforces.com/contest/144/problem/D)

[Submission #217245243 - Codeforces](https://codeforces.com/contest/144/submission/217245243)

显然我们把每条边拆成 $w_i$ 条长度为 $1$ 的边复杂度是爆炸了的

那对于我们求出了所有点的单源最短路后，我们可以枚举每条边，直接计算该边上有没有点满足条件

可以根据边的两个端点到 $s$ 的最短路求出该边上符合条件的点的数量