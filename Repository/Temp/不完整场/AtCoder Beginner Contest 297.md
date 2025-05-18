[F - Minimum Bounding Box 2 (atcoder.jp)](https://atcoder.jp/contests/abc297/tasks/abc297_f)

[Submission #40725555 - AtCoder Beginner Contest 297](https://atcoder.jp/contests/abc297/submissions/40725555)

将问题反过来考虑，枚举每种矩形有多少种放置棋子的方案，对于一个 $n \times m$ 的矩形，我们可以用容斥的方法求出正好覆盖它的方案数

即总方案数减去没有达到任意一条边界的方案数，其中有重复计算的贡献，容斥四层即可消除重复贡献，具体详见代码。